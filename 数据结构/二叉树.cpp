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
�������ֵܱ�ʾ��:
�������ߵĺ��ӳ�Ϊ���ӽ�㣬���ӵ��ұߵ��ֵ�Ϊ�Һ���(��һ�ö����ת��Ϊ������)
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
6.����N�������������������Ϊ ��2Ϊ��(N+1)�Ķ���
7.���ھ���n��������ȫ��������������մ������´������ҵ�����˳������нڵ��0��ʼ��ţ���������Ϊi�Ľ����:
	(1)��i > 0��iλ�ý���˫�����: (i-1)/2		��i = 0��iΪ���ڵ��ţ���˫�׽ڵ�
	(2)��2i + 1 < n��iλ�ý���������: 2i + 1	��2i + 1 >= n��������
	(3)��2i + 2 < n��iλ�ý���Һ������: 2i + 2	��2i + 2 >= n�����Һ���


���������:
1.��������:
һ�����Ϊh����2^h - 1�����Ķ�����(��ÿ��Ľ�������ﵽ���ֵ)
2.��ȫ������:
�����һ���⣬ÿ���ϵĽ�������ﵽ���ֵ�������һ����ֻȱ���ұߵ����ɽ��
(�������Ϊk������n�����Ķ����������ҽ�����ÿһ����������Ϊk�����������б�Ŵ�1��n�Ľ��һһ��Ӧʱ���ö���������Ϊ��ȫ������)
����������һ���������ȫ������
*/


/*
�������Ĵ洢��ʽ:
1.˳��洢:
��������洢��һ������ֻ�ʺϱ�ʾ��ȫ������(������ȫ���������пռ��ϵ��˷�)����ʵ��ʹ����ֻ�жѲŻ�ʹ���������洢
������˳��洢����������һ�����飬���߼�����һ��������
2.��ʽ�洢:
����������ʽ�洢�ṹ��ָ����������ʾһ�ö���������������ָʾԪ��֮����߼���ϵ��
ͨ���ķ���:�����ÿ���������������ɣ������������ָ����
��ʽ�ṹ�ַ�Ϊ������(left��right)��������(left��right��parent)
*/











//��
/*
�ѵ��߼��ṹ��һ����ȫ������
1.�ṹ��:
		�������ʾ�Ķ�����(����)
2.������:
		��һ���Ĺؼ��������������н������ֵ\��Сֵ
		����(�󶥶ѡ������):���ֵ	˫�״��ڵ��ں���
		��С��(С���ѡ�С����):��Сֵ	˫��С�ڵ��ں���
*/

//С��
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
//void HeapPop(Heap* hp)//ɾ���Ѷ�����
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

//������
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
//	//���ѵķ�ʽ1 O(NlogN)
//	/*for (int i = 1; i < size; ++i) {//�����˼�룬ÿ����һ�������ϵ���һ��
//		AdjustUp(array, i);
//	}*/
//	//���ѵķ�ʽ2 O(N)		//�ѵ�����Ҳ���Ƕ�
//	for (int i = (size - 1 - 1) / 2; i >= 0; --i) {//Ҷ�Ӳ���Ҫ����
//		AdjustDown(array, size, i);
//	}
//	for (int i = size- 1; i > 0; --i)//ɾ����˼�룬ÿ��ɾ���Ķ��Ƕ�����С����
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



//Top-K����
/*
�������ݽ����ǰK������Ԫ�ػ�����С��Ԫ�أ�һ����������������Ƚϴ�
����Top-K���⣬���뵽�����ֱ�ӵķ�ʽ�������򣬵��ǣ�����������ǳ�������Ͳ�̫��ȡ��(�������ݶ�����һ����ȫ�����ص��ڴ���)��
��ѵķ�ʽ�����ö������
*/
/*
1. �����ݼ�����ǰK��Ԫ��������
ǰk������Ԫ�أ���С��
ǰk����С��Ԫ�أ��򽨴��
2. ��ʣ���N-K��Ԫ��������Ѷ�Ԫ�����Ƚϣ����������滻�Ѷ�Ԫ��
N-K��Ԫ��������Ѷ�Ԫ�ر���֮�󣬶���ʣ���K��Ԫ�ؾ��������ǰK����С��������Ԫ��
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

























//��ʽ������
/*
�������ı�����ʽ:
1.������ȱ���:DFS
����(��)����:�� ������ ������ NLR	������������
����(��)����:������ �� ������ LNR
����(��)����:������ ������ �� LRN	
2.�������(������ȱ���):BFS
��������ĸ�������ڲ���Ϊ1������������Ǵ����ڶ������ĸ���������
���ȷ��ʵ�һ���������㣬Ȼ������ҷ��ʵڶ����ϵĽ�㣬�Դ����ƣ����ϵ��£������ң����������Ľ�㡣
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
//void PrevOrder(struct BinaryTreeNode* root)//ǰ��
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
//void InOrder(struct BinaryTreeNode* root)//����
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
//void PostOrder(struct BinaryTreeNode* root)//����
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
//void DestoryTree(struct BinaryTreeNode* root)//��������
//{
//	if (root == NULL)
//		return;
//	DestoryTree(root->left);
//	DestoryTree(root->right);
//	free(root);
//}
//int main()
//{
//	//׼�����
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
//	//�������ṹ
//	A->left = B;
//	A->right = C;
//	B->left = D;
//	B->right = E;
//
//	//ǰ�к������
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
//void GetBinaryTreeNodeSize_1(BinaryTreeNode* root, int* count)//��ȡ�����
//{
//	if (root == NULL)return;
//	++(*count);
//	GetBinaryTreeNodeSize_1(root->left, count);
//	GetBinaryTreeNodeSize_1(root->right, count);
//}
//int GetBinaryTreeNodeSize_2(BinaryTreeNode* root)//��ȡ�����
//{
//	return root == NULL ? 0 : GetBinaryTreeNodeSize_2(root->left) + GetBinaryTreeNodeSize_2(root->right) + 1;
//}
//int GetLeaf(BinaryTreeNode* root)//��ȡҶ����
//{
//	if (root == NULL)return 0;
//	return ((root->left == NULL) && (root->right == NULL)) ? 1 : GetLeaf(root->left) + GetLeaf(root->right);
//}
//int GetLevelKSize(BinaryTreeNode* root, int k)//���k��ڵ����
//{
//	assert(k >= 1);
//	if (root == NULL) return 0;
//	if (k == 1) return 1;
//	return GetLevelKSize(root->left, k - 1) + GetLevelKSize(root->right, k - 1);
//}
//int GetDepth(BinaryTreeNode* root)//���������
//{
//	if (root == NULL) return 0;
//	int leftDep = GetDepth(root->left);
//	int rightDep = GetDepth(root->right);
//	return leftDep > rightDep ? leftDep + 1 : rightDep + 1;
//
//}
//BinaryTreeNode* BinaryTreeFind(BinaryTreeNode* root, BTDataType x)//���ҽ��
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
//	//׼�����
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
//	//�������ṹ
//	A->left = B;
//	A->right = C;
//	B->left = D;
//	B->right = E;
//
//	int count = 0;
//	GetBinaryTreeNodeSize_1(A, &count);
//	printf("����%d�����\n", count);//5
//	printf("����%d�����\n", GetBinaryTreeNodeSize_2(A));//5
//
//	printf("Ҷ����Ϊ:%d\n", GetLeaf(A));//3
//
//	int k = 3;
//	printf("��%d�㹲��%d�����\n", k, GetLevelKSize(A, k));
//
//	printf("���������Ϊ%d\n", GetDepth(A));
//
//	BinaryTreeNode* node = BinaryTreeFind(A,'E');
//	printf("%c\n", node->data);
//	return 0;
//}





//�������ٶ�����
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
//void DestoryTree(BinaryTreeNode* root)//��������
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





//�������(�ǵݹ�)��������ʵ��
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<stdbool.h>
//typedef char BTDataType;
//typedef struct BinaryTreeNode
//{
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//	BTDataType data;
//}BinaryTreeNode;
/////*************************************************************
//typedef struct BinaryTreeNode* QDataType;
//typedef struct QueueNode
//{
//	QDataType data;
//	struct QueueNode* next;
//}QNode;
//typedef struct Queue
//{
//	QNode* head;
//	QNode* tail;
//}Queue;
//
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = pq->tail = NULL;
//}
//void QueueDestory(Queue* pq)
//{
//	assert(pq);
//	QNode* cur = pq->head;
//	while (cur != NULL)
//	{
//		QNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pq->head = pq->tail = NULL;
//}
//void QueuePush(Queue* pq, QDataType d)//��β�� 
//{
//	assert(pq);
//	QNode* newNode = (QNode*)malloc(sizeof(QNode));
//	if (newNode == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	newNode->next = NULL;
//	newNode->data = d;
//
//	if (pq->tail == NULL)
//	{
//		pq->head = pq->tail = newNode;
//	}
//	else
//	{
//		pq->tail->next = newNode;
//		pq->tail = newNode;
//	}
//}
//void QueuePop(Queue* pq)//��ͷ�� 
//{
//	assert(pq);
//	assert(pq->head);//���в�Ϊ��
//	if (pq->head->next == NULL)//ֻ��һ��������� 
//	{
//		free(pq->head);
//		pq->head = pq->tail = NULL;
//	}
//	else
//	{
//		QNode* next = pq->head->next;
//		free(pq->head);
//		pq->head = next;
//	}
//}
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(pq->head);
//	return pq->head->data;
//}
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(pq->tail);
//	return pq->tail->data;
//}
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//	int size = 0;
//	QNode* cur = pq->head;
//	while (cur != NULL)
//	{
//		++size;
//		cur = cur->next;
//	}
//	return size;
//}
//bool QueueIsEmpty(Queue* pq)
//{
//	assert(pq);
//	return pq->head == NULL;
//}
////********************************************************
////1�����Ƚ��������ĸ��ڵ�push�������У��ж϶��в�Ϊ�գ��������ͷ��Ԫ�أ�
////2���������Ľڵ������
////3���жϽڵ�����к��ӣ��ͽ�����push��������
////4��ѭ�����ϲ�����ֱ��Tree == NULL��
//void LevelOrder(BinaryTreeNode* root)//�������
//{
//	Queue q;
//	QueueInit(&q);
//	if (root != NULL) QueuePush(&q, root);
//	while (!QueueIsEmpty(&q))
//	{
//		struct BinaryTreeNode* front = QueueFront(&q);
//		QueuePop(&q);
//		printf("%c ", front->data);
//		if (front->left != NULL) QueuePush(&q, front->left);
//		if (front->right != NULL) QueuePush(&q, front->right);
//	}
//	QueueDestory(&q);
//}
//int BinaryTreeComplete(BinaryTreeNode* root) {//�ж��Ƿ�Ϊ��ȫ������
//	Queue q;
//	QueueInit(&q);
//	if (root != NULL) QueuePush(&q, root);
//	while (!QueueIsEmpty(&q))
//	{
//		struct BinaryTreeNode* front = QueueFront(&q);
//		QueuePop(&q);
//		if (front != NULL) {
//			QueuePush(&q, front->left);
//			QueuePush(&q, front->right);
//		}
//		else {
//			break;
//		}
//	}
//	while (!QueueIsEmpty(&q)) {//����ʱ������ȫΪ����Ϊ��ȫ������
//		if (QueueFront(&q) != NULL) {
//			QueueDestory(&q);
//			return false;
//		}
//		QueuePop(&q);
//	}
//	QueueDestory(&q);
//	return true;
//}
//int main()
//{
//	//׼�����
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
//	struct BinaryTreeNode* D = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
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
//	//�������ṹ
//	A->left = B;
//	A->right = C;
//	B->left = D;
//	B->right = E;
//
//	LevelOrder(A);
//	if (BinaryTreeComplete(A)) printf("����Ϊ��ȫ������\n");
//	else printf("������Ϊ��ȫ������\n");
//
//	return 0;
//}



