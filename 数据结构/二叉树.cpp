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
左孩子右兄弟表示法:
父结点左边的孩子称为左孩子结点，左孩子的右边的兄弟为右孩子(将一棵多叉树转化为二叉树)
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
6.具有N个结点的满二叉树的深度为 以2为底(N+1)的对数
7.对于具有n个结点的完全二叉树，如果按照从上至下从左至右的数组顺序对所有节点从0开始编号，则对于序号为i的结点有:
	(1)若i > 0，i位置结点的双亲序号: (i-1)/2		若i = 0，i为根节点编号，无双亲节点
	(2)若2i + 1 < n，i位置结点左孩子序号: 2i + 1	若2i + 1 >= n则无左孩子
	(3)若2i + 2 < n，i位置结点右孩子序号: 2i + 2	若2i + 2 >= n则无右孩子


特殊二叉树:
1.满二叉树:
一棵深度为h且有2^h - 1个结点的二叉树(即每层的结点数都达到最大值)
2.完全二叉树:
除最后一层外，每层上的结点数都达到最大值，在最后一层上只缺少右边的若干结点
(对于深度为k的且有n个结点的二叉树，当且仅当其每一个结点与深度为k的满二叉树中编号从1到n的结点一一对应时，该二叉树被称为完全二叉树)
满二叉树是一种特殊的完全二叉树
*/


/*
二叉树的存储方式:
1.顺序存储:
利用数组存储，一般数组只适合表示完全二叉树(不是完全二叉树会有空间上的浪费)，现实中使用中只有堆才会使用数组来存储
二叉树顺序存储在物理上是一个数组，在逻辑上是一个二叉树
2.链式存储:
二叉树的链式存储结构是指用链表来表示一棵二叉树，即用链来指示元素之间的逻辑关系。
通常的方法:链表的每个结点由三个域组成，数据域和左右指针域。
链式结构又分为二叉链(left和right)和三叉链(left、right和parent)
*/











//堆
/*
堆的逻辑结构是一棵完全二叉树
1.结构性:
		用数组表示的二叉树(层序)
2.有序性:
		任一结点的关键字是其子树所有结点的最大值\最小值
		最大堆(大顶堆、大根堆):最大值	双亲大于等于孩子
		最小堆(小顶堆、小根堆):最小值	双亲小于等于孩子
*/

//小堆
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<stdbool.h>
//typedef int HPDataType;
//typedef struct Heap {
//	HPDataType* _data;
//	int _capacity;
//	int _size;
//}Heap;
//
//void HeapInit(Heap* hp) 
//{
//	assert(hp);
//	hp->_data = NULL;
//	hp->_capacity = hp->_size = 0;
//}
//void HeapDestory(Heap* hp)
//{
//	assert(hp);
//	free(hp->_data);
//	hp->_capacity = hp->_size = 0;
//}
//
//void Swap(HPDataType* x, HPDataType* y)
//{
//	HPDataType temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//void AdjustUp(HPDataType* array,int child)
//{
//	int parent = (child - 1) / 2;
//	while (array[child] < array[parent] && child)
//	//while (array[child] > array[parent] && child)
//	{
//		Swap(&array[child], &array[parent]);
//		child = parent;
//		parent = (child - 1) / 2;
//	}
//}
//void HeapPush(Heap* hp,HPDataType x)
//{
//	assert(hp);
//	if (hp->_size == hp->_capacity) {
//		int newCapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
//		HPDataType* temp = (HPDataType*)realloc(hp->_data, sizeof(HPDataType) * newCapacity);
//		if (temp == NULL) {
//			perror("realloc fail:");
//			exit(-1);
//		}
//		hp->_data = temp;
//	}
//	hp->_data[hp->_size] = x;
//	++hp->_size;
//	AdjustUp(hp->_data, hp->_size - 1);
//}
//
//void AdjustDown(HPDataType* array, int size, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < size){
//		if (child + 1 < size && array[child + 1] > array[child]) ++child;
//		if (array[child] > array[parent]) {
//			Swap(&array[child], &array[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else break;
//	}
//}
//void HeapPop(Heap* hp)//删除堆顶数据
//{
//	assert(hp);
//	Swap(&(hp->_data[0]), &(hp->_data[hp->_size - 1]));
//	--hp->_size;
//	AdjustDown(hp->_data, hp->_size, 0);
//}
//
//HPDataType HeapTop(Heap* hp) 
//{
//	assert(hp);
//	assert(hp->_size > 0);
//	return (hp->_data[0]);
//}
//bool HeapIsEmpty(Heap* hp)
//{
//	assert(hp);
//	return hp->_size == 0;
//}
//int HeapSize(Heap* hp)
//{
//	assert(hp);
//	return hp->_size;
//}
//int main()
//{
//	int array[] = { 27,15,19,18,28,34,65,49,25,37 };
//	Heap hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
//		HeapPush(&hp, array[i]);
//	}
//
//	for (int i = 0; i < hp._size; ++i) {
//		printf("%d ", hp._data[i]);
//	}
//	printf("\n");
//
//	HeapPop(&hp);
//
//	for (int i = 0; i < hp._size; ++i) {
//		printf("%d ", hp._data[i]);
//	}
//	printf("\n");
//
//	while (!HeapIsEmpty(&hp)) {
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	return 0;
//}

//堆排序
//#include<stdio.h>
//typedef int HPDataType;
//void Swap(HPDataType* x, HPDataType* y)
//{
//	HPDataType temp = *x;
//	*x = *y;
//	*y = temp;
//}
//void AdjustUp(HPDataType* array, int child)
//{
//	int parent = (child - 1) / 2;
//	while (array[child] < array[parent] && child)
//	{
//		Swap(&array[child], &array[parent]);
//		child = parent;
//		parent = (child - 1) / 2;
//	}
//}
//void AdjustDown(HPDataType* array, int size, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < size) {
//		if (child + 1 < size && array[child + 1] > array[child]) ++child;
//		if (array[child] > array[parent]) {
//			Swap(&array[child], &array[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else break;
//	}
//}
//void HeapSort(int* array,int size) 
//{
//	//建堆的方式1 O(NlogN)
//	/*for (int i = 1; i < size; ++i) {//插入的思想，每插入一个数向上调整一次
//		AdjustUp(array, i);
//	}*/
//	//建堆的方式2 O(N)		//堆的子树也都是堆
//	for (int i = (size - 1 - 1) / 2; i >= 0; --i) {//叶子不需要调整
//		AdjustDown(array, size, i);
//	}
//	for (int i = size- 1; i > 0; --i)//删除的思想，每次删除的都是堆中最小的数
//	{
//		Swap(&array[0], &array[i]);
//		AdjustDown(array, i, 0);
//	}
//}
//int main()
//{
//	int array[] = { 27,15,19,18,28,34,65,49,25,37 };
//	HeapSort(array, sizeof(array) / sizeof(array[0]));
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
//		printf("%d ", array[i]);
//	}
//	return 0;
//}



//Top-K问题
/*
即求数据结合中前K个最大的元素或者最小的元素，一般情况下数据量都比较大
对于Top-K问题，能想到的最简单直接的方式就是排序，但是：如果数据量非常大，排序就不太可取了(可能数据都不能一下子全部加载到内存中)。
最佳的方式就是用堆来解决
*/
/*
1. 用数据集合中前K个元素来建堆
前k个最大的元素，则建小堆
前k个最小的元素，则建大堆
2. 用剩余的N-K个元素依次与堆顶元素来比较，不满足则替换堆顶元素
N-K个元素依次与堆顶元素比完之后，堆中剩余的K个元素就是所求的前K个最小或者最大的元素
*/
//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
//typedef int HPDataType;
//void Swap(HPDataType* x, HPDataType* y)
//{
//	HPDataType temp = *x;
//	*x = *y;
//	*y = temp;
//}
//void AdjustDown(HPDataType* array, int size, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < size) {
//		if (child + 1 < size && array[child + 1] > array[child]) ++child;
//		if (array[child] > array[parent]) {
//			Swap(&array[child], &array[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else break;
//	}
//}
//void PrintTopK(int* array, int n, int k)
//{
//	int* MinHeap = (int*)malloc(sizeof(int) * k);
//	if (MinHeap == NULL) {
//		perror("malloc fail:");
//		exit(-1);
//	}
//
//	for (int i = 0; i < k; ++i) {
//		MinHeap[i] = array[i];
//	}
//
//	for (int i = (k - 1 - 1) / 2; i >= 0; --i) {
//		AdjustDown(MinHeap, k, i);
//	}
//	for (int i = k; i < n; ++i) {
//		if (array[i] > MinHeap[0]) {
//			Swap(&array[i], &MinHeap[0]);
//			AdjustDown(MinHeap, k, 0);
//		}
//	}
//
//	for (int i = 0; i < k; ++i) {
//		printf("%d ", MinHeap[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int n = 10000;
//	int* array = (int*)malloc(sizeof(int) * n);
//	if (array == NULL) {
//		perror("malloc fail:");
//		exit(-1);
//	}
//
//	srand((unsigned)time(NULL));
//	for (size_t i = 0; i < n; ++i)
//	{
//		array[i] = rand() % 1000000;
//	}
//
//	array[5] = 1000000 + 1;
//	array[1231] = 1000000 + 2;
//	array[531] = 1000000 + 3;
//	array[5121] = 1000000 + 4;
//	array[115] = 1000000 + 5;
//	array[2335] = 1000000 + 6;
//	array[9999] = 1000000 + 7;
//	array[76] = 1000000 + 8;
//	array[423] = 1000000 + 9;
//	array[3144] = 1000000 + 10;
//
//	PrintTopK(array, n, 10);//k == 10
//	return 0;
//}
//

























//链式二叉树
/*
二叉树的遍历方式:
1.深度优先遍历:DFS
先序(根)遍历:根 左子树 右子树 NLR	最符合深度优先
中序(根)遍历:左子树 根 右子树 LNR
后序(根)遍历:左子树 右子树 根 LRN	
2.层序遍历(广度优先遍历):BFS
设二叉树的根结点所在层数为1，层序遍历就是从所在二叉树的根结点出发，
首先访问第一层的树根结点，然后从左到右访问第二层上的结点，以此类推，从上到下，从左到右，逐层访问树的结点。
*/

//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//typedef char BTDataType;
//struct BinaryTreeNode
//{
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//	BTDataType data;
//};
//void PrevOrder(struct BinaryTreeNode* root)//前序
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//	printf("%c ", root->data);
//	PrevOrder(root->left);
//	PrevOrder(root->right);
//}
//void InOrder(struct BinaryTreeNode* root)//中序
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}  
//	InOrder(root->left);
//	printf("%c ", root->data);
//	InOrder(root->right);
//}
//void PostOrder(struct BinaryTreeNode* root)//后序
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//	PostOrder(root->left);
//	PostOrder(root->right);
//	printf("%c ", root->data);
//}
//void DestoryTree(struct BinaryTreeNode* root)//后序销毁
//{
//	if (root == NULL)
//		return;
//	DestoryTree(root->left);
//	DestoryTree(root->right);
//	free(root);
//}
//int main()
//{
//	//准备结点
//	struct BinaryTreeNode* A = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
//	assert(A);
//	A->data = 'A';
//	A->left = NULL;
//	A->right = NULL;
//
//	struct BinaryTreeNode* B = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
//	assert(B);
//	B->data = 'B';
//	B->left = NULL;
//	B->right = NULL;
//
//	struct BinaryTreeNode* C = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
//	assert(C);
//	C->data = 'C';
//	C->left = NULL;
//	C->right = NULL;
//
//	struct BinaryTreeNode* D = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
//	assert(D);
//	D->data = 'D';
//	D->left = NULL;
//	D->right = NULL;
//
//	struct BinaryTreeNode* E = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
//	assert(E);
//	E->data = 'E';
//	E->left = NULL;
//	E->right = NULL;
//
//	//构建树结构
//	A->left = B;
//	A->right = C;
//	B->left = D;
//	B->right = E;
//
//	//前中后序遍历
//	PrevOrder(A);
//	printf("\n");
//	InOrder(A); 
//	printf("\n");
//	PostOrder(A);
//	printf("\n");
//
//	DestoryTree(A);
//	return 0;
//}
//A B D NULL NULL E NULL NULL C NULL NULL
//NULL D NULL B NULL E NULL A NULL C NULL
//NULL NULL D NULL NULL E B NULL NULL C A





//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//typedef char BTDataType;
//typedef struct BinaryTreeNode
//{
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//	BTDataType data;
//}BinaryTreeNode;
//void GetBinaryTreeNodeSize_1(BinaryTreeNode* root, int* count)//获取结点数
//{
//	if (root == NULL)return;
//	++(*count);
//	GetBinaryTreeNodeSize_1(root->left, count);
//	GetBinaryTreeNodeSize_1(root->right, count);
//}
//int GetBinaryTreeNodeSize_2(BinaryTreeNode* root)//获取结点数
//{
//	return root == NULL ? 0 : GetBinaryTreeNodeSize_2(root->left) + GetBinaryTreeNodeSize_2(root->right) + 1;
//}
//int GetLeaf(BinaryTreeNode* root)//获取叶子数
//{
//	if (root == NULL)return 0;
//	return ((root->left == NULL) && (root->right == NULL)) ? 1 : GetLeaf(root->left) + GetLeaf(root->right);
//}
//int GetLevelKSize(BinaryTreeNode* root, int k)//求第k层节点个数
//{
//	assert(k >= 1);
//	if (root == NULL) return 0;
//	if (k == 1) return 1;
//	return GetLevelKSize(root->left, k - 1) + GetLevelKSize(root->right, k - 1);
//}
//int GetDepth(BinaryTreeNode* root)//求树的深度
//{
//	if (root == NULL) return 0;
//	int leftDep = GetDepth(root->left);
//	int rightDep = GetDepth(root->right);
//	return leftDep > rightDep ? leftDep + 1 : rightDep + 1;
//
//}
//BinaryTreeNode* BinaryTreeFind(BinaryTreeNode* root, BTDataType x)//查找结点
//{
//	if (root == NULL) return NULL;
//	if (root->data == x) return root;
//
//	BinaryTreeNode* left = BinaryTreeFind(root->left,x);
//	if (left != NULL) return left;
//	BinaryTreeNode* right = BinaryTreeFind(root->right,x);
//	if (right != NULL) return right;
//
//	return NULL;
//}
//int main()
//{
//	//准备结点
//	BinaryTreeNode* A = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
//	assert(A);
//	A->data = 'A';
//	A->left = NULL;
//	A->right = NULL;
//
//	BinaryTreeNode* B = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
//	assert(B);
//	B->data = 'B';
//	B->left = NULL;
//	B->right = NULL;
//
//	BinaryTreeNode* C = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
//	assert(C);
//	C->data = 'C';
//	C->left = NULL;
//	C->right = NULL;
//
//	BinaryTreeNode* D = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
//	assert(D);
//	D->data = 'D';
//	D->left = NULL;
//	D->right = NULL;
//
//	BinaryTreeNode* E = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
//	assert(E);
//	E->data = 'E';
//	E->left = NULL;
//	E->right = NULL;
//
//	//构建树结构
//	A->left = B;
//	A->right = C;
//	B->left = D;
//	B->right = E;
//
//	int count = 0;
//	GetBinaryTreeNodeSize_1(A, &count);
//	printf("共有%d个结点\n", count);//5
//	printf("共有%d个结点\n", GetBinaryTreeNodeSize_2(A));//5
//
//	printf("叶子数为:%d\n", GetLeaf(A));//3
//
//	int k = 3;
//	printf("第%d层共有%d个结点\n", k, GetLevelKSize(A, k));
//
//	printf("该树的深度为%d\n", GetDepth(A));
//
//	BinaryTreeNode* node = BinaryTreeFind(A,'E');
//	printf("%c\n", node->data);
//	return 0;
//}





//构建销毁二叉树
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//typedef char BTDataType;
//typedef struct BinaryTreeNode {
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//	BTDataType data;
//}BinaryTreeNode;
//
//BinaryTreeNode* BuyNode(BTDataType x) {
//	BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
//	assert(node);
//	node->data = x;
//	node->left = node->right = NULL;
//	return node;
//}
//
//BinaryTreeNode* CreateTree(char* str, int* pi) {
//	if (str[*pi] == '#') {
//		++(*pi);
//		return NULL;
//	}
//	BinaryTreeNode* root = BuyNode(str[(*pi)++]);
//	root->left = CreateTree(str, pi);
//	root->right = CreateTree(str, pi);
//	return root;
//}
//
//void InOrder(BinaryTreeNode* root) {
//	if (root == NULL) return;
//	InOrder(root->left);
//	printf("%c ", root->data);
//	InOrder(root->right);
//}
//
//void DestoryTree(BinaryTreeNode* root)//后序销毁
//{
//	if (root == NULL) return;
//	DestoryTree(root->left);
//	DestoryTree(root->right);
//	free(root);
//}
//int main()
//{
//	char str[101] = { 0 };
//	scanf("%s", str);
//
//	int i = 0;
//	BinaryTreeNode* root = CreateTree(str, &i);
//
//	InOrder(root);
//
//	DestoryTree(root);
//	return 0;
//}





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

































//搜索二叉树(二叉排序树、二叉查找树 BST)
/*
它或者是一棵空树，或者是具有以下性质的二叉树:
若它的左子树不为空，则左子树上所有节点的值都小于根节点的值
若它的右子树不为空，则右子树上所有节点的值都大于根节点的值
它的左右子树也分别为二叉搜索树
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
//
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


//using namespace KEY;
//void test_K()
//{
//	BinarySearchTree<int> bst;
//	int arr[] = { 8,3,1,10,6,7,2,4,5,9,4,3,4 };
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
//		bst.insert(arr[i]);
//	}
//	BinarySearchTree<int> copy1 = bst;
//	BinarySearchTree<int> copy2;
//	copy2 = bst;
//
//	cout << bst.find(4) << endl;
//	bst.inorder();
//	cout << endl;
//	for (int i = 0; i < 10; ++i) 
//	{
//		bst.erase(i + 1);
//		bst.inorder();
//		cout << endl;
//	}
//
//	copy1.inorder();
//	cout << endl;
//	copy2.inorder();
//}


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