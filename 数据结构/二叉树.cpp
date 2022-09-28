/*
树的概念:
树是一种非线性的数据结构，它是由n(n>=0)个有限结点组成一个具有层次关系的集合。
把它称为树，是因为它看起来像一棵倒挂的树，根朝上，叶朝下。
*/

/*
特点:
1.有一个特殊的结点，称为根结点，根结点没有前驱结点。
2.除根结点外，其余结点被分成M(M>0)个互不相交的集合T1、T2……Tm，其中每一个集合Ti(1<=i<=m)又是一棵结构与树类似的的子树。
每棵子树的根结点有且只有一个前驱，可以有0个或多个后继
3.树是递归定义的
*/

/*
术语:
结点的度:结点挂接的子树数(有几个直接后继就为几度)

结点的层次:从根到该结点的层数(根结点算第一层)

叶子、叶节点、终端结点:度为0的结点(即无后继的结点)

非终端结点、分支结点:度不为0的结点

双亲结点、父结点:若一个结点含有子节点，则这个结点是其子结点的父结点(子节点的直接前驱)

孩子结点、子结点:一个结点含有的子树的根结点称为该结点的子结点(即该结点的直接后继)

兄弟结点:同一双亲下的同层结点(即具有相同父结点的结点互称为兄弟结点)

堂兄弟结点:即双亲位于同一层的结点(非同一双亲)

先祖:从根到该结点所经分支上的所有结点(父也是祖先)

子孙:以该结点为根的子树中的任一结点都为该结点的子孙

树的度:一棵树中，所有 结点的度 中的最大值

树的深度(高度):指所有结点中的最大层数

有序树:结点各子树从左到右有序，不可互换(左为第一)

无序树:结点各子树可互换位置

森林:由m(m>0)棵互不相交的树组成的集合被称为森林
*/


/*
树的表示:
1.左孩子右兄弟表示法:
父结点左边的孩子称为左孩子结点，左孩子的右边的兄弟为右孩子(将一棵多叉树转化为二叉树)
2.双亲表示法:
利用数组存储双亲的下标
*/



















/*
二叉树:
n(n>=0)个结点的有限集合，由一个根结点以及两棵互不相交，分别称为左子树和右子树的二叉树组成

性质:
1.每个结点最多有两棵子树，即二叉树不存在度大于2的结点
2.二叉树的子树有左右之分，其子树的次序不能颠倒(有序树)
3.在二叉树的第i层上至多有2^(i-1)个结点(i>0)
4.深度为k的二叉树至多有2^k - 1个结点(k>0)
5.对于任何一棵二叉树，若度为2的结点树有m个，则叶子数n必为m+1(即n = m+1)
6.具有N个结点的满二叉树的深度为logN

特殊二叉树:
1.满二叉树:
一棵深度为k且有2^k - 1个结点的二叉树(即每层的结点数都达到最大值)
2.完全二叉树:
除最后一层外，每层上的结点数都达到最大值，在最后一层上只缺少右边的若干结点
(对于深度为k的且有n个结点的二叉树，当且仅当其每一个结点与深度为k的满二叉树中编号从1到n的结点一一对应时，该二叉树被称为完全二叉树)
满二叉树是一种特殊的完全二叉树
*/


/*
二叉树的存储方式:
1.顺序存储:
利用数组存储，一般数组只适合表示完全二叉树(不是完全二叉树会有空间上的浪费)
二叉树顺序存储在物理上是一个数组，在逻辑上是一个二叉树
2.链式存储:
二叉树的链式存储结构是指用链表来表示一棵二叉树，即用链来指示元素之间的逻辑关系。
通常的方法:链表的每个结点由三个域组成，数据域和左右指针域。
链式结构又分为二叉链(left和right)和三叉链(left、right和parent)
*/

/*
二叉树的遍历方式:
1.深度优先遍历:
先序(根)遍历:根 左子树 右子树 NLR
中序(根)遍历:左子树 根 右子树 LNR
后序(根)遍历:左子树 右子树 根 LRN
2.层序遍历(广度优先遍历):
设二叉树的根结点所在层数为1，层序遍历就是从所在二叉树的根结点出发，
首先访问第一层的树根结点，然后从左到右访问第二层上的结点，以此类推，从上到下，从左到右，逐层访问树的结点。
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
void PrevOrder(struct BinaryTreeNode* root)//前序
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
void InOrder(struct BinaryTreeNode* root)//中序
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
void PostOrder(struct BinaryTreeNode* root)//后序
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
void DestoryTree(struct BinaryTreeNode* root)//后序销毁
{
	if (root == NULL)
		return;
	DestoryTree(root->left);
	DestoryTree(root->right);
	free(root);
}
int main()
{
	//准备结点
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

	//构建树结构
	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	//前中后序遍历
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
void GetBinaryTreeNodeSize_1(struct BinaryTreeNode* root, int* count)//获取结点数
{
	if (root == NULL)return;
	++(*count);
	GetBinaryTreeNodeSize_1(root->left, count);
	GetBinaryTreeNodeSize_1(root->right, count);
}
int GetBinaryTreeNodeSize_2(struct BinaryTreeNode* root)//获取结点数
{
	return root == NULL ? 0 : GetBinaryTreeNodeSize_2(root->left) + GetBinaryTreeNodeSize_2(root->right) + 1;
}
int GetLeaf(struct BinaryTreeNode* root)//获取叶子数
{
	if (root == NULL)return 0;
	return ((root->left == NULL) && (root->right == NULL)) ? 1 : GetLeaf(root->left) + GetLeaf(root->right);
}
int main()
{
	//准备结点
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

	//构建树结构
	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	int count = 0;
	GetBinaryTreeNodeSize_1(A, &count);
	printf("共有%d个结点\n", count);//5
	printf("共有%d个结点\n", GetBinaryTreeNodeSize_2(A));//5

	printf("叶子数为:%d\n", GetLeaf(A));//3
	return 0;
}
*/




//层序遍历(非递归)——队列实现
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
void QueuePush(Queue* pq, QDataType d)//队尾入 
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
void QueuePop(Queue* pq)//队头出 
{
	assert(pq);
	assert(pq->head);//队列不为空
	if (pq->head->next == NULL)//只有一个结点的情况 
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
//1、首先将二叉树的根节点push到队列中，判断队列不为NULL，就输出队头的元素，
//2、遍历过的节点出队列
//3、判断节点如果有孩子，就将孩子push到队列中
//4、循环以上操作，直到Tree == NULL。
void LevelOrder(struct BinaryTreeNode* root)//层序遍历
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
	//准备结点
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

	//构建树结构
	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	LevelOrder(A);
	return 0;
}
*/




