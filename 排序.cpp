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



			线性时间非比较类的排序:基数排序、桶排序、计数排序
*/















/*
直接插入排序:
把待排序的记录按其关键码值的大小逐个插入到已经排好序的有序序列中，直到所有的记录插入完为止，得到一个新的有序序列
(即当插入第i个元素时，前面的array[0]……array[i-1]已经排好序，此时用array[i]的排序码与array[0]……array[i-1]的排序码进行比较，
找到插入位置将array[i]插入,原来位置上的元素顺序后移)
*/
/*
#include<stdio.h>
void InsertSort(int* arr, int n)//升序
{
	for (int i = 0; i < n-1; ++i)
	{
		int end = i;
		int temp = arr[end + 1];
		while(end >= 0)
		{
			if (arr[end] > temp)
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
			{
				break;//找到位置
			}
		}
		arr[end + 1] = temp;
	}
}
int main()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	InsertSort(arr, 10);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/
//时间复杂度:O(n^2)





/*
希尔排序(缩小增量排序):
————直接插入排序的优化
先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序(即预排序)，待整个序列中的记录"基本有序"时，再对全体记录进行依次直接插入排序
*/
/*
#include<stdio.h>
void ShellSort(int* arr, int n)//升序
{
	for (int gap = n/3; gap > 1; gap = gap/3 +1)//gap取值无官方规定(2、3……)
	{
		//把间隔为gap的多组数据同时排
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int temp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > temp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = temp;
		}
	}
}
int main()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	ShellSort(arr, 10);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/
//时间复杂度:O(NlogN)

















//选择排序基本思想:
//每一次从待排序的数据元素中选出最大(最小)的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完

//选择排序
/*
#include<stdio.h>
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void SelectSort(int* arr, int n)
{
	for (int i = 0;i < n - 1;++i)
	{
		int min = i;
		for (int j = i+1; j < n; ++j)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			Swap(&arr[i], &arr[min]);
		}
	}
}
int main()
{
	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
	SelectSort(arr, (int)(sizeof(arr) / sizeof(int)));
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/



//直接选择排序(优化版)
/*
同时查找最大值和最小值
时间复杂度为:O(N^2)
*/
/*
#include<stdio.h>
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void SelectSort(int* arr,int n)
{
	
	for (int begin = 0,end = n - 1; begin < end; ++begin, --end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
		}
		Swap(&arr[begin], &arr[mini]);
		if (begin == maxi)maxi = mini;//特殊情况
		Swap(&arr[end], &arr[maxi]);
	}
}
int main()
{
	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
	SelectSort(arr, (int)(sizeof(arr) / sizeof(int)));
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/






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
/*
#include<stdio.h>
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSort(int arr[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		int exchange = 0;
		for (int j = 0; j < n-i-1; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				Swap(&arr[j], &arr[j + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0)//若没发生交换，则停止循环
		{
			break;
		}
	}
}
int main()
{
	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
	BubbleSort(arr, (int)(sizeof(arr) / sizeof(int)));
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/
//时间复杂度为:O(n)







/*
快速排序是一种二叉树结构的交换排序方法。
其基本思想为:
任取待排序元素序列中的某元素作为基准值，按照该排序码将待排序集合分割成两子序列。
左子序列中所有元素均小于基准值，右子序列中所有元素均大于基准值，然后左右子序列重复该过程，直到所有元素都排列在相应位置为止。
*/




