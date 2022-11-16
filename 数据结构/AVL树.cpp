//AVL�������
/*
������������������̲��ҵ�Ч�ʣ���������������ӽ�����������������˻�Ϊ��֧��������Ԫ���൱����˳���������Ԫ�أ�Ч�ʵ���

��λ����˹����ѧ��G.M.Adelson-Velskii��E.M.Landis��1962������һ�ֽ����������ķ���:
��������������в����½������ܱ�֤ÿ���������������߶�֮��ľ���ֵ������1(��Ҫ�����еĽ����е���)�����ɽ������ĸ߶ȣ��Ӷ�����ƽ����������
*/


/*
һ��AVL�� �ǿ��������Ǿ����������ʵĶ���������:
1. ����������������AVL��
2. ���������߶�֮��(���ƽ������)�ľ���ֵ������1(-1/0/1)	�������߶ȼ�ȥ�������߶�
3. ��һ�ö����������Ǹ߶�ƽ��ģ������AVL����������n����㣬��߶ȿɱ�����O(log_2 n)������ʱ�临�Ӷ�O(log_2 n)
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
	int _balance_factor;//ƽ������
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

		//����ƽ��
		//1.����ƽ������
		while (parent != nullptr){
			if (cur == parent->right) ++parent->_balance_factor;
			else --parent->_balance_factor;

			if(parent->_balance_factor == 0) break;
			else if (abs(parent->_balance_factor) == 1) {
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_balance_factor) == 2) {
				//��Ҫ��ת
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

		//��������任����������
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

		//����ƽ������
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







