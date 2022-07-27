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



			����ʱ��ǱȽ��������:��������Ͱ���򡢼�������
*/















/*
ֱ�Ӳ�������:
�Ѵ�����ļ�¼����ؼ���ֵ�Ĵ�С������뵽�Ѿ��ź�������������У�ֱ�����еļ�¼������Ϊֹ���õ�һ���µ���������
(���������i��Ԫ��ʱ��ǰ���array[0]����array[i-1]�Ѿ��ź��򣬴�ʱ��array[i]����������array[0]����array[i-1]����������бȽϣ�
�ҵ�����λ�ý�array[i]����,ԭ��λ���ϵ�Ԫ��˳�����)
*/
/*
#include<stdio.h>
void InsertSort(int* arr, int n)//����
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
				break;//�ҵ�λ��
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
//ʱ�临�Ӷ�:O(n^2)





/*
ϣ������(��С��������):
��������ֱ�Ӳ���������Ż�
�Ƚ�����������ļ�¼���зָ��Ϊ���������зֱ����ֱ�Ӳ�������(��Ԥ����)�������������еļ�¼"��������"ʱ���ٶ�ȫ���¼��������ֱ�Ӳ�������
*/
/*
#include<stdio.h>
void ShellSort(int* arr, int n)//����
{
	for (int gap = n/3; gap > 1; gap = gap/3 +1)//gapȡֵ�޹ٷ��涨(2��3����)
	{
		//�Ѽ��Ϊgap�Ķ�������ͬʱ��
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
//ʱ�临�Ӷ�:O(NlogN)

















//ѡ���������˼��:
//ÿһ�δӴ����������Ԫ����ѡ�����(��С)��һ��Ԫ�أ���������е���ʼλ�ã�ֱ��ȫ�������������Ԫ������

//ѡ������
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



//ֱ��ѡ������(�Ż���)
/*
ͬʱ�������ֵ����Сֵ
ʱ�临�Ӷ�Ϊ:O(N^2)
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
		if (begin == maxi)maxi = mini;//�������
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
		if (exchange == 0)//��û������������ֹͣѭ��
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
/*
#include<stdio.h>
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int temp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > temp)
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
			{
				break;//�ҵ�λ��
			}
		}
		arr[end + 1] = temp;
	}
}
int GetMid(int* arr,int left,int right)//����ȡ��
{
	int mid = (left + right) >> 1;
	if (arr[left] < arr[mid])
	{
		if (arr[mid] < arr[right])
		{
			return mid;
		}
		else if (arr[left] > arr[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else//arr[left] > arr[mid]
	{
		if (arr[mid] > arr[right])
		{
			return mid;
		}
		else if (arr[left] > arr[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
}
void QuickSort(int* arr, int left,int right)
{
	if (left >= right)return;

	int index = GetMid(arr, left, right);
	Swap(&arr[left], &arr[index]);//�����߼�����

	int begin = left, end = right;
	int pivot = begin;
	int key = arr[begin];
	while (begin < end)
	{
		//�ұ���С���������
		while (begin < end && arr[end] >= key)
		{
			--end;
		}
		arr[pivot] = arr[end];
		pivot = end;
		//����Ҵ󣬷����ұ�
		while (begin < end && arr[begin] <= key)
		{
			++begin;
		}
		arr[pivot] = arr[begin];
		pivot = begin;
	}
	pivot = begin;
	arr[pivot] = key;

	//С�����Ż�(�������ṹ��Խ����Ҷ�ӣ�������ֻ�Խ��(�������ÿ����ϴ�);β��ֱ��ʹ�ò�������)
	//���ʺ�ʹ�ö�����(ͬΪ�������ṹ)��ϣ������(�ʺϴ���������)
	if (pivot - 1 - left > 10)
	{
		QuickSort(arr, left, pivot - 1);
	}
	else
	{
		InsertSort(arr + left, pivot - 1 - left + 1);
	}
	if (right - pivot - 1 > 10)//��ֵ�������������е���
	{
		QuickSort(arr, pivot + 1, right);
	}
	else
	{
		InsertSort(arr + pivot + 1, right - pivot - 1 + 1);
	}
}
int main()
{
	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
	QuickSort(arr, 0 ,(int)(sizeof(arr) / sizeof(int))-1);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/



//����ָ�뷨
/*
#include<stdio.h>
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)return;

	int begin = left, end = right;
	int key = begin;
	while (begin < end)
	{
		while (begin < end && arr[end] >= arr[key])//��С
		{
			--end;
		}
		while (begin < end && arr[begin] <= arr[key])//�Ҵ�
		{
			++begin;
		}
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[begin], &arr[key]);

	QuickSort(arr, left, begin - 1);
	QuickSort(arr, begin + 1, right);
}
int main()
{
	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
	QuickSort(arr, 0, (int)(sizeof(arr) / sizeof(int)) - 1);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/



//ǰ��ָ�뷨
/*
#include<stdio.h>
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)return;

	int key = left;
	int cur = left, prev = left + 1;
	while (prev <= right)
	{
		if (arr[prev] < arr[key] && ++cur != prev)//���������彻��
		{
			Swap(&arr[prev], &arr[cur]);
		}
		++prev;
	}
	Swap(&arr[key], &arr[cur]);

	QuickSort(arr, left, cur - 1);
	QuickSort(arr, cur + 1, right);
}
int main()
{
	int arr[10] = { 10,9,8,7,4,3,2,1,6,5 };
	QuickSort(arr, 0, (int)(sizeof(arr) / sizeof(int)) - 1);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/


