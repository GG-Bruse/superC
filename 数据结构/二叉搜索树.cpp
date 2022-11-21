//搜索二叉树(二叉排序树、二叉查找树 BST)
/*
它或者是一棵空树，或者是具有以下性质的二叉树:
若它的左子树不为空，则左子树上所有节点的值都小于根节点的值
若它的右子树不为空，则右子树上所有节点的值都大于根节点的值
它的左右子树也分别为二叉搜索树
不允许键值冗余
*/


//二叉搜索树操作
/*
1. 二叉搜索树的查找
a、从根开始比较，查找，比根大则往右边走查找，比根小则往左边走查找。
b、最多查找高度次，走到到空，还没找到，这个值不存在

2. 二叉搜索树的插入
a. 树为空，则直接新增节点，赋值给root指针
b. 树不空，按二叉搜索树性质查找插入位置，插入新节点

3. 二叉搜索树的删除

*/


//#define RECURSION
//#include<iostream>
//#include<algorithm>
//using std::swap;
//using std::cout;
//using std::endl;
//namespace KEY
//{
//	template<class K>
//	struct BinarySearchTreeNode
//	{
//		BinarySearchTreeNode(const K& key = K()) : _left(nullptr), _right(nullptr), _key(key) {}
//		BinarySearchTreeNode<K>* _left;
//		BinarySearchTreeNode<K>* _right;
//		K _key;
//	};
//	template<class K>
//	class BinarySearchTree
//	{
//		typedef BinarySearchTreeNode<K> BSTNode;
//	public:
//		BinarySearchTree() = default;//C++11: 强制编译器生成默认构造
//		BinarySearchTree(const BinarySearchTree<K>& obj) {
//			_root = _copy(obj._root);
//		}
//		~BinarySearchTree() {
//			_destory(_root);
//		}
//		BinarySearchTree<K>& operator=(BinarySearchTree<K> obj) {
//			swap(_root, obj._root);
//			return *this;
//		}
//
//		bool insert(const K& key) {
//#ifdef RECURSION
//			return _insert(_root, key);
//#else
//			if (_root == nullptr) {
//				_root = new BSTNode(key);
//				return true;
//			}
//			BSTNode* cur = _root, * parent = nullptr;
//			while (cur != nullptr) {
//				if (cur->_key > key) {
//					parent = cur;
//					cur = cur->_left;
//				}
//				else if (cur->_key < key) {
//					parent = cur;
//					cur = cur->_right;
//				}
//				else {//cur->_key == key
//					return false;//不允许键值冗余，插入失败
//				}
//			}
//			cur = new BSTNode(key);
//			if (parent->_key > key) parent->_left = cur;
//			else parent->_right = cur;
//			return true;
//#endif
//		}
//
//		bool erase(const K& key) {
//#ifdef RECURSION
//			return _erase(_root, key);
//#else
//			BSTNode* cur = _root, * parent = nullptr;
//			while (cur != nullptr) {
//				if (cur->_key > key) {
//					parent = cur;
//					cur = cur->_left;
//				}
//				else if (cur->_key < key) {
//					parent = cur;
//					cur = cur->_right;
//				}
//				else {//cur->_key == key,开始删除
//					if (cur->_left == nullptr) {
//						if (cur == _root) {
//							_root = cur->_right;
//						}
//						else {
//							if (cur == parent->_left) {
//								parent->_left = cur->_right;
//							}
//							if (cur == parent->_right) {
//								parent->_right = cur->_right;
//							}
//						}
//						delete cur;
//						cur = nullptr;
//					}
//					else if (cur->_right == nullptr) {
//						if (cur == _root) {
//							_root = cur->_left;
//						}
//						else {
//							if (cur == parent->_left) {
//								parent->_left = cur->_left;
//							}
//							if (cur == parent->_right) {
//								parent->_right = cur->_left;
//							}
//						}
//						delete cur;
//						cur = nullptr;
//					}
//					else {//左右都不为nullptr,使用替换法
//						BSTNode* replace = cur->_right, * min_parent = cur;
//						while (replace->_left != nullptr) {
//							min_parent = replace;
//							replace = replace->_left;
//						}
//						swap(replace->_key, cur->_key);
//						if (min_parent->_left == replace) {
//							min_parent->_left = replace->_right;
//						}
//						else {
//							min_parent->_right = replace->_right;
//						}
//						delete replace;
//					}
//					return true;
//				}
//			}
//			return false;
//#endif 
//		}
//
//		bool find(const K& key) {
//#ifdef RECURSION
//			return _find(_root, key);
//#else
//			BSTNode* cur = _root;
//			while (cur != nullptr) {
//				if (cur->_key > key) {
//					cur = cur->_left;
//				}
//				else if (cur->_key < key) {
//					cur = cur->_right;
//				}
//				else {//cur->_key == key
//					return true;
//				}
//			}
//			return false;
//#endif
//		}
//
//		void inorder() {
//			_inorder(_root);
//		}
//
//	private:
//		BSTNode* _copy(BSTNode* root) {
//			if (root == nullptr) return nullptr;
//			BSTNode* copy_root = new BSTNode(root->_key);
//			copy_root->_left = _copy(root->_left);
//			copy_root->_right = _copy(root->_right);
//			return copy_root;
//		}
//
//		bool _insert(BSTNode*& root, const K& key) {//root为上一层左指针(右指针)的别名，直接赋值即可
//			if (root == nullptr) {
//				root = new BSTNode(key);
//				return true;
//			}
//			else if (root->_key > key) return _insert(root->_left, key);
//			else if (root->_key < key) return _insert(root->_right, key);
//			else return false;
//		}
//
//		bool _erase(BSTNode*& root, const K& key) {
//			if (root == nullptr) return false;
//			else if (root->_key > key) return _erase(root->_left, key);
//			else if (root->_key < key) return _erase(root->_right, key);
//			else {
//				BSTNode* del = root;
//				if (root->_left == nullptr) {
//					root = root->_right;
//				}
//				else if (root->_right == nullptr) {
//					root = root->_left;
//				}
//				else {//左右都不为空
//					BSTNode* replace = root->_right;
//					while (replace->_left != nullptr) {
//						replace = replace->_left;
//					}
//					swap(replace->_key, root->_key);
//					return _erase(root->_right, key);//不可写成erase(key),因为重新查找不到(搜素二叉树的存储性质已被破坏)
//				}
//				delete del;
//				return true;
//			}
//		}
//
//		bool _find(BSTNode* root, const K& key) {
//			if (root == nullptr) return false;
//			else if (root->_key > key) return _find(root->_left, key);
//			else if (root->_key < key) return _find(root->_right, key);
//			else return true;//root->_key == key
//		}
//
//		void _inorder(BSTNode* root) {
//			if (root == nullptr) {
//				return;
//			}
//			_inorder(root->_left);
//			cout << root->_key << " ";
//			_inorder(root->_right);
//		}
//
//		void _destory(BSTNode*& root) {
//			if (root == nullptr) {
//				return;
//			}
//			_destory(root->_left);
//			_destory(root->_right);
//			delete root;
//			root = nullptr;
//		}
//	private:
//		BSTNode* _root = nullptr;
//	};
//}
//
//namespace KEY_VALUE
//{
//	template<class K,class V>
//	struct BinarySearchTreeNode
//	{
//		BinarySearchTreeNode(const K& key = K(), const V& value = V()) : _left(nullptr), _right(nullptr), _key(key), _value(value) {}
//		BinarySearchTreeNode<K,V>* _left;
//		BinarySearchTreeNode<K,V>* _right;
//		K _key;
//		V _value;
//	};
//	template<class K,class V>
//	class BinarySearchTree
//	{
//		typedef BinarySearchTreeNode<K, V> BSTNode;
//	public:
//		bool insert(const K& key,const V& value) {
//			if (_root == nullptr) {
//				_root = new BSTNode(key,value);
//				return true;
//			}
//			BSTNode* cur = _root, * parent = nullptr;
//			while (cur != nullptr) {
//				if (cur->_key > key) {
//					parent = cur;
//					cur = cur->_left;
//				}
//				else if (cur->_key < key) {
//					parent = cur;
//					cur = cur->_right;
//				}
//				else {//cur->_key == key
//					return false;//不允许键值冗余，插入失败
//				}
//			}
//			cur = new BSTNode(key,value);
//			if (parent->_key > key) parent->_left = cur;
//			else parent->_right = cur;
//			return true;
//		}
//
//		BSTNode* find(const K& key) {
//			BSTNode* cur = _root;
//			while (cur != nullptr) {
//				if (cur->_key > key) {
//					cur = cur->_left;
//				}
//				else if (cur->_key < key) {
//					cur = cur->_right;
//				}
//				else {//cur->_key == key
//					return cur;
//				}
//			}
//			return nullptr;
//		}
//
//		void inorder() {
//			_inorder(_root);
//		}
//		private:
//		void _inorder(BSTNode* root) {
//			if (root == nullptr) {
//				return;
//			}
//			_inorder(root->_left);
//			cout << root->_key << ":" << root->_value << " ";
//			_inorder(root->_right);
//		}
//	private:
//		BSTNode* _root = nullptr;
//	};
//}
//
//
////using namespace KEY;
////void test_K()
////{
////	BinarySearchTree<int> bst;
////	int arr[] = { 8,3,1,10,6,7,2,4,5,9,4,3,4 };
////	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
////		bst.insert(arr[i]);
////	}
////	BinarySearchTree<int> copy1 = bst;
////	BinarySearchTree<int> copy2;
////	copy2 = bst;
////
////	cout << bst.find(4) << endl;
////	bst.inorder();
////	cout << endl;
////	for (int i = 0; i < 10; ++i) 
////	{
////		bst.erase(i + 1);
////		bst.inorder();
////		cout << endl;
////	}
////
////	copy1.inorder();
////	cout << endl;
////	copy2.inorder();
////}
//
//
//#include<iostream>
//#include<string>
//#include<vector>
//using std::string;
//using std::vector;
//using std::cin;
//using namespace KEY_VALUE;
//void test_KV() 
//{
//	BinarySearchTree<string, string> dict;
//	dict.insert("sort","排序");
//	dict.insert("left" , "左边");
//	dict.insert("right","右边");
//	dict.insert("BinarySearchTree", "二叉搜索树");
//	dict.insert("insert", "插入");
//	dict.inorder();
//	cout << endl;
//
//	string search_str;
//	while (cin >> search_str) 
//	{
//		BinarySearchTreeNode<string,string>* temp = dict.find(search_str);
//		if (temp == nullptr) 
//		{
//			cout << "查找失败" << endl;
//		}
//		else
//		{
//			cout << temp->_value << endl;
//		}
//	}
//}
//void test_KV2() {
//	vector<string> v = { "苹果","香蕉","草莓","苹果", "苹果", "苹果","香蕉", "苹果", "苹果", "苹果", "苹果", "苹果" ,"哈密瓜"};
//	BinarySearchTree<string, int> fruit_tree;
//	for (size_t i = 0; i < v.size(); ++i) {
//		BinarySearchTreeNode<string, int>* temp = fruit_tree.find(v[i]);
//		if (temp == nullptr) 
//		{
//			fruit_tree.insert(v[i], 1);
//		}
//		else
//		{
//			++temp->_value;
//		}
//	}
//	fruit_tree.inorder();
//}
//
//int main()
//{
//	//test_K();
//	//test_KV();
//	test_KV2();
//	return 0;
//}



















//二叉搜索树的应用
/*
1. K模型:
K模型即只有key作为关键码，结构中只需要存储Key即可，关键码即为需要搜索到的值
比如: 给一个单词word，判断该单词是否拼写正确，具体方式如下：以词库中所有单词集合中的每个单词作为key，
构建一棵二叉搜索树在二叉搜索树中检索该单词是否存在，存在则拼写正确，不存在则拼写错误。

2. KV模型:
每一个关键码key，都有与之对应的值Value，即<Key, Value>的键值对
比如英汉词典就是英文与中文的对应关系，通过英文可以快速找到与其对应的中文，英文单词与其对应的中文<word, chinese>就构成一种键值对；
再比如统计单词次数，统计成功后，给定单词就可快速找到其出现的次数，单词与其出现次数就是<word, count>就构成一种键值对
*/



//二叉搜索树的性能分析
/*
插入和删除操作都必须先查找，查找效率代表了二叉搜索树中各个操作的性能
对有n个结点的二叉搜索树，若每个元素查找的概率相等，则二叉搜索树平均查找长度是结点在二叉搜索树的深度的函数，即结点越深，则比较次数越多。
但对于同一个关键码集合，如果各关键码插入的次序不同，可能得到不同结构的二叉搜索树

最优情况下，二叉搜索树为完全二叉树(或者接近完全二叉树)，其平均比较次数为: log_2 N
最差情况下，二叉搜索树退化为单支树(或者类似单支)
问题:
若退化成单支树，二叉搜索树的性能就失去了。那能否进行改进，不论按照什么次序插入关键码，二叉搜索树的性能都能达到最优？AVL树和红黑树
*/