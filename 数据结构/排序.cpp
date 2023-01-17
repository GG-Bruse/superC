/*
����ĸ���:
ʹһ����¼����������ĳ����ĳЩ�ؼ��ֵĴ�С��������ݼ������������Ĳ���

�ȶ���:
�ٶ��ڴ�����ļ�¼�����С����ڶ��������ͬ�Ĺؼ��ֵļ�¼��������������Щ��¼����Դ��򱣳ֲ���
(����ԭ�����У�arr[i] == arr[j]��arr[i]��arr[j]ǰ�����������arr[i]����arr[j]ǰ)�������������㷨���ȶ��ģ�����Ϊ���ȶ�

�ڲ�����:
����Ԫ��ȫ�������ڴ��е�����
�ⲿ����:
����Ԫ��̫�಻��ͬʱ�����ڴ��У�����������̵�Ҫ�����������֮���ƶ����ݵ�����
*/



/*
									��������:ֱ�Ӳ�������ϣ������

									ѡ������:ѡ�����򡢶�����
			������ʱ��Ƚ��������:
									��������:ð�����򡢿�������
			
									�鲢����(��·�鲢���򡢶�·�鲢����)
�������:



			����ʱ��ǱȽ��������:�������򡢻�������
*/















/*
ֱ�Ӳ�������:
�Ѵ�����ļ�¼����ؼ���ֵ�Ĵ�С������뵽�Ѿ��ź�������������У�ֱ�����еļ�¼������Ϊֹ���õ�һ���µ���������
(���������i��Ԫ��ʱ��ǰ���array[0]����array[i-1]�Ѿ��ź��򣬴�ʱ��array[i]����������array[0]����array[i-1]����������бȽϣ�
�ҵ�����λ�ý�array[i]����,ԭ��λ���ϵ�Ԫ��˳�����)
*/

//#include<stdio.h>
//void InsertSort(int* arr, int n)//����
//{
//	for (int i = 0; i < n-1; ++i)//һ������n-1��
//	{
//		int end = i;
//		int temp = arr[end + 1];
//		while(end >= 0)
//		{
//			if (temp < arr[end])
//			{
//				arr[end + 1] = arr[end];
//				--end;
//			}
//			else {
//				break;//�ҵ�λ��
//			}
//		}
//		arr[end + 1] = temp;
//	}
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	InsertSort(arr, 10);
//	for (int i = 0; i < 10; ++i){
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//ʱ�临�Ӷ�:O(n^2)





/*
ϣ������(��С��������):
��������ֱ�Ӳ���������Ż�
�Ƚ�����������ļ�¼���зָ��Ϊ���������зֱ����ֱ�Ӳ�������(��Ԥ����)�������������еļ�¼"��������"ʱ���ٶ�ȫ���¼��������ֱ�Ӳ�������
*/

//#include<stdio.h>
//void ShellSort(int* arr, int n)//����
//{
//	int gap = n;
//	while (gap > 1)//gapȡֵ�޹ٷ��涨(2��3����)
//	{
//		gap = gap / 3 + 1;
//		//�Ѽ��Ϊgap�Ķ�������ͬʱ��
//		for (int i = 0; i < n - gap; ++i)
//		{
//			int end = i;
//			int temp = arr[end + gap];
//			while (end >= 0)
//			{
//				if (arr[end] > temp)
//				{
//					arr[end + gap] = arr[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			arr[end + gap] = temp;
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	ShellSort(arr, 10);
//	for (int i = 0; i < 10; ++i) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//ʱ�临�Ӷ�:O(NlogN)






















//ѡ���������˼��:
//ÿһ�δӴ����������Ԫ����ѡ�����(��С)��һ��Ԫ�أ���������е���ʼλ�ã�ֱ��ȫ�������������Ԫ������

//ѡ������
//#include<stdio.h>
//void Swap(int* a, int* b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void SelectSort(int* arr, int n)
//{
//	for (int i = 0;i < n - 1;++i)
//	{
//		int min = i;
//		for (int j = i+1; j < n; ++j)
//		{
//			if (arr[j] < arr[min]) {
//				min = j;
//			}
//		}
//		if (min != i) {
//			Swap(&arr[i], &arr[min]);
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
//	SelectSort(arr, (int)(sizeof(arr) / sizeof(int)));
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}




//ֱ��ѡ������(�Ż���)
/*
ͬʱ�������ֵ����Сֵ
ʱ�临�Ӷ�Ϊ:O(N^2)
*/

//#include<stdio.h>
//void Swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void SelectSort(int* arr,int n)
//{
//	
//	for (int begin = 0,end = n - 1; begin < end; ++begin, --end)
//	{
//		int mini = begin, maxi = begin;
//		for (int i = begin + 1; i <= end; ++i)
//		{
//			if (arr[i] < arr[mini]) mini = i;
//			if (arr[i] > arr[maxi]) maxi = i;
//		}
//		Swap(&arr[begin], &arr[mini]);
//		if (begin == maxi)maxi = mini;//ǰ��Ľ������ܸı��˴������ֵ��λ��
//		Swap(&arr[end], &arr[maxi]);
//	}
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
//	SelectSort(arr, (int)(sizeof(arr) / sizeof(int)));
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}







/*
������:
�ѵ��߼��ṹ��һ����ȫ���������ѵ�����ṹ��һ������(����)
leftchild = parent * 2 +1;
rightchild = parent * 2 + 2; 
parent = (child - 1)/2

�ѵ���������:
1.�ṹ��:
		�������ʾ�Ķ�����
2.������:
		��һ���Ĺؼ��������������н������ֵ\��Сֵ
		����(�󶥶ѡ������):���ֵ
		��С��(С���ѡ�С����):��Сֵ
*/
/*
1.����:(�����򽨴�ѣ��Ž���С��)		���ѵ�ʱ�临�Ӷ�Ϊ:O(n)
���µ����㷨:������ѣ��Ӹ���㿪ʼѡ�����Һ����нϴ��һ�����븸�ױȽϣ����ȸ��״��򽻻���Ȼ��������µ���ֱ��Ҷ�ӽ����ֹ��(ǰ��:�����������Ǵ��)
			 ����С�ѣ��Ӹ���㿪ʼѡ�����Һ����н�С��һ�����븸�ױȽϣ����ȸ���С�򽻻���Ȼ��������µ���ֱ��Ҷ�ӽ����ֹ��(ǰ��:������������С��)
�����һ����Ҷ�ӵ�������ʼʹ�����µ����㷨����֤��������������С��,��ɽ���ѡ�
2.�����(С)����������󣬲����ٲ�������ǰn-1�������µ������ٸ������ڶ���λ�ý�������
*/
/*
#include<stdio.h>
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void AdJustDown(int* arr,int n,int root)
{
	int parent = root;
	int child = parent * 2 + 1;//Ĭ������
	while (child < n)
	{
		if (child+1 < n && arr[child + 1] > arr[child])
		{
			++child;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr,int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdJustDown(arr, n, i);
	}
	for(int end = n - 1;end > 0; --end)
	{
		Swap(&arr[0], &arr[end]);
		AdJustDown(arr, end, 0);
	}
}
int main()
{
	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
	HeapSort(arr, 10);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/
//ʱ�临�Ӷ�:O(NlogN)

























//�����������˼��:
//����ֵ�ϴ�(С)�ļ�¼�����е�β���ƶ�����ֵ��С(��)�ļ�¼�����е�ǰ���ƶ�


//ð������

//#include<stdio.h>
//void Swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void BubbleSort(int arr[],int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		int exchange = 0;
//		for (int j = 0; j < n-i-1; ++j)
//		{
//			if (arr[j] > arr[j+1])
//			{
//				Swap(&arr[j], &arr[j + 1]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)//��û������������ֹͣѭ��
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
//	BubbleSort(arr, (int)(sizeof(arr) / sizeof(int)));
//	for (int i = 0; i < 10; ++i) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//ʱ�临�Ӷ�Ϊ:O(n)







/*
����������һ�ֶ������ṹ�Ľ������򷽷���(ʱ�临�Ӷ�ΪO(NlogN))
�����˼��Ϊ:
��ȡ������Ԫ�������е�ĳԪ����Ϊ��׼ֵkey(keyһ��ѡ���һ���������һ��)�����ո������뽫�����򼯺Ϸָ���������С�
��������������Ԫ�ؾ�С�ڻ�׼ֵ����������������Ԫ�ؾ����ڻ�׼ֵ��Ȼ�������������ظ��ù��̣�ֱ������Ԫ�ض���������Ӧλ��Ϊֹ��
*/
/*
�������������������������ʱ��ʱ�临�Ӷ�ΪO(N^2)
�������:����ȡ��
*/


//�ڿӷ�
//#include<stdio.h>
//void Swap(int* a, int* b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void InsertSort(int* arr, int n)
//{
//	for (int i = 0; i < n - 1; ++i)
//	{
//		int end = i;
//		int temp = arr[end + 1];
//		while (end >= 0)
//		{
//			if (arr[end] > temp)
//			{
//				arr[end + 1] = arr[end];
//				--end;
//			}
//			else
//			{
//				break;//�ҵ�λ��
//			}
//		}
//		arr[end + 1] = temp;
//	}
//}
//int GetMid(int* arr,int left,int right)//����ȡ��
//{
//	int mid = (left + right) >> 1;
//	if (arr[left] < arr[mid])
//	{
//		if (arr[mid] < arr[right]) return mid;
//		else if (arr[left] > arr[right]) return left;
//		else return right;
//	}
//	else//arr[left] > arr[mid]
//	{
//		if (arr[mid] > arr[right]) return mid;
//		else if (arr[left] > arr[right]) return right;
//		else return left;
//	}
//}
//void QuickSort(int* arr, int left,int right)
//{
//	if (left >= right)return;
//
//	int index = GetMid(arr, left, right);
//	Swap(&arr[left], &arr[index]);//�����߼�����
//
//	int begin = left, end = right;
//	int pivot = begin;
//	int key = arr[begin];
//	while (begin < end)
//	{
//		//�ұ���С���������
//		while (begin < end && arr[end] >= key) {
//			--end;
//		}
//		arr[pivot] = arr[end];
//		pivot = end;
//		//����Ҵ󣬷����ұ�
//		while (begin < end && arr[begin] <= key) {
//			++begin;
//		}
//		arr[pivot] = arr[begin];
//		pivot = begin;
//	}
//	pivot = begin;
//	arr[pivot] = key;
//
//	//С�����Ż�(�������ṹ��Խ����Ҷ�ӣ�������ֻ�Խ��(�������ÿ����ϴ�);β��ֱ��ʹ�ò�������)
//	//���ʺ�ʹ�ö�����(ͬΪ�������ṹ)��ϣ������(�ʺϴ���������)
//	if (pivot - 1 - left > 10) {
//		QuickSort(arr, left, pivot - 1);
//	}
//	else {
//		InsertSort(arr + left, pivot - 1 - left + 1);
//	}
//	if (right - pivot - 1 > 10) {//��ֵ�������������е���
//		QuickSort(arr, pivot + 1, right);
//	}
//	else {
//		InsertSort(arr + pivot + 1, right - pivot - 1 + 1);
//	}
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
//	QuickSort(arr, 0 ,(int)(sizeof(arr) / sizeof(int))-1);
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//#include<stdio.h>
//void Swap(int* a, int* b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void QuickSort(int* arr, int left, int right)
//{
//	if (left >= right)return;
//
//	int begin = left, end = right;
//	int pivot = begin;
//	int key = arr[begin];
//	while (begin < end)
//	{
//		//�ұ���С���������
//		while (begin < end && arr[end] >= key) {
//			--end;
//		}
//		arr[pivot] = arr[end];
//		pivot = end;
//		//����Ҵ󣬷����ұ�
//		while (begin < end && arr[begin] <= key) {
//			++begin;
//		}
//		arr[pivot] = arr[begin];
//		pivot = begin;
//	}
//	pivot = begin;
//	arr[pivot] = key;
//	QuickSort(arr, left, pivot - 1);
//	QuickSort(arr, pivot + 1, right);
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
//	QuickSort(arr, 0, (int)(sizeof(arr) / sizeof(int)) - 1);
//	for (int i = 0; i < 10; ++i) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



//����ָ�뷨hoare
//#include<stdio.h>
//void Swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void QuickSort(int* arr, int left, int right)
//{
//	if (left >= right)return;
//
//	int begin = left, end = right;
//	int key = begin;
//	while (begin < end)
//	{
//		while (begin < end && arr[end] >= arr[key])//��С
//		{
//			--end;
//		}
//		while (begin < end && arr[begin] <= arr[key])//�Ҵ�
//		{
//			++begin;
//		}
//		Swap(&arr[begin], &arr[end]);
//	}
//	Swap(&arr[begin], &arr[key]);
//
//	QuickSort(arr, left, begin - 1);
//	QuickSort(arr, begin + 1, right);
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
//	QuickSort(arr, 0, (int)(sizeof(arr) / sizeof(int)) - 1);
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}




//ǰ��ָ�뷨
//#include<stdio.h>
//void Swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void QuickSort(int* arr, int left, int right)
//{
//	if (left >= right)return;
//
//	int key = left;
//	int prev = left, cur = left + 1;
//	while (cur <= right)
//	{
//		if (arr[cur] < arr[key] && ++prev != cur)//���������彻��
//		{
//			Swap(&arr[prev], &arr[cur]);
//		}
//		++cur;
//	}
//	Swap(&arr[key], &arr[prev]);
//
//	QuickSort(arr, left, prev - 1);
//	QuickSort(arr, prev + 1, right);
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
//	QuickSort(arr, 0, (int)(sizeof(arr) / sizeof(int)) - 1);
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}




//�ǵݹ�(�ݹ��ȱ��:ջ֡��ȹ���stackoverflow)
//#include<stdio.h>
//#include<stdbool.h>
//#include<stdlib.h>
//#include<assert.h>
////����ջʵ�ַǵݹ�
///************************************************************************************/
//typedef int SKDataType;
//typedef struct stack
//{
//	SKDataType* data;
//	int top;
//	int capacity;
//}Stack;
//void StackInit(Stack* ps)
//{
//	assert(ps);
//	ps->data = (SKDataType*)malloc(sizeof(SKDataType)*4);
//	if(ps->data == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//
//	ps->capacity = 4;
//	ps->top = 0;//topָ��ջ��Ԫ�ص���һ��λ��
//}
//void StackDestory(Stack* ps)
//{
//	assert(ps);
//	free(ps->data);
//	ps->data = NULL;
//	ps->capacity = ps->top = 0;
//}
//void StackPush(Stack* ps,SKDataType d)
//{
//	assert(ps);
//	if(ps->top == ps->capacity)
//	{
//		SKDataType* newSpace = (SKDataType*)realloc(ps->data,ps->capacity * 2 * sizeof(SKDataType));
//		if(newSpace == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		ps->data = newSpace;
//		ps->capacity *= 2;
//	}
//	ps->data[ps->top] = d;
//	++ps->top;
//}
//void StackPop(Stack* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);//ջ����Ϊ��
//	--ps->top;
//}
//SKDataType StackTop(Stack* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//	return ps->data[ps->top - 1];
//}
//int StackSize(Stack* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//bool StackIsEmpty(Stack* ps)
//{
//	assert(ps);
//	return ps->top == 0;
//}
///***********************************************************************************/
//void QuickSort(int* arr, int size)
//{
//	Stack sk;
//	StackInit(&sk);
//	StackPush(&sk, size);
//	StackPush(&sk, 0);
//	while (!StackIsEmpty(&sk))
//	{
//		int left = StackTop(&sk);
//		StackPop(&sk);
//		int right = StackTop(&sk);
//		StackPop(&sk);
//
//		//�ڿӵ�������
//		int begin = left, end = right;
//		int pivot = begin;
//		int key = arr[begin];
//		while (begin < end)
//		{
//			//�ұ���С���������
//			while (begin < end && arr[end] >= key)
//			{
//				--end;
//			}
//			arr[pivot] = arr[end];
//			pivot = end;
//			//����Ҵ󣬷����ұ�
//			while (begin < end && arr[begin] <= key)
//			{
//				++begin;
//			}
//			arr[pivot] = arr[begin];
//			pivot = begin;
//		}
//		pivot = begin;
//		arr[pivot] = key;
//
//		if (right > pivot + 1)
//		{
//			StackPush(&sk, right);
//			StackPush(&sk, pivot + 1);
//		}
//		if (left < pivot - 1)
//		{
//			StackPush(&sk, pivot - 1);
//			StackPush(&sk, left);
//		}
//	}
//	StackDestory(&sk);
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
//	QuickSort(arr, (int)(sizeof(arr) / sizeof(int)) - 1);
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}




















/*
�鲢����(������):
�ǽ����ڹ鲢�����ϵ�һ����Ч�������㷨�����÷��η���
��������������кϲ����õ���ȫ��������С�����ʹÿ��������������ʹÿ�������м�����
�������������ϲ���һ���������Ϊ��·�鲢
*/
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <string.h>
//void _MergeSort(int* arr, int left, int right,int* temp)
//{
//	if (left >= right) return;
//	int mid = (left + right) >> 1;
//	_MergeSort(arr, left, mid, temp);
//	_MergeSort(arr, mid + 1, right, temp);
//
//	int begin1 = left, end1 = mid;
//	int begin2 = mid + 1, end2 = right;
//	int index = left;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (arr[begin1] < arr[begin2]) {
//			temp[index++] = arr[begin1++];
//		}
//		else {
//			temp[index++] = arr[begin2++];
//		}
//	}
//	while (begin1 <= end1) {
//		temp[index++] = arr[begin1++];
//	}
//	while (begin2 <= end2) {
//		temp[index++] = arr[begin2++];
//	}
//
//	//���鲢���ݿ�����ԭ����
//	/*for (int i = left; i <= right; ++i) {
//		arr[i] = temp[i];
//	}*/
//	memcpy(arr + left, temp + left, (right - left + 1) * sizeof(int));
//}
//void MergeSort(int* arr, int size)
//{
//	int* temp = (int*)malloc(sizeof(int) * size);
//	assert(temp);
//	_MergeSort(arr, 0, size - 1, temp);
//	free(temp);
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
//	MergeSort(arr,(int)(sizeof(arr) / sizeof(int)));
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}



//�ǵݹ�
//#include<stdio.h>
//#include<stdlib.h>
//void MergeSort(int* arr, int size)
//{
//	if (arr == NULL) return;
//	int* temp = (int*)malloc(sizeof(int) * size);
//	if (temp == NULL) return;
//
//	int gap = 1;//ÿ�����ݸ���
//	while (gap < size)
//	{
//		for (int i = 0; i < size ; i += 2 * gap)
//		{
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			int index = i;
//
//			if (end1 >= size) {
//				end1 = size - 1;
//				//[begin2.end2]��Ϊһ�������ڵ�����
//				begin2 = size;
//				end2 = size - 1;
//			}
//			else if (begin2 >= size) {
//				begin2 = size;
//				end2 = size - 1;
//			}
//			else if (end2 >= size) end2 = size - 1;//�鲢������������������
//
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (arr[begin1] < arr[begin2]) {
//					temp[index++] = arr[begin1++];
//				}
//				else {
//					temp[index++] = arr[begin2++];
//				}
//			}
//			while (begin1 <= end1) {
//				temp[index++] = arr[begin1++];
//			}
//			while (begin2 <= end2) {
//				temp[index++] = arr[begin2++];
//			}
//		}
//		for (int j = 0; j < size; ++j) {
//			arr[j] = temp[j];
//		}
//		gap *= 2;
//	}
//	free(temp);
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
//	MergeSort(arr, (int)(sizeof(arr) / sizeof(int)));
//	for (int i = 0; i < 10; ++i) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}




















/*
��������(�ǱȽ�����):
��������ĺ������ڽ����������ֵת��Ϊ���洢�ڶ��⿪�ٵ�����ռ��С���Ϊһ������ʱ�临�Ӷȵ����򣬼�������Ҫ����������ݱ�������ȷ����Χ���������ݡ�

��1���ҳ��������������������С��Ԫ��(ʹ�����ӳ�䣬���ٿռ��˷�)
��2��ͳ��������ÿ��ֵΪi��Ԫ�س��ֵĴ�������������C�ĵ�i��
��3�������еļ����ۼӣ���C�еĵ�һ��Ԫ�ؿ�ʼ��ÿһ���ǰһ����ӣ�
��4���������Ŀ�����飺��ÿ��Ԫ��i����������ĵ�C(i)�ÿ��һ��Ԫ�ؾͽ�C(i)��ȥ1
*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<assert.h>
//void CountSort(int* arr, int size)
//{
//	int max = arr[0], min = arr[0];
//	for (int i = 1; i < size; ++i)
//	{
//		if (arr[i] > max) max = arr[i];
//		if (arr[i] < min) min = arr[i];
//	}
//	int range = max - min + 1;
//
//	int* count = (int*)calloc(range ,sizeof(int));
//	assert(count);
//
//	for (int i = 0; i < size; ++i) {
//		count[arr[i] - min]++;//���λ��ӳ��
//	}
//	
//	int j = 0;
//	for (int i = 0; i < range; ++i)
//	{
//		while (count[i]--) {
//			arr[j++] = i + min;
//		}
//	}
//
//	free(count);
//	count = NULL;
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
//	CountSort(arr, (int)(sizeof(arr) / sizeof(int)));
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//ʱ�临�Ӷ�ΪO(N + range),�����ڷ�Χ���е���������