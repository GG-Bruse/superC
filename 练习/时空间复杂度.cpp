//�㷨Ч�ʷ�Ϊʱ��Ч��(ʱ�临�Ӷ�)�Ϳռ�Ч��(�ռ临�Ӷ�)
//��ʵ�ʿ�����ʱ�临�Ӷ������ڿռ临�Ӷ� 







/*
ʱ�临�Ӷȵĸ���:
һ���㷨�����ѵ�ʱ������������ִ�д��������ȡ��㷨�еĻ���������ִ�д���Ϊ�㷨��ʱ�临�Ӷȡ�
*/


/*
����ʱ�临�Ӷ�: 
��O�Ľ�����ʾ��(����) 
1.�ó���1��������ʱ���е����мӷ����� 
2.���޸ĵ����д����ĺ����У�ֻ������߽���
3.����߽�������Ҳ���1����ȥ���������˵ĳ������õ���O�� 
 
��O����:��������������������Ϊ�����ַ��� 
*/ 


/*
��1:
void func(int m,int n)
{
	int count = 0;
	for(int i = 0;i < m;++i)
	{
 		++count;	
 	}
 	for(int j = 0;j < 0;++j)
 	{
		++count;
	}
	printf("%d\n",count);
}
1.��ʱ�临�Ӷ�ΪO(m+n)
2.��mԶ����n����ʱ�临�Ӷ�ΪO(m) 
3.��m��n��С�������ʱ�临�Ӷ�ΪO(m)��O(n) 
*/ 


/*
��2��
void func(int n)
{
	int count = 0;
	for(int i = 0;i < 100;++i)
	{
		++count;
	}
	printf("%d\n",count);
}
��ʱ�临�Ӷ�ΪO(1) 
*/ 


/*
��3��
const char* strchar(const char* str,char character)
{
	while(*str != '\0')
	{
		if(*str == character)
			return str;
		++str;
	}
	return NULL;
}
��const char* str = "dadiefgicbie";(N)
��characterΪ'x'ʱΪ����(N)
��characterΪ'g'ʱΪƽ�����(N/2)
��characterΪ'd'ʱΪ������(1)

ĳЩ�㷨��ʱ�临�Ӷȴ����������:
����:���������ģ��������д���(�Ͻ�)
ƽ�����:���������ģ���������д���
������:���������ģ����С���д���(�½�)
��ʵ����һ�������ע�����㷨�����������������������������ݵ�ʱ�临�Ӷ�ΪO(n) 
*/


/*
��4: 
BubbleSort:
#include <stdio.h>
void bubble_sort(int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
    {
		for (int j = 0; j < len - 1 - i; j++)
        {
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
         int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
         int len = (int) sizeof(arr) / sizeof(*arr);
         bubble_sort(arr, len);
         for (int i = 0; i < len; i++)
                 printf("%d ", arr[i]);
         return 0;
}

��һ��ð��:N-1 
�ڶ���ð��:N-2
������ð��:N-3
��
��N��ð��:1 
��Ϊ�Ȳ�����,(����+β��)*����/2 = ׼ȷ���� ��N-1+1��*N/2
��ʱ�临�Ӷ�ΪO(N^2) 
*/


/*
��5:
BinarySearch:
int BinarySearch(int* arr,int size,int target)
{
	int left = 0;
	int right = size - 1;
	while(left <= right)
	{
		int mid = left + ((right - left)>>1);
		if(arr[mid] > target)
		{
			right = mid-1;
		}
		else if(arr[mid] < target)
		{
			left = mid+1;	
		}
		else 
			return mid;	
	}
	return -1;
}
���������X�Σ���1*2^X = N
��ʱ�临�Ӷ�ΪO(��2Ϊ��N�Ķ���),��д��O(logN) 
*/


/*
��6:
�׳�: 
long long Factorial(size_t N)
{
	return N<2?N:Factorial(N-1)*N;
}
�ݹ������N��,ÿ�εݹ�����ΪO(1)
����ʱ�临�ӶȾ���O(N) 
*/


/*
����:
쳲������ݹ�:
long long Fibonacci(size_t N)
{
	return N<2?N:Fibonacci(N-1):Fibonacci(N-2);
} 
N-1��֧��N-2��֧ÿ����ٷֳ�������֧��ʱ�临�Ӷ�ΪO(2^N)
ʵ��������N-1��N-2�ı仯���ʲ�ͬ��N-1��֧�ĵ��ô�������N-2��֧�� 
*/











/*
�ռ临�Ӷȵĸ���:
�ռ临�Ӷ��Ƕ�һ���㷨�����й�������ʱռ�ô洢�ռ��С�Ķ�����(�����ĸ���) 
*/ 


/*
����ռ临�Ӷ�: 
ͬ��ʹ�ô�O�Ľ�����ʾ��(����)
*/ 


/*
��1:
BubbleSort:
void bubble_sort(int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
    {
		for (int j = 0; j < len - 1 - i; j++)
        {
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
��ռ临�Ӷ�ΪO(1),��������Ϊ������ 
*/ 


/*
��2: 
long long* Fibonacci(size_t n)
{
	if(n == 0)
		return NULL;
	long long* fibArray = (long long*)malloc((n+1)*sizeof(long long));
	fibArray[0] = 0;
	fibArray[1] = 1;
	for(int i = 2;i <= n; ++i)
	{
		fibArray[i] = fibArray[i-1]+fibArray[i-2];
	}
	return fibArray;
}
��ռ临�Ӷ�ΪO(n) 
*/ 


/*
��3:
long long Factorial(size_t N)
{
	return N < 2?N:Factorial(N-1);
}
�ݹ������N��,ÿ�ε��ý�����һ��ջ֡��ÿ��ջ֡ʹ���˳������ռ� 
��ռ临�Ӷ�ΪO(N) 
*/



