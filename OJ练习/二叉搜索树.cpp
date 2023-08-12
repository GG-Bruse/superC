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
			//�ҵ��������λ��
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
				else {//��ֵ��ͬ
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
				else//�ҵ���
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
					else//���Ҷ�����
					{
						//�滻ɾ�������ҵ�����������С�Ľ�� ���丸���
						BSTNode* rightMin = current->_right;
						BSTNode* rightMinParent = current;
						while (rightMin->_left) {//��С������
							rightMinParent = rightMin;
							rightMin = rightMin->_left;
						}
						//����ɾ������ֵ��ΪrightMin��ֵ
						current->_key = rightMin->_key;
						current->_value = rightMin->_value;
						//��rightMinɾ������������
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
//	bst.insert(1, "��");
//	bst.insert(2, "����");
//	bst.insert(3, "������");
//	bst.insert(4, "��������");
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