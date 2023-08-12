#include <iostream>
#include <algorithm>
using namespace std;

namespace KEY_VALUE
{
	template<class K, class V>
	struct BinarySearchTreeNode
	{
		BinarySearchTreeNode(const K& key = K(), const V& value = V()) :_left(nullptr), _right(nullptr),_key(key),_value(value) {}
		BinarySearchTreeNode<K,V>* _left;
		BinarySearchTreeNode<K,V>* _right;
		K _key;
		V _value;
	};

	template<class K, class V>
	class BinarySearchTree
	{
		typedef BinarySearchTreeNode<K, V> BSTNode;
	public:
		bool insert(const K& key, const V& value)
		{
			if (_root == nullptr) {
				_root = new BSTNode(key, value);
				return true;
			}
			//找到待插入的位置
			BSTNode* current = _root, * parent = nullptr;
			while (current != nullptr)
			{
				if (current->_key < key) {
					parent = current;
					current = current->_right;
				}
				else if (current->_key > key)
				{
					parent = current;
					current = current->_left;
				}
				else {//键值相同
					return false;
				}
			}
			current = new BSTNode(key, value);
			if (key > parent->_key) parent->_right = current;
			else parent->_left = current;
			return true;
		}

		bool erase(const K& key)
		{
			BSTNode* current = _root, * parent = nullptr;
			while (current != nullptr)
			{
				if (key > current->_key) {
					parent = current;
					current = current->_right;
				}
				else if (key < current->_key) {
					parent = current;
					current = current->_left;
				}
				else//找到了
				{
					if (current->_left == nullptr) 
					{
						if (current == _root) {
							_root = current->_right;
						}
						else
						{
							if (current == parent->_left) {
								parent->_left = current->_right;
							}
							else {//current == parent->_right
								parent->_right = current->_right;
							}
						}
						delete current;
						return true;
					}
					else if (current->_right == nullptr)
					{
						if (current == _root) {
							_root = current->_left;
						}
						else
						{
							if (current == parent->_left) {
								parent->_left = current->_left;
							}
							else {//current == parent->_right
								parent->_right = current->_left;
							}
						}
						delete current;
						return true;
					}
					else//左右都不空
					{
						//替换删除法：找到右子树中最小的结点 及其父结点
						BSTNode* rightMin = current->_right;
						BSTNode* rightMinParent = current;
						while (rightMin->_left) {//找小往左走
							rightMinParent = rightMin;
							rightMin = rightMin->_left;
						}
						//将待删除结点的值改为rightMin的值
						current->_key = rightMin->_key;
						current->_value = rightMin->_value;
						//将rightMin删除，无左子树
						if (rightMin == rightMinParent->_left) {
							rightMinParent->_left = rightMin->_right;
						}
						else {//rightMin == rightMinParent->_right
							rightMinParent->_right = rightMin->_right;
						}
						delete rightMin;
						return true;
					}
				}
			}
			return false;
		}

		BSTNode* find(const K& key)
		{
			BSTNode* current = _root;
			while (current != nullptr)
			{
				if (key > current->_key) current = current->_right;
				else if (key < current->_key) current = current->_left;
				else return current;
			}
			return nullptr;
		}

		void inorder() { _InOrder(_root); }

	private:
		void _InOrder(BSTNode* root)
		{
			if (root == nullptr) return;
			_InOrder(root->_left);
			cout << root->_key << " " << root->_value << endl;
			_InOrder(root->_right);
		}
	private:
		BSTNode* _root = nullptr;
	};
}

//using namespace KEY_VALUE;
//int main()
//{
//	BinarySearchTree<int, string> bst;
//	bst.insert(1, "哈");
//	bst.insert(2, "哈哈");
//	bst.insert(3, "哈哈哈");
//	bst.insert(4, "哈哈哈哈");
//
//	bst.inorder();
//
//	auto it = bst.find(4);
//	cout << it->_key << " " << it->_value << endl;
//
//	if (bst.erase(2)) bst.inorder();
//	if (bst.erase(3)) bst.inorder();
//	if (bst.erase(1)) bst.inorder();
//	if (bst.erase(4)) bst.inorder();
//	return 0;
//}