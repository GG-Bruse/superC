#include <iostream>
#include <string>
#include <utility>
#include <cassert>
using namespace std;

namespace KEY_VALUE
{
	template<class K, class V>
	struct AVLTreeNode
	{
		AVLTreeNode(const pair<K, V>& data)
			:_parent(nullptr), _left(nullptr), _right(nullptr), _data(data),_balance_factor(0) {}
		AVLTreeNode<K, V>* _parent;
		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		pair<K, V> _data;
		int _balance_factor;
	};

	template<class K, class V>
	class AVLTree
	{
		typedef AVLTreeNode<K, V> TreeNode;
	public:
		bool insert(const pair<K, V>& kv)
		{
			if (_root == nullptr) {
				_root = new TreeNode(kv);
				return true;
			}
			TreeNode* parent = nullptr;
			TreeNode* current = _root;
			while (current != nullptr)
			{
				if (kv.first > current->_data.first) {
					parent = current;
					current = current->_right;
				}
				else if (kv.first < current->_data.first) {
					parent = current;
					current = current->_left;
				}
				else return false;
			}
			current = new TreeNode(kv);
			if (parent->_data.first > kv.first) parent->_left = current;
			else parent->_right = current;
			current->_parent = parent;
			//����ƽ��
			while (parent != nullptr)
			{
				//����ƽ�����ӣ������߶� - �����߶�
				if (current == parent->_left) --parent->_balance_factor;
				else ++parent->_balance_factor;
				//���ṹ����
				if (parent->_balance_factor == 0) break;
				else if (abs(parent->_balance_factor) == 1) {
					current = parent;
					parent = parent->_parent;
				}
				else if (abs(parent->_balance_factor) == 2)//��Ҫ��ת�����ṹ
				{
					if (parent->_balance_factor == -2 && current->_balance_factor == -1)
						rotate_right(parent);
					else if (parent->_balance_factor == 2 && current->_balance_factor == 1)
						rotate_left(parent);
					else if (parent->_balance_factor == -2 && current->_balance_factor == 1)
						rotate_left_right(parent);
					else if (parent->_balance_factor == 2 && current->_balance_factor == -1)
						rotate_right_left(parent);
					else assert(false);
					break;
				}
				else assert(false);//�����ϲ������
			}
			return true;
		}

	private:
		void rotate_right(TreeNode* parent)//����ϸ������������
		{
			TreeNode* leftSub = parent->_left;
			TreeNode* leftSubRight = leftSub->_right;
			TreeNode* pparent = parent->_parent;

			parent->_left = leftSubRight;
			if(leftSubRight != nullptr) leftSubRight->_parent = parent;
			leftSub->_right = parent;
			parent->_parent = leftSub;
			
			if (parent == _root) {
				_root = leftSub;
				leftSub->_parent = nullptr;
			}
			else
			{
				if (pparent->_left == parent) pparent->_left = leftSub;
				else pparent->_right = leftSub;
				leftSub->_parent = pparent;
			}
			leftSub->_balance_factor = parent->_balance_factor = 0;
		}

		void rotate_left(TreeNode* parent)//����ϸ����������Ҳ�
		{
			TreeNode* rightSub = parent->_right;
			TreeNode* rightSubLeft = rightSub->_left;
			TreeNode* pparent = parent->_parent;

			parent->_right = rightSubLeft;
			if (rightSubLeft != nullptr) rightSubLeft->_parent = parent;
			rightSub->_left = parent;
			parent->_parent = rightSub;

			if (parent == _root) {
				_root = rightSub;
				rightSub->_parent = nullptr;
			}
			else {
				if (parent == pparent->_left) pparent->_left = rightSub;
				else pparent->_right = rightSub;
				rightSub->_parent = pparent;
			}
			rightSub->_balance_factor = parent->_balance_factor = 0;
		}

		void rotate_left_right(TreeNode* parent)//����Ľϸ����������Ҳ�
		{
			TreeNode* leftSub = parent->_left;
			TreeNode* leftSubRight = leftSub->_right;
			int bf = leftSubRight->_balance_factor;

			rotate_left(leftSub);
			rotate_right(parent);

			leftSubRight->_balance_factor = 0;
			if (bf == -1) {
				leftSub->_balance_factor = 0;
				parent->_balance_factor = 1;
			}
			else if (bf == 1) {
				leftSub->_balance_factor = -1;
				parent->_balance_factor = 0;
			}
			else if (bf == 0) {
				leftSub->_balance_factor = 0;
				parent->_balance_factor = 0;
			}
			else assert(false);
		}

		void rotate_right_left(TreeNode* parent)//����Ľϸ������������
		{
			TreeNode* rightSub = parent->_right;
			TreeNode* rightSubLeft = rightSub->_left;
			int bf = rightSubLeft->_balance_factor;

			rotate_right(rightSub);
			rotate_left(parent);

			rightSubLeft->_balance_factor = 0;
			if (bf == 1) {
				rightSub->_balance_factor = 0;
				parent->_balance_factor = -1;
			}
			else if (bf == -1) {
				rightSub->_balance_factor = 1;
				parent->_balance_factor = 0;
			}
			else if (bf == 0) {
				rightSub->_balance_factor = 0;
				parent->_balance_factor = 0;
			}
			else assert(false);
		}

	public://���Ժ���
		bool IsBalance() { return _IsBalance(_root); }
		void inorder() { _inorder(_root); }
	private:
		int Height(TreeNode* root)
		{
			if (root == nullptr) return 0;
			return max(Height(root->_left), Height(root->_right)) + 1;
		}
		bool _IsBalance(TreeNode* root)
		{
			if (root == nullptr) return true;

			int diff = Height(root->_right) - Height(root->_left);
			if (diff != root->_balance_factor) {
				cout << root->_data.first << "��ƽ�������쳣" << endl;
				return false;
			}
			return abs(diff) < 2 && _IsBalance(root->_left) && _IsBalance(root->_right);
		}
		void _inorder(TreeNode* root)
		{
			if (root == nullptr) return;
			_inorder(root->_left);
			cout << root->_data.first << " " << root->_data.second << endl;
			_inorder(root->_right);
		}
	private:
		TreeNode* _root = nullptr;
	};
}


//using namespace KEY_VALUE;
//int main()
//{
//	AVLTree<int, string> tree;
//	tree.insert(make_pair(1, "��"));
//	tree.insert(make_pair(2, "����"));
//	tree.insert(make_pair(3, "������"));
//	tree.insert(make_pair(4, "��������"));
//
//	if(tree.IsBalance()) tree.inorder();
//
//	tree.insert(make_pair(0, "����"));
//	if (tree.IsBalance()) tree.inorder();
//	return 0;
//}
