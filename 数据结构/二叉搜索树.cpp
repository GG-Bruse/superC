//����������(��������������������� BST)
/*
��������һ�ÿ����������Ǿ����������ʵĶ�����:
��������������Ϊ�գ��������������нڵ��ֵ��С�ڸ��ڵ��ֵ
��������������Ϊ�գ��������������нڵ��ֵ�����ڸ��ڵ��ֵ
������������Ҳ�ֱ�Ϊ����������
�������ֵ����
*/


//��������������
/*
1. �����������Ĳ���
a���Ӹ���ʼ�Ƚϣ����ң��ȸ��������ұ��߲��ң��ȸ�С��������߲��ҡ�
b�������Ҹ߶ȴΣ��ߵ����գ���û�ҵ������ֵ������

2. �����������Ĳ���
a. ��Ϊ�գ���ֱ�������ڵ㣬��ֵ��rootָ��
b. �����գ����������������ʲ��Ҳ���λ�ã������½ڵ�

3. ������������ɾ��

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
//		BinarySearchTree() = default;//C++11: ǿ�Ʊ���������Ĭ�Ϲ���
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
//					return false;//�������ֵ���࣬����ʧ��
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
//				else {//cur->_key == key,��ʼɾ��
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
//					else {//���Ҷ���Ϊnullptr,ʹ���滻��
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
//		bool _insert(BSTNode*& root, const K& key) {//rootΪ��һ����ָ��(��ָ��)�ı�����ֱ�Ӹ�ֵ����
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
//				else {//���Ҷ���Ϊ��
//					BSTNode* replace = root->_right;
//					while (replace->_left != nullptr) {
//						replace = replace->_left;
//					}
//					swap(replace->_key, root->_key);
//					return _erase(root->_right, key);//����д��erase(key),��Ϊ���²��Ҳ���(���ض������Ĵ洢�����ѱ��ƻ�)
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
//					return false;//�������ֵ���࣬����ʧ��
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
//	dict.insert("sort","����");
//	dict.insert("left" , "���");
//	dict.insert("right","�ұ�");
//	dict.insert("BinarySearchTree", "����������");
//	dict.insert("insert", "����");
//	dict.inorder();
//	cout << endl;
//
//	string search_str;
//	while (cin >> search_str) 
//	{
//		BinarySearchTreeNode<string,string>* temp = dict.find(search_str);
//		if (temp == nullptr) 
//		{
//			cout << "����ʧ��" << endl;
//		}
//		else
//		{
//			cout << temp->_value << endl;
//		}
//	}
//}
//void test_KV2() {
//	vector<string> v = { "ƻ��","�㽶","��ݮ","ƻ��", "ƻ��", "ƻ��","�㽶", "ƻ��", "ƻ��", "ƻ��", "ƻ��", "ƻ��" ,"���ܹ�"};
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



















//������������Ӧ��
/*
1. Kģ��:
Kģ�ͼ�ֻ��key��Ϊ�ؼ��룬�ṹ��ֻ��Ҫ�洢Key���ɣ��ؼ��뼴Ϊ��Ҫ��������ֵ
����: ��һ������word���жϸõ����Ƿ�ƴд��ȷ�����巽ʽ���£��Դʿ������е��ʼ����е�ÿ��������Ϊkey��
����һ�ö����������ڶ����������м����õ����Ƿ���ڣ�������ƴд��ȷ����������ƴд����

2. KVģ��:
ÿһ���ؼ���key��������֮��Ӧ��ֵValue����<Key, Value>�ļ�ֵ��
����Ӣ���ʵ����Ӣ�������ĵĶ�Ӧ��ϵ��ͨ��Ӣ�Ŀ��Կ����ҵ������Ӧ�����ģ�Ӣ�ĵ��������Ӧ������<word, chinese>�͹���һ�ּ�ֵ�ԣ�
�ٱ���ͳ�Ƶ��ʴ�����ͳ�Ƴɹ��󣬸������ʾͿɿ����ҵ�����ֵĴ���������������ִ�������<word, count>�͹���һ�ּ�ֵ��
*/



//���������������ܷ���
/*
�����ɾ�������������Ȳ��ң�����Ч�ʴ����˶����������и�������������
����n�����Ķ�������������ÿ��Ԫ�ز��ҵĸ�����ȣ������������ƽ�����ҳ����ǽ���ڶ�������������ȵĺ����������Խ���Ƚϴ���Խ�ࡣ
������ͬһ���ؼ��뼯�ϣ�������ؼ������Ĵ���ͬ�����ܵõ���ͬ�ṹ�Ķ���������

��������£�����������Ϊ��ȫ������(���߽ӽ���ȫ������)����ƽ���Ƚϴ���Ϊ: log_2 N
�������£������������˻�Ϊ��֧��(�������Ƶ�֧)
����:
���˻��ɵ�֧�������������������ܾ�ʧȥ�ˡ����ܷ���иĽ������۰���ʲô�������ؼ��룬���������������ܶ��ܴﵽ���ţ�AVL���ͺ����
*/