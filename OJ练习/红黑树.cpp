#include <iostream>
#include <string>
#include <utility>
#include <cassert>
using namespace std;

namespace KEY_VALUE
{
	enum Color { RED, BLACK };//性质1：每个结点不是红色就是黑色
	template<class K, class V>
	struct RedBlackTreeNode 
	{
		RedBlackTreeNode(const pair<K, V>& data) :
			_left(nullptr), _right(nullptr), _parent(nullptr), _data(data), _color(RED) {}
		RedBlackTreeNode<K, V>* _left;
		RedBlackTreeNode<K, V>* _right;
		RedBlackTreeNode<K, V>* _parent;
		pair<K, V> _data;
		Color _color;
	};

	template<class K, class V>
	class RedBlackTree
	{
		typedef RedBlackTreeNode<K, V> TreeNode;
	public:
		bool insert(const pair<K, V>& data)
		{
			if (_root == nullptr) {
				_root = new TreeNode(data);
				_root->_color = BLACK;//性质2：根结点为黑色
			}
			//根据二叉搜索树的规则插入新结点
			TreeNode* parent = nullptr;
			TreeNode* current = _root;
			while (current != nullptr)
			{
				if (data.first > current->_data.first) {
					parent = current;
					current = current->_right;
				}
				else if (data.first < current->_data.first) {
					parent = current;
					current = current->_left;
				}
				else return false;//不允许键值冗余
			}
			current = new TreeNode(data);
			if (data.first > parent->_data.first) parent->_right = current;
			if (data.first < parent->_data.first) parent->_left = current;
			current->_parent = parent;

			while (parent != nullptr && parent->_color == RED)//若父结点为黑色则不用调整
			{
				TreeNode* grandparent = parent->_parent;
				//当父结点为红色时，祖父结点必然存在(根节点必须为黑色)
				assert(grandparent != nullptr);
				assert(grandparent->_color == BLACK);
				if (parent == grandparent->_left)
				{
					TreeNode* uncle = grandparent->_right;
					//颜色调整
					/*
					存在uncle结点并且为红色，直接调整颜色即可
					性质4：对于每个结点，从该结点到其所有后代叶子结点的简单路径上，均包含相同数目的黑色结点（即每条路径上的黑色结点个数相同）
					若存在uncle结点且为红色，直接将parent和uncle置为黑色即可，相当于左右子树的黑色结点数个加1，不影响性质
					*/
					if (uncle != nullptr && uncle->_color == RED)
					{
						parent->_color = uncle->_color = BLACK;
						grandparent->_color = RED;
						//继续向上调整颜色
						current = grandparent;
						parent = current->_parent;
					}
					//结构调整
					else {//uncle不存在或者为黑
						if (current == parent->_left)//插入较高左子树的左侧
						{
							rotate_right(grandparent);
							parent->_color = BLACK;
							grandparent->_color = RED;

						}
						else//插入较高左子树的右侧
						{
							rotate_left(parent);
							rotate_right(grandparent);
							current->_color = BLACK;
							grandparent->_color = RED;
						}
						break;
					}
				}
				else//parent == grandparent->_right
				{
					TreeNode* uncle = grandparent->_left;
					//颜色调整
					if (uncle != nullptr && uncle->_color == RED)
					{
						parent->_color = uncle->_color = BLACK;
						grandparent->_color = RED;
						//继续向上调整颜色
						current = grandparent;
						parent = current->_parent;
					}
					else//uncle不存在或者为黑
					{
						if (current == parent->_right)//插入较高右子树的右侧
						{
							rotate_left(grandparent);
							parent->_color = BLACK;
							grandparent->_color = RED;
						}
						else//插入较高右子树的左侧
						{
							rotate_right(parent);
							rotate_left(grandparent);
							current->_color = BLACK;
							grandparent->_color = RED;
						}
						break;
					}
				}
			}
			_root->_color = BLACK;//确保 性质2：根结点为黑色
			return true;
		}

		void inorder() { _inorder(_root); }
		bool IsBalance() {
			//空树也是红黑树
			if (_root == nullptr) return true;
			//根结点是黑色的
			if (_root->_color != BLACK) return false;
			int benchmark = 0;//基准值
			return _IsBalance(_root, 0, benchmark);
		}
	private:
		void _inorder(TreeNode* root) {
			if (root == nullptr) return;
			_inorder(root->_left);
			cout << root->_data.first << ":" << root->_data.second << " ";
			_inorder(root->_right);
		}
		bool _IsBalance(TreeNode* root, int blackNum, int& benchmark) {
			if (root == nullptr) {
				if (benchmark == 0) {//以第一条路上的黑色结点数为基准值
					benchmark = blackNum;
					return true;
				}
				else {
					return blackNum == benchmark;
				}
			}
			if (root->_color == BLACK) ++blackNum;
			if (root->_color == RED && root->_parent->_color == RED) return false;
			//逻辑短路，若root结点为红色，其就不可能为根结点，一定有parent结点
			return _IsBalance(root->_left, blackNum, benchmark) && _IsBalance(root->_right, blackNum, benchmark);
		}

	private:
		void rotate_left(TreeNode* parent)
		{
			TreeNode* rightSub = parent->_right;
			TreeNode* rightSubLeft = rightSub->_left;
			TreeNode* pparent = parent->_parent;

			parent->_right = rightSubLeft;
			if (rightSubLeft != nullptr) rightSubLeft->_parent = parent;
			rightSub->_left = parent;
			parent->_parent = rightSub;
			//解决根结点变化带来的问题
			if (parent == _root) {
				_root = rightSub;
				rightSub->_parent = nullptr;
			}
			else {
				if (pparent->_left == parent) pparent->_left = rightSub;
				else pparent->_right = rightSub;
				rightSub->_parent = pparent;
			}
		}
		void rotate_right(TreeNode* parent)
		{
			TreeNode* leftSub = parent->_left;
			TreeNode* leftSubRight = leftSub->_right;
			TreeNode* pparent = parent->_parent;

			parent->_left = leftSubRight;
			if (leftSubRight != nullptr) leftSubRight->_parent = parent;
			leftSub->_right = parent;
			parent->_parent = leftSub;
			//解决根结点变化带来的问题
			if (parent == _root) {
				_root = leftSub;
				leftSub->_parent = nullptr;
			}
			else {
				if (pparent->_left == parent) pparent->_left = leftSub;
				else pparent->_right = leftSub;
				leftSub->_parent = pparent;
			}
		}
	private:
		RedBlackTreeNode<K, V>* _root = nullptr;
	};
}

using namespace KEY_VALUE;
void RBTreeTest() 
{
	size_t N = 10;
	srand((unsigned)time(NULL));
	RedBlackTree<int, int> t;
	for (size_t i = 0; i < N; ++i) {
		int x = rand();
		//cout << "insert:" << x << ":" << i << endl;
		t.insert(make_pair(x, i));
	}
	t.inorder();
	cout << t.IsBalance() << endl;

}
void RBTreeTest2()
{
	RedBlackTree<int, int> tree;
	tree.insert(make_pair(32083, 0));
	tree.insert(make_pair(17005, 1));
	tree.insert(make_pair(13759, 2));
	tree.insert(make_pair(2397, 3));
	tree.insert(make_pair(25975, 4));
	tree.insert(make_pair(27966, 5));
}
int main()
{
	RBTreeTest();
	return 0;
}