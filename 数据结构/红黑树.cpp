/*
红黑树，是一种二叉搜索树。但在每个结点上增加一个存储位表示结点的颜色，可以是Red或Black。 
通过对任何一条从根到叶子的路径上各个结点着色方式的限制，红黑树确保没有一条路径会比其他路径长出两倍，因而是接近平衡的。



注意:
与AVL树的平衡(左右高度差不超过1) 相比，红黑树的平衡(没有一条路径会比其他路径长出两倍)并没有那么严格。
所以两者在插入或删除相同数据时，红黑树需要旋转调整的次数更少，这使得红黑树的性能略高于AVL树。
可是AVL树更加平衡，查找数据所需的次数不是更加少吗？在AVL树与红黑树中进行数据的查找都十分快捷，对于CPU从时间上来说并不会造成什么负担。
总的来说，AVL树更适用于插入删除不频繁，只对查找要求较高的场景; 红黑树相较于AVL树更适应对插入、删除、查找要求都较高的场景



性质:
1. 每个结点不是红色就是黑色
2. 根节点是黑色的
3. 若一个节点是红色的，则它的两个孩子结点是黑色的(即树中没有连续的红色结点)
4. 对于每个结点，从该结点到其所有后代叶结点的简单路径上，均包含相同数目的黑色结点(即每条路径上黑色结点数量相等)
5. 每个叶子结点都是黑色的(此处的叶子结点指的是空结点NIF)

*/



//#include<iostream>
//#include<cassert>
//using std::pair;
//using std::make_pair;
//using std::cout;
//using std::cout;
//using std::endl;
//
//enum Color { RED,BLACK };
//template<class K,class V>
//struct RedBlackTreeNode {
//	RedBlackTreeNode(const pair<K, V>& kv) :_parent(nullptr), _left(nullptr), _right(nullptr), _data(kv),_color(RED){}
//
//	RedBlackTreeNode<K, V>* _parent;
//	RedBlackTreeNode<K, V>* _left;
//	RedBlackTreeNode<K, V>* _right;
//	pair<K, V> _data;
//	Color _color;
//};
//
//template<class K,class V>
//class RedBlackTree 
//{
//	typedef RedBlackTreeNode<K, V> TreeNode;
//public:
//	bool insert(const pair<K, V>& kv) {
//		if (_root == nullptr) {
//			_root = new TreeNode(kv);
//			_root->_color = BLACK;
//			return true;
//		}
//
//		TreeNode* parent = nullptr;
//		TreeNode* cur = _root;
//		while (cur != nullptr) {
//			if (kv.first > cur->_data.first) {
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (kv.first < cur->_data.first) {
//				parent = cur;
//				cur = cur->_left;
//			}
//			else return false;
//		}
//		cur = new TreeNode(kv);
//		cur->_color = RED;
//		if (kv.first > parent->_data.first) {
//			parent->_right = cur;
//		}
//		else { //kv.first < parent->_data.first)
//			parent->_left = cur;
//		}
//		cur->_parent = parent;
//
//		while (parent && parent->_color == RED)
//		{
//			TreeNode* grandfather = parent->_parent;
//			assert(grandfather != nullptr);//当parent结点为红时，grandfather结点必不为空(根结点为黑)
//			assert(grandfather->_color == BLACK);//当parent结点为红时，grandfather结点必为黑色(否则违反性质，出现连续的红色结点)
//
//			if (parent == grandfather->_left) {
//				TreeNode* uncle = grandfather->_right;
//				if (uncle != nullptr && uncle->_color == RED) {
//					parent->_color = uncle->_color = BLACK;
//					grandfather->_color = RED;
//					cur = grandfather;
//					parent = cur->_parent;
//				}
//				else {//uncle不存在或者为黑
//					//右单旋 + 变色
//					if (cur == parent->_left) {
//						rotate_right(grandfather);
//						grandfather->_color = RED;
//						parent->_color = BLACK;
//					}
//					//左右双旋 + 变色
//					else {//cur == parent->_right
//						rotate_left(parent);
//						rotate_right(grandfather);
//						cur->_color = BLACK;
//						grandfather->_color = RED;
//					}
//					break;
//				}
//			}
//			else {//parent == grandfather->_right
//				TreeNode* uncle = grandfather->_left;
//				if (uncle != nullptr && uncle->_color == RED) {
//					parent->_color = uncle->_color = BLACK;
//					grandfather->_color = RED;
//					cur = grandfather;
//					parent = cur->_parent;
//				}
//				else {//uncle不存在或者为黑
//					//左单旋 + 变色
//					if (cur == parent->_right) {
//						rotate_left(grandfather);
//						grandfather->_color = RED;
//						parent->_color = BLACK;
//					}
//					//右左双旋 + 变色
//					else {//cur == parent->_left
//						rotate_right(parent);
//						rotate_left(grandfather);
//						cur->_color = BLACK;
//						grandfather->_color = RED;
//					}
//					break;
//				}
//			}
//		}
//		_root->_color = BLACK;
//		return true;
//	}
//
//	void inorder() {
//		_inorder(_root);
//	}
//
//	bool IsBalance() {
//		//空树也是红黑树
//		if (_root == nullptr) return true;
//
//		//根结点是黑色的
//		if (_root->_color != BLACK) return false;
//
//		int benchmark = 0;//基准值
//		return _IsBalance(_root, 0, benchmark);
//	}
//private:
//	void _inorder(TreeNode* root) {
//		if (root == nullptr) {
//			return;
//		}
//		_inorder(root->_left);
//		cout << root->_data.first << ":" << root->_data.second << " ";
//		_inorder(root->_right);
//	}
//
//	bool _IsBalance(TreeNode* root, int blackNum, int& benchmark) {
//		if (root == nullptr) {
//			if (benchmark == 0) {
//				benchmark = blackNum;
//				return true;
//			}
//			else {
//				return blackNum == benchmark;
//			}
//		}
//		if (root->_color == BLACK) ++blackNum;
//
//		if (root->_color == RED && root->_parent->_color == RED) return false;//逻辑短路，若root结点为红色，其就不可能为根结点，一定有parent结点
//
//		return _IsBalance(root->_left, blackNum, benchmark) && _IsBalance(root->_right, blackNum, benchmark);
//	}
//
//	void rotate_left(TreeNode* parent) {
//		TreeNode* subR = parent->_right;
//		TreeNode* subRL = subR->_left;
//		TreeNode* pparent = parent->_parent;
//
//		parent->_right = subRL;
//		if (subRL != nullptr) subRL->_parent = parent;
//		subR->_left = parent;
//		parent->_parent = subR;
//
//		//解决根结点变换带来的问题
//		if (_root == parent) {
//			_root = subR;
//			subR->_parent = nullptr;
//		}
//		else {
//			if (pparent->_left == parent) pparent->_left = subR;
//			else pparent->_right = subR;
//			subR->_parent = pparent;
//		}
//	}
//	void rotate_right(TreeNode* parent) {
//		TreeNode* subL = parent->_left;
//		TreeNode* subLR = subL->_right;
//		TreeNode* pparent = parent->_parent;
//
//		parent->_left = subLR;
//		if (subLR != nullptr) subLR->_parent = parent;
//		subL->_right = parent;
//		parent->_parent = subL;
//
//		if (_root == parent) {
//			_root = subL;
//			subL->_parent = nullptr;
//		}
//		else {
//			if (pparent->_left == parent) pparent->_left = subL;
//			else pparent->_right = subL;
//			subL->_parent = pparent;
//		}
//	}
//
//private:
//	TreeNode* _root = nullptr;
//};
//
//void RBTreeTest() {
//	size_t N = 10000;
//	srand((unsigned)time(NULL));
//	RedBlackTree<int, int> t;
//	for (size_t i = 0; i < N; ++i) { 
//		int x = rand();
//		//cout << "insert:" << x << ":" << i << endl;
//		t.insert(make_pair(x, i));
//	}
//	t.inorder();
//	cout << t.IsBalance() << endl;
//
//}
//int main() 
//{
//	RBTreeTest();
//	return 0;
//}

