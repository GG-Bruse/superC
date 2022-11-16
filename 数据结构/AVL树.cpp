//AVL树的提出
/*
二叉搜索树虽可以缩短查找的效率，但如果数据有序或接近有序二叉搜索树将退化为单支树，查找元素相当于在顺序表中搜索元素，效率低下

两位俄罗斯的数学家G.M.Adelson-Velskii和E.M.Landis在1962年明了一种解决上述问题的方法:
当向二叉搜索树中插入新结点后，若能保证每个结点的左右子树高度之差的绝对值不超过1(需要对树中的结点进行调整)，即可降低树的高度，从而减少平均搜索长度
*/


/*
一棵AVL树 是空树或者是具有以下性质的二叉搜索树:
1. 它的左右子树都是AVL树
2. 左右子树高度之差(简称平衡因子)的绝对值不超过1(-1/0/1)	右子树高度减去左子树高度
3. 若一棵二叉搜索树是高度平衡的，其就是AVL树。若它有n个结点，其高度可保持在O(log_2 n)，搜索时间复杂度O(log_2 n)
*/



#include <utility>
#include <cstdlib>
#include <cassert>
using std::pair;

template<class K,class V>
struct AVLTreeNode {
	AVLTreeNode(const pair<K,V>& kv) :_parent(nullptr), _left(nullptr), _right(nullptr),_data(kv),_balance_factor(0) {}

	AVLTreeNode<K, V>* _parent;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;

	pair<K, V> _data;
	int _balance_factor;//平衡因子
};

template<class K, class V>
class AVLTree 
{
	typedef AVLTreeNode<K, V> TreeNode;
public:
	bool insert(const pair<K, V>& kv) {
		if (_root == nullptr) {
			_root = new TreeNode(kv);
			return true;
		}

		TreeNode* parent = nullptr;
		TreeNode* cur = _root;
		while (cur != nullptr) {
			if (kv.first > cur->_data.first) {
				parent = cur;
				cur = cur->_right;
			}
			else if (kv.first < cur->_data.first) {
				parent = cur;
				cur = cur->_left;
			}
			else return false;
		}
		cur = new TreeNode(kv);
		if (kv.first > parent->_data.first) {
			parent->_right = cur;
		}
		else { //kv.first < parent->_data.first)
			parent->_left = cur;
		}
		cur->_parent = parent;

		//控制平衡
		//1.更新平衡因子
		while (parent != nullptr){
			if (cur == parent->right) ++parent->_balance_factor;
			else --parent->_balance_factor;

			if(parent->_balance_factor == 0) break;
			else if (abs(parent->_balance_factor) == 1) {
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_balance_factor) == 2) {
				//需要旋转
				if (parent->_balance_factor == 2 && cur->_balance_factor == 1) {
					rotate_left(parent);
				}
				else if (parent->_balance_factor == -2 && cur->_balance_factor = -1) {
					rotate_right(parent);
				}
				else if (parent->_balance_factor == -2 && cur->_balance_factor == 1) {
					rotate_left_right(parent);
				}
				else {

				}

			}
			else {
				assert(false);
			}
		}




		return true;
	}
private:
	void rotate_left(TreeNode* parent) {
		TreeNode* subR = parent->_right;
		TreeNode* subRL = subR->_left;
		TreeNode* pparent = parent->_parent;

		parent->_right = subRL;
		if (subRL != nullptr) subRL->_parent = parent;
		subR->_left = parent;
		parent->_parent = subR;

		//解决根结点变换带来的问题
		if (_root == parent) {
			_root = subR;
			subR->_parent = nullptr;
		}
		else {
			if (pparent->left == parent) pparent->_left = subR;
			else pparent->_right = subR;
			subR->_parent = pparent;
		}
		subR->_balance_factor = parent->_balance_factor = 0;
	}

	void rotate_right(TreeNode* parent) {
		TreeNode* subL = parent->_left;
		TreeNode* subLR = subL->_right;
		TreeNode* pparent = parent->_parent;

		parent->_left = subLR;
		if (subLR != nullptr) subLR->_parent = parent;
		subL->_right = parent;
		parent->_parent = subL;

		if (_root == parent) {
			_root = subL;
			subL->_parent = nullptr;
		}
		else {
			if (pparent->left == parent) pparent->_left = subL;
			else pparent->_right = subL;
			subL->_parent = pparent;
		}
		subL->_balance_factor = parent->_balance_factor = 0;
	}

	void rotate_left_right(TreeNode* parent) {
		TreeNode* subL = parent->_left;
		TreeNode* subLR = subL->_right;
		int bf = subLR->_balance_factor;

		rotate_left(parent->left);
		rotate_right(parent);

		//更新平衡因子
		subLR->_balance_factor = 0;
		if (bf == 1) {
			parent->_balance_factor = 0;
			subL->_balance_factor = -1;
		}
		else if (bf == -1) {
			parent->_balance_factor = 1;
			subL->_balance_factor = 0;
		}
		else if (bf == 0) {
			parent->_balance_factor = 0;
			subL->_balance_factor = 0;
		}
		else assert(false);
	}
private:
	TreeNode _root = nullptr;
};







