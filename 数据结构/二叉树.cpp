/*
���ĸ���:
����һ�ַ����Ե����ݽṹ��������n(n>=0)�����޽�����һ�����в�ι�ϵ�ļ��ϡ�
������Ϊ��������Ϊ����������һ�õ��ҵ����������ϣ�Ҷ���¡�
*/

/*
�ص�:
1.��һ������Ľ�㣬��Ϊ����㣬�����û��ǰ����㡣
2.��������⣬�����㱻�ֳ�M(M>0)�������ཻ�ļ���T1��T2����Tm������ÿһ������Ti(1<=i<=m)����һ�ýṹ�������Ƶĵ�������
ÿ�������ĸ��������ֻ��һ��ǰ����������0���������
3.���ǵݹ鶨���
*/

/*
����:
���Ķ�:���ҽӵ�������(�м���ֱ�Ӻ�̾�Ϊ����)

���Ĳ��:�Ӹ����ý��Ĳ���(��������һ��)

Ҷ�ӡ�Ҷ�ڵ㡢�ն˽��:��Ϊ0�Ľ��(���޺�̵Ľ��)

���ն˽�㡢��֧���:�Ȳ�Ϊ0�Ľ��

˫�׽�㡢�����:��һ����㺬���ӽڵ㣬�������������ӽ��ĸ����(�ӽڵ��ֱ��ǰ��)

���ӽ�㡢�ӽ��:һ����㺬�е������ĸ�����Ϊ�ý����ӽ��(���ý���ֱ�Ӻ��)

�ֵܽ��:ͬһ˫���µ�ͬ����(��������ͬ�����Ľ�㻥��Ϊ�ֵܽ��)

���ֵܽ��:��˫��λ��ͬһ��Ľ��(��ͬһ˫��)

����:�Ӹ����ý��������֧�ϵ����н��(��Ҳ������)

����:�Ըý��Ϊ���������е���һ��㶼Ϊ�ý�������

���Ķ�:һ�����У����� ���Ķ� �е����ֵ

�������(�߶�):ָ���н���е�������

������:�����������������򣬲��ɻ���(��Ϊ��һ)

������:���������ɻ���λ��

ɭ��:��m(m>0)�û����ཻ������ɵļ��ϱ���Ϊɭ��
*/


/*
���ı�ʾ:
1.�������ֵܱ�ʾ��:
�������ߵĺ��ӳ�Ϊ���ӽ�㣬���ӵ��ұߵ��ֵ�Ϊ�Һ���(��һ�ö����ת��Ϊ������)
2.˫�ױ�ʾ��:
��������洢˫�׵��±�
*/

































/*
������:
n(n>=0)���������޼��ϣ���һ��������Լ����û����ཻ���ֱ��Ϊ���������������Ķ��������

����:
1.ÿ���������������������������������ڶȴ���2�Ľ��
2.������������������֮�֣��������Ĵ����ܵߵ�(������)
3.�ڶ������ĵ�i����������2^(i-1)�����(i>0)
4.���Ϊk�Ķ�����������2^k - 1�����(k>0)
5.�����κ�һ�ö�����������Ϊ2�Ľ������m������Ҷ����n��Ϊm+1(��n = m+1)
6.����N�������������������ΪlogN

���������:
1.��������:
һ�����Ϊk����2^k - 1�����Ķ�����(��ÿ��Ľ�������ﵽ���ֵ)
2.��ȫ������:
�����һ���⣬ÿ���ϵĽ�������ﵽ���ֵ�������һ����ֻȱ���ұߵ����ɽ��
(�������Ϊk������n�����Ķ����������ҽ�����ÿһ����������Ϊk�����������б�Ŵ�1��n�Ľ��һһ��Ӧʱ���ö���������Ϊ��ȫ������)
����������һ���������ȫ������
*/


/*
�������Ĵ洢��ʽ:
1.˳��洢:
��������洢��һ������ֻ�ʺϱ�ʾ��ȫ������(������ȫ���������пռ��ϵ��˷�)
������˳��洢����������һ�����飬���߼�����һ��������
2.��ʽ�洢:
����������ʽ�洢�ṹ��ָ����������ʾһ�ö���������������ָʾԪ��֮����߼���ϵ��
ͨ���ķ���:�����ÿ���������������ɣ������������ָ����
��ʽ�ṹ�ַ�Ϊ������(left��right)��������(left��right��parent)
*/

/*
�������ı�����ʽ:
1.������ȱ���:
����(��)����:�� ������ ������ NLR
����(��)����:������ �� ������ LNR
����(��)����:������ ������ �� LRN
2.�������(������ȱ���):
��������ĸ�������ڲ���Ϊ1������������Ǵ����ڶ������ĸ���������
���ȷ��ʵ�һ���������㣬Ȼ������ҷ��ʵڶ����ϵĽ�㣬�Դ����ƣ����ϵ��£������ң����������Ľ�㡣
*/



/*
#include<stdio.h>
#include<stdlib.h>
typedef char BTDataType;
struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
};
void PrevOrder(struct BinaryTreeNode* root)//ǰ��
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(struct BinaryTreeNode* root)//����
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}  
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
void PostOrder(struct BinaryTreeNode* root)//����
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}
void DestoryTree(struct BinaryTreeNode* root)//��������
{
	if (root == NULL)
		return;
	DestoryTree(root->left);
	DestoryTree(root->right);
	free(root);
}
int main()
{
	//׼�����
	struct BinaryTreeNode* A = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;
	struct BinaryTreeNode* B = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;
	struct BinaryTreeNode* C = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;
	struct BinaryTreeNode* D = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;
	struct BinaryTreeNode* E = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	//�������ṹ
	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	//ǰ�к������
	PrevOrder(A);
	printf("\n");
	InOrder(A); 
	printf("\n");
	PostOrder(A);
	printf("\n");

	DestoryTree(A);
	return 0;
}
*/
//A B D NULL NULL E NULL NULL C NULL NULL
//NULL D NULL B NULL E NULL A NULL C NULL
//NULL NULL D NULL NULL E B NULL NULL C A









/*
#include<stdio.h>
#include<stdlib.h>
typedef char BTDataType;
struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
};
void GetBinaryTreeNodeSize_1(struct BinaryTreeNode* root, int* count)//��ȡ�����
{
	if (root == NULL)return;
	++(*count);
	GetBinaryTreeNodeSize_1(root->left, count);
	GetBinaryTreeNodeSize_1(root->right, count);
}
int GetBinaryTreeNodeSize_2(struct BinaryTreeNode* root)//��ȡ�����
{
	return root == NULL ? 0 : GetBinaryTreeNodeSize_2(root->left) + GetBinaryTreeNodeSize_2(root->right) + 1;
}
int GetLeaf(struct BinaryTreeNode* root)//��ȡҶ����
{
	if (root == NULL)return 0;
	return ((root->left == NULL) && (root->right == NULL)) ? 1 : GetLeaf(root->left) + GetLeaf(root->right);
}
int main()
{
	//׼�����
	struct BinaryTreeNode* A = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;
	struct BinaryTreeNode* B = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;
	struct BinaryTreeNode* C = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;
	struct BinaryTreeNode* D = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;
	struct BinaryTreeNode* E = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	//�������ṹ
	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	int count = 0;
	GetBinaryTreeNodeSize_1(A, &count);
	printf("����%d�����\n", count);//5
	printf("����%d�����\n", GetBinaryTreeNodeSize_2(A));//5

	printf("Ҷ����Ϊ:%d\n", GetLeaf(A));//3
	return 0;
}
*/




//�������(�ǵݹ�)��������ʵ��
/*
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef char BTDataType;
struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
};
///*************************************************************
typedef struct BinaryTreeNode* QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType d)//��β�� 
{
	assert(pq);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newNode->next = NULL;
	newNode->data = d;

	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newNode;
	}
	else
	{
		pq->tail->next = newNode;
		pq->tail = newNode;
	}
}
void QueuePop(Queue* pq)//��ͷ�� 
{
	assert(pq);
	assert(pq->head);//���в�Ϊ��
	if (pq->head->next == NULL)//ֻ��һ��������� 
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->head;
	while (cur != NULL)
	{
		++size;
		cur = cur->next;
	}
	return size;
}
bool QueueIsEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
//********************************************************
//1�����Ƚ��������ĸ��ڵ�push�������У��ж϶��в�ΪNULL���������ͷ��Ԫ�أ�
//2���������Ľڵ������
//3���жϽڵ�����к��ӣ��ͽ�����push��������
//4��ѭ�����ϲ�����ֱ��Tree == NULL��
void LevelOrder(struct BinaryTreeNode* root)//�������
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (!QueueIsEmpty(&q))
	{
		struct BinaryTreeNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if (front->left != NULL)
			QueuePush(&q, front->left);
		if (front->right != NULL)
			QueuePush(&q, front->right);
	}
	QueueDestory(&q);
}
int main()
{
	//׼�����
	struct BinaryTreeNode* A = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;
	struct BinaryTreeNode* B = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;
	struct BinaryTreeNode* C = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;
	struct BinaryTreeNode* D = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;
	struct BinaryTreeNode* E = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	//�������ṹ
	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	LevelOrder(A);
	return 0;
}
*/

































//����������(��������������������� BST)
/*
��������һ�ÿ����������Ǿ����������ʵĶ�����:
��������������Ϊ�գ��������������нڵ��ֵ��С�ڸ��ڵ��ֵ
��������������Ϊ�գ��������������нڵ��ֵ�����ڸ��ڵ��ֵ
������������Ҳ�ֱ�Ϊ����������
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

#define RECURSION
#include<iostream>
#include<algorithm>
using std::cout;
using std::endl;
using std::swap;
template<class K>
struct BinarySearchTreeNode
{
	BinarySearchTreeNode(const K& key = K()): _left(nullptr), _right(nullptr), _key(key) {}
	BinarySearchTreeNode<K>* _left;
	BinarySearchTreeNode<K>* _right;
	K _key;
};
template<class K>
class BinarySearchTree
{
	typedef BinarySearchTreeNode<K> BSTNode;
public:
	BinarySearchTree(const BinarySearchTree<K>& obj) {

	}
	~BinarySearchTree() {
		_destory(_root);
	}

	bool insert(const K& key) {
#ifdef RECURSION
		return _insert(_root, key);
#else
		if (_root == nullptr) {
			_root = new BSTNode(key);
			return true;
		}
		BSTNode* cur = _root, * parent = nullptr;
		while (cur != nullptr) {
			if (cur->_key > key) {
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key) {
				parent = cur;
				cur = cur->_right;
	}
			else {//cur->_key == key
				return false;//�������ֵ���࣬����ʧ��
			}
}
		cur = new BSTNode(key);
		if (parent->_key > key) parent->_left = cur;
		else parent->_right = cur;
		return true;
#endif
	}

	bool erase(const K& key) {
#ifdef RECURSION
		return _erase(_root, key);
#else
		BSTNode* cur = _root, * parent = nullptr;
		while (cur != nullptr) {
			if (cur->_key > key) {
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key) {
				parent = cur;
				cur = cur->_right;
			}
			else {//cur->_key == key,��ʼɾ��
				if (cur->_left == nullptr) {
					if (cur == _root) {
						_root = cur->_right;
					}
					else {
						if (cur == parent->_left) {
							parent->_left = cur->_right;
						}
						if (cur == parent->_right) {
							parent->_right = cur->_right;
						}
					}
					delete cur;
					cur = nullptr;
				}
				else if (cur->_right == nullptr) {
					if (cur == _root) {
						_root = cur->_left;
					}
					else {
						if (cur == parent->_left) {
							parent->_left = cur->_left;
						}
						if (cur == parent->_right) {
							parent->_right = cur->_left;
						}
					}
					delete cur;
					cur = nullptr;
				}
				else {//���Ҷ���Ϊnullptr,ʹ���滻��
					BSTNode* replace = cur->_right, * min_parent = cur;
					while (replace->_left != nullptr) {
						min_parent = replace;
						replace = replace->_left;
					}
					swap(replace->_key, cur->_key);
					if (min_parent->_left == replace) {
						min_parent->_left = replace->_right;
					}
					else {
						min_parent->_right = replace->_right;
					}
					delete replace;
				}
				return true;
			}
		}
		return false;
#endif 
	}

	bool find(const K& key) {
#ifdef RECURSION
		return _find(_root, key);
#else
		BSTNode* cur = _root;
		while (cur != nullptr) {
			if (cur->_key > key) {
				cur = cur->_left;
			}
			else if (cur->_key < key) {
				cur = cur->_right;
			}
			else {//cur->_key == key
				return true;
			}
		}
		return false;
#endif
	}

	void inorder() {
		_inorder(_root);
	}

private:
	bool _insert(BSTNode* &root, const K& key) {//rootΪ��һ����ָ��(��ָ��)�ı�����ֱ�Ӹ�ֵ����
		if (root == nullptr) {
			root = new BSTNode(key);
			return true;
		}
		else if (root->_key > key) return _insert(root->_left, key);
		else if (root->_key < key) return _insert(root->_right, key);
		else return false;
	}

	bool _erase(BSTNode* &root, const K& key) {
		if (root == nullptr) return false;
		else if (root->_key > key) return _erase(root->_left, key);
		else if (root->_key < key) return _erase(root->_right, key);
		else {
			BSTNode* del = root;
			if (root->_left == nullptr) {
				root = root->_right;
			}
			else if (root->_right == nullptr) {
				root = root->_left;
			}
			else {//���Ҷ���Ϊ��
				BSTNode* replace = root->_right;
				while (replace->_left != nullptr) {
					replace = replace->_left;
				}
				swap(replace->_key, root->_key);
				return _erase(root->_right, key);//����д��erase(key),��Ϊ���²��Ҳ���(���ض������Ĵ洢�����ѱ��ƻ�)
			}
			delete del;
			return true;
		}

	}

	bool _find(BSTNode* root, const K& key) {
		if (root == nullptr) return false;
		else if (root->_key > key) return _find(root->_left, key);
		else if(root->_key < key) return _find(root->_right, key);
		else return true;//root->_key == key
	}

	void _inorder(BSTNode* root) {
		if (root == nullptr) {
			return;
		}
		_inorder(root->_left);
		cout << root->_key << " ";
		_inorder(root->_right);
	}

	void _destory(BSTNode* &root) {
		if (root == nullptr) {
			return;
		}
		destory(root->_left);
		destory(root->_right);
		delete root;
		root = nullptr;
	}
private:
	BSTNode* _root = nullptr;
};

int main()
{
	BinarySearchTree<int> bst;
	int arr[] = { 8,3,1,10,6,7,2,4,5,9,4,3,4 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		bst.insert(arr[i]);
	}
	cout << bst.find(4) << endl;
	bst.inorder();
	cout << endl;
	for (int i = 0; i < 10; ++i) {
		bst.erase(i + 1);
		bst.inorder();
		cout << endl;
	}

	return 0;
}
