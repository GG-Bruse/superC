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

		//为了方便插入后再进行分裂操作，多给一个空间
		K _keys[M];
		BTreeNode<K, M>* _childs[M + 1]; 
		BTreeNode<K, M>* _parent;
		size_t _number; //记录此时实际存储了多少个关键字
	};

	template<class K, size_t M>
	class BTree
	{
		typedef BTreeNode<K, M> Node;
	public:
		//Node*指向找到的结点，int为该元素在该结点中的位置
		pair<Node*, int> Find(const K& key)
		{
			Node* parent = nullptr;
			Node* current = _root;
			int index = 0;
			while (current)//若结点存在
			{
				//在结点的值域中查找
				index = 0;
				while (index < current->_number)
				{
					if (key == current->_keys[index])
						return make_pair(current, index);
					else if (key < current->_keys[index])
						break; //该元素可能在i的左孩子结点中
					else ++index;
				}
				//在current中没有找到，到current结点的第index个孩子中查找
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

			//找插入位置，若该元素已经存在，则不插入
			pair<Node*, int> ret = Find(key);
			if (-1 != ret.second) return false;
			
			Node* current = ret.first;//待插入的叶子结点
			K newKey = key;
			Node* child = nullptr;

			while (true)
			{
				InsertKey(current, newKey, child);
				//若没有满则操作结束
				if (current->_number < M) return true;

				//若满了则进行分裂
				Node* brother = new Node;
				size_t mid = (M >> 1);
				size_t i = mid + 1, j = 0;
				for (; i <= M - 1; ++i)
				{
					brother->_keys[j] = current->_keys[i];
					brother->_childs[j++] = current->_childs[i];
					if (current->_childs[i])
						current->_childs[i]->_parent = brother;
					//拷贝完成后进行重置，便于观察
					current->_keys[i] = K();
					current->_childs[i] = nullptr;
				}
				//孩子比关键字多搬移一个
				brother->_childs[j] = current->_childs[i];
				if (current->_childs[i])
					current->_childs[i]->_parent = brother;
				current->_childs[i] = nullptr;

				brother->_number = j;
				current->_number -= (brother->_number + 1);

				K midKey = current->_keys[mid];
				current->_keys[mid] = K();

				//若分裂的节点为根节点，重新申请一个新的根节点
				//将中间位置数据以及分裂出的新节点插入到新的根节点中，插入结束
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
				//若分裂的节点不是根节点，将中间位置数据以及新分裂出的节点继续向current的双亲中进行插入
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