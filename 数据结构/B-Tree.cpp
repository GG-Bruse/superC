#include <iostream>
using namespace std;

namespace b_tree
{
	template<class K, size_t M>
	struct BTreeNode
	{
		BTreeNode():_parent(nullptr), _number(0) {
			for (int i = 0; i < M; ++i) {
				_keys[i] = K();
				_childs[i] = nullptr;
			}
			_childs[M] = nullptr;
		}

		//Ϊ�˷��������ٽ��з��Ѳ��������һ���ռ�
		K _keys[M];
		BTreeNode<K, M>* _childs[M + 1]; 
		BTreeNode<K, M>* _parent;
		size_t _number; //��¼��ʱʵ�ʴ洢�˶��ٸ��ؼ���
	};

	template<class K, size_t M>
	class BTree
	{
		typedef BTreeNode<K, M> Node;
	public:
		//Node*ָ���ҵ��Ľ�㣬intΪ��Ԫ���ڸý���е�λ��
		pair<Node*, int> Find(const K& key)
		{
			Node* parent = nullptr;
			Node* current = _root;
			int index = 0;
			while (current)//��������
			{
				//�ڽ���ֵ���в���
				index = 0;
				while (index < current->_number)
				{
					if (key == current->_keys[index])
						return make_pair(current, index);
					else if (key < current->_keys[index])
						break; //��Ԫ�ؿ�����i�����ӽ����
					else ++index;
				}
				//��current��û���ҵ�����current���ĵ�index�������в���
				parent = current;
				current = current->_childs[index];
			}
			return make_pair(parent, -1);
		}

		bool Insert(const K& key)
		{
			if (nullptr == _root)
			{
				_root = new Node;
				_root->_keys[0] = key;
				++_root->_number;
				return true;
			}

			//�Ҳ���λ�ã�����Ԫ���Ѿ����ڣ��򲻲���
			pair<Node*, int> ret = Find(key);
			if (-1 != ret.second) return false;
			
			Node* current = ret.first;//�������Ҷ�ӽ��
			K newKey = key;
			Node* child = nullptr;

			while (true)
			{
				InsertKey(current, newKey, child);
				//��û�������������
				if (current->_number < M) return true;

				//����������з���
				Node* brother = new Node;
				size_t mid = (M >> 1);
				size_t i = mid + 1, j = 0;
				for (; i <= M - 1; ++i)
				{
					brother->_keys[j] = current->_keys[i];
					brother->_childs[j++] = current->_childs[i];
					if (current->_childs[i])
						current->_childs[i]->_parent = brother;
					//������ɺ�������ã����ڹ۲�
					current->_keys[i] = K();
					current->_childs[i] = nullptr;
				}
				//���ӱȹؼ��ֶ����һ��
				brother->_childs[j] = current->_childs[i];
				if (current->_childs[i])
					current->_childs[i]->_parent = brother;
				current->_childs[i] = nullptr;

				brother->_number = j;
				current->_number -= (brother->_number + 1);

				K midKey = current->_keys[mid];
				current->_keys[mid] = K();

				//�����ѵĽڵ�Ϊ���ڵ㣬��������һ���µĸ��ڵ�
				//���м�λ�������Լ����ѳ����½ڵ���뵽�µĸ��ڵ��У��������
				if (current == _root)
				{
					_root = new Node;
					_root->_keys[0] = midKey;
					_root->_childs[0] = current;
					_root->_childs[1] = brother;
					_root->_number = 1;
					current->_parent = _root;
					brother->_parent = _root;
					break;
				}
				//�����ѵĽڵ㲻�Ǹ��ڵ㣬���м�λ�������Լ��·��ѳ��Ľڵ������current��˫���н��в���
				else
				{
					newKey = midKey;
					child = brother;
					current = current->_parent;
				}
			}
			return true;
		}

		void InOrder() { _InOrder(_root); }

	private:
		void InsertKey(Node* current, const K& key, Node* child)
		{
			int end = current->_number - 1;
			while (end >= 0)
			{
				if (key < current->_keys[end])
				{
					current->_keys[end + 1] = current->_keys[end];
					current->_childs[end + 2] = current->_childs[end + 1];
					--end;
				}
				else break;
			}
			current->_keys[end + 1] = key;
			current->_childs[end + 2] = child;
			if (child)
				child->_parent = current;
			++current->_number;
		}

		void _InOrder(Node* root)
		{
			if (nullptr == root) return;
			for (int i = 0; i < root->_number; ++i) {
				_InOrder(root->_childs[i]);
				cout << root->_keys[i] << " ";
			}
			_InOrder(root->_childs[root->_number]);
		}

	private:
		Node* _root = nullptr;
	};
}


using namespace b_tree;
void TestBTree()
{
	int array[] = { 53, 139, 75, 49, 145, 36, 101};
	BTree<int, 3> bTree;
	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
		bTree.Insert(array[i]);
	bTree.InOrder();
}
int main()
{
	TestBTree();
	return 0;
}