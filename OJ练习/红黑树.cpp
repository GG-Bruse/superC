#include <iostream>
#include <string>
#include <utility>
#include <cassert>
using namespace std;

namespace KEY_VALUE
{
	enum Color { RED, BLACK };//����1��ÿ����㲻�Ǻ�ɫ���Ǻ�ɫ
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
				_root->_color = BLACK;//����2�������Ϊ��ɫ
			}
			//���ݶ����������Ĺ�������½��
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
				else return false;//�������ֵ����
			}
			current = new TreeNode(data);
			if (data.first > parent->_data.first) parent->_right = current;
			if (data.first < parent->_data.first) parent->_left = current;
			current->_parent = parent;

			while (parent != nullptr && parent->_color == RED)//�������Ϊ��ɫ���õ���
			{
				TreeNode* grandparent = parent->_parent;
				//�������Ϊ��ɫʱ���游����Ȼ����(���ڵ����Ϊ��ɫ)
				assert(grandparent != nullptr);
				assert(grandparent->_color == BLACK);
				if (parent == grandparent->_left)
				{
					TreeNode* uncle = grandparent->_right;
					//��ɫ����
					/*
					����uncle��㲢��Ϊ��ɫ��ֱ�ӵ�����ɫ����
					����4������ÿ����㣬�Ӹý�㵽�����к��Ҷ�ӽ��ļ�·���ϣ���������ͬ��Ŀ�ĺ�ɫ��㣨��ÿ��·���ϵĺ�ɫ��������ͬ��
					������uncle�����Ϊ��ɫ��ֱ�ӽ�parent��uncle��Ϊ��ɫ���ɣ��൱�����������ĺ�ɫ���������1����Ӱ������
					*/
					if (uncle != nullptr && uncle->_color == RED)
					{
						parent->_color = uncle->_color = BLACK;
						grandparent->_color = RED;
						//�������ϵ�����ɫ
						current = grandparent;
						parent = current->_parent;
					}
					//�ṹ����
					else {//uncle�����ڻ���Ϊ��
						if (current == parent->_left)//����ϸ������������
						{
							rotate_right(grandparent);
							parent->_color = BLACK;
							grandparent->_color = RED;

						}
						else//����ϸ����������Ҳ�
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
					//��ɫ����
					if (uncle != nullptr && uncle->_color == RED)
					{
						parent->_color = uncle->_color = BLACK;
						grandparent->_color = RED;
						//�������ϵ�����ɫ
						current = grandparent;
						parent = current->_parent;
					}
					else//uncle�����ڻ���Ϊ��
					{
						if (current == parent->_right)//����ϸ����������Ҳ�
						{
							rotate_left(grandparent);
							parent->_color = BLACK;
							grandparent->_color = RED;
						}
						else//����ϸ������������
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
			_root->_color = BLACK;//ȷ�� ����2�������Ϊ��ɫ
			return true;
		}

		void inorder() { _inorder(_root); }
		bool IsBalance() {
			//����Ҳ�Ǻ����
			if (_root == nullptr) return true;
			//������Ǻ�ɫ��
			if (_root->_color != BLACK) return false;
			int benchmark = 0;//��׼ֵ
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
				if (benchmark == 0) {//�Ե�һ��·�ϵĺ�ɫ�����Ϊ��׼ֵ
					benchmark = blackNum;
					return true;
				}
				else {
					return blackNum == benchmark;
				}
			}
			if (root->_color == BLACK) ++blackNum;
			if (root->_color == RED && root->_parent->_color == RED) return false;
			//�߼���·����root���Ϊ��ɫ����Ͳ�����Ϊ����㣬һ����parent���
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
			//��������仯����������
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
			//��������仯����������
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