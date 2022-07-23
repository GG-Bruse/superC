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


















