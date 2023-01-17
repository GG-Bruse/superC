/*
排序的概念:
使一串记录，按照其中某个或某些关键字的大小，递增或递减的排列起来的操作

稳定性:
假定在待排序的记录序列中。存在多个具有相同的关键字的记录，若经过排序，这些记录的相对次序保持不变
(即在原序列中，arr[i] == arr[j]且arr[i]在arr[j]前，而在排序后arr[i]仍在arr[j]前)，则这种排序算法是稳定的；否则为不稳定

内部排序:
数据元素全部放在内存中的排序
外部排序:
数据元素太多不能同时放在内存中，根据排序过程的要求不能在内外存之间移动数据的排序
*/



/*
									插入排序:直接插入排序、希尔排序

									选择排序:选择排序、堆排序
			非线性时间比较类的排序:
									交换排序:冒泡排序、快速排序
			
									归并排序(二路归并排序、多路归并排序)
排序分类:



			线性时间非比较类的排序:计数排序、基数排序
*/















/*
直接插入排序:
把待排序的记录按其关键码值的大小逐个插入到已经排好序的有序序列中，直到所有的记录插入完为止，得到一个新的有序序列
(即当插入第i个元素时，前面的array[0]……array[i-1]已经排好序，此时用array[i]的排序码与array[0]……array[i-1]的排序码进行比较，
找到插入位置将array[i]插入,原来位置上的元素顺序后移)
*/

//#include<stdio.h>
//void InsertSort(int* arr, int n)//升序
//{
//	for (int i = 0; i < n-1; ++i)//一共插入n-1趟
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
//				break;//找到位置
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
//时间复杂度:O(n^2)





/*
希尔排序(缩小增量排序):
————直接插入排序的优化
先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序(即预排序)，待整个序列中的记录"基本有序"时，再对全体记录进行依次直接插入排序
*/

//#include<stdio.h>
//void ShellSort(int* arr, int n)//升序
//{
//	int gap = n;
//	while (gap > 1)//gap取值无官方规定(2、3……)
//	{
//		gap = gap / 3 + 1;
//		//把间隔为gap的多组数据同时排
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
//时间复杂度:O(NlogN)






















//选择排序基本思想:
//每一次从待排序的数据元素中选出最大(最小)的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完

//选择排序
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




//直接选择排序(优化版)
/*
同时查找最大值和最小值
时间复杂度为:O(N^2)
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
//		if (begin == maxi)maxi = mini;//前面的交换可能改变了此趟最大值的位置
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
堆排序:
堆的逻辑结构是一棵完全二叉树，堆的物理结构是一个数组(层序)
leftchild = parent * 2 +1;
rightchild = parent * 2 + 2; 
parent = (child - 1)/2

堆的两个特性:
1.结构性:
		用数组表示的二叉树
2.有序性:
		任一结点的关键字是其子树所有结点的最大值\最小值
		最大堆(大顶堆、大根堆):最大值
		最小堆(小顶堆、小根堆):最小值
*/
/*
1.建堆:(排升序建大堆，排降序建小堆)		建堆的时间复杂度为:O(n)
向下调整算法:若建大堆，从根结点开始选出左右孩子中较大的一个，与父亲比较，若比父亲大则交换。然后继续往下调整直到叶子结点终止。(前提:左右子树都是大堆)
			 若建小堆，从根结点开始选出左右孩子中较小的一个，与父亲比较，若比父亲小则交换。然后继续往下调整直到叶子结点终止。(前提:左右子树都是小堆)
从最后一个非叶子的子树开始使用向下调整算法，保证其左右子树都是小堆,完成建大堆。
2.将最大(小)数交换到最后，并不再参与排序。前n-1个数向下调整，再跟倒数第二个位置交换……
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
	int child = parent * 2 + 1;//默认左孩子
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
//时间复杂度:O(NlogN)

























//交换排序基本思想:
//将键值较大(小)的记录向序列的尾部移动，键值较小(大)的记录向序列的前部移动


//冒泡排序

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
//		if (exchange == 0)//若没发生交换，则停止循环
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
//时间复杂度为:O(n)







/*
快速排序是一种二叉树结构的交换排序方法。(时间复杂度为O(NlogN))
其基本思想为:
任取待排序元素序列中的某元素作为基准值key(key一般选择第一个或者最后一个)，按照该排序码将待排序集合分割成两子序列。
左子序列中所有元素均小于基准值，右子序列中所有元素均大于基准值，然后左右子序列重复该过程，直到所有元素都排列在相应位置为止。
*/
/*
快速排序在有序的情况下最坏，此时其时间复杂度为O(N^2)
解决方案:三数取中
*/


//挖坑法
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
//				break;//找到位置
//			}
//		}
//		arr[end + 1] = temp;
//	}
//}
//int GetMid(int* arr,int left,int right)//三数取中
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
//	Swap(&arr[left], &arr[index]);//保持逻辑不变
//
//	int begin = left, end = right;
//	int pivot = begin;
//	int key = arr[begin];
//	while (begin < end)
//	{
//		//右边找小，放在左边
//		while (begin < end && arr[end] >= key) {
//			--end;
//		}
//		arr[pivot] = arr[end];
//		pivot = end;
//		//左边找大，放在右边
//		while (begin < end && arr[begin] <= key) {
//			++begin;
//		}
//		arr[pivot] = arr[begin];
//		pivot = begin;
//	}
//	pivot = begin;
//	arr[pivot] = key;
//
//	//小区间优化(二叉树结构，越靠近叶子，结点数分化越多(函数调用开销较大);尾部直接使用插入排序)
//	//不适合使用堆排序(同为二叉树结构)、希尔排序(适合大体量数据)
//	if (pivot - 1 - left > 10) {
//		QuickSort(arr, left, pivot - 1);
//	}
//	else {
//		InsertSort(arr + left, pivot - 1 - left + 1);
//	}
//	if (right - pivot - 1 > 10) {//该值根据数据量自行调控
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
//		//右边找小，放在左边
//		while (begin < end && arr[end] >= key) {
//			--end;
//		}
//		arr[pivot] = arr[end];
//		pivot = end;
//		//左边找大，放在右边
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



//左右指针法hoare
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
//		while (begin < end && arr[end] >= arr[key])//找小
//		{
//			--end;
//		}
//		while (begin < end && arr[begin] <= arr[key])//找大
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




//前后指针法
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
//		if (arr[cur] < arr[key] && ++prev != cur)//避免无意义交换
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




//非递归(递归的缺陷:栈帧深度过大，stackoverflow)
//#include<stdio.h>
//#include<stdbool.h>
//#include<stdlib.h>
//#include<assert.h>
////利用栈实现非递归
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
//	ps->top = 0;//top指向栈顶元素的上一个位置
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
//	assert(ps->top > 0);//栈不可为空
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
//		//挖坑单趟排序
//		int begin = left, end = right;
//		int pivot = begin;
//		int key = arr[begin];
//		while (begin < end)
//		{
//			//右边找小，放在左边
//			while (begin < end && arr[end] >= key)
//			{
//				--end;
//			}
//			arr[pivot] = arr[end];
//			pivot = end;
//			//左边找大，放在右边
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
归并排序(外排序):
是建立在归并操作上的一种有效的排序算法，采用分治法。
将已有序的子序列合并，得到完全有序的序列。即先使每个子序列有序，再使每个子序列间有序。
若将两个有序表合并成一个有序表，称为二路归并
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
//	//将归并数据拷贝回原数组
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



//非递归
//#include<stdio.h>
//#include<stdlib.h>
//void MergeSort(int* arr, int size)
//{
//	if (arr == NULL) return;
//	int* temp = (int*)malloc(sizeof(int) * size);
//	if (temp == NULL) return;
//
//	int gap = 1;//每组数据个数
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
//				//[begin2.end2]即为一个不存在的区间
//				begin2 = size;
//				end2 = size - 1;
//			}
//			else if (begin2 >= size) {
//				begin2 = size;
//				end2 = size - 1;
//			}
//			else if (end2 >= size) end2 = size - 1;//归并过程中右区间计算过大
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
计数排序(非比较排序):
计数排序的核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整型数据。

（1）找出待排序的数组中最大和最小的元素(使用相对映射，减少空间浪费)
（2）统计数组中每个值为i的元素出现的次数，存入数组C的第i项
（3）对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
（4）反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1
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
//		count[arr[i] - min]++;//相对位置映射
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
//时间复杂度为O(N + range),适用于范围集中的整型数据