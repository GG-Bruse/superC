//算法效率分为时间效率(时间复杂度)和空间效率(空间复杂度)
//在实际开发中时间复杂度优先于空间复杂度 







/*
时间复杂度的概念:
一个算法所花费的时间与其中语句的执行次数呈正比。算法中的基本操作的执行次数为算法的时间复杂度。
*/


/*
计算时间复杂度: 
大O的渐进表示法(估算) 
1.用常数1代替运行时间中的所有加法常数 
2.在修改的运行次数的函数中，只保留最高阶项
3.若最高阶项存在且不是1，则去除与该项相乘的常数，得到大O阶 
 
大O符号:是用于描述函数渐进行为的数字符号 
*/ 


/*
例1:
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
1.其时间复杂度为O(m+n)
2.若m远大于n，则时间复杂度为O(m) 
3.若m、n大小相近，则时间复杂度为O(m)或O(n) 
*/ 


/*
例2：
void func(int n)
{
	int count = 0;
	for(int i = 0;i < 100;++i)
	{
		++count;
	}
	printf("%d\n",count);
}
其时间复杂度为O(1) 
*/ 


/*
例3：
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
若const char* str = "dadiefgicbie";(N)
当character为'x'时为最坏情况(N)
当character为'g'时为平均情况(N/2)
当character为'd'时为最好情况(1)

某些算法的时间复杂度存在三种情况:
最坏情况:任意输入规模的最大运行次数(上界)
平均情况:任意输入规模的期望运行次数
最好情况:任意输入规模的最小运行次数(下界)
在实际中一般情况关注的是算法的最坏运行情况，所以数组中搜索数据的时间复杂度为O(n) 
*/


/*
例4: 
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

第一趟冒泡:N-1 
第二趟冒泡:N-2
第三趟冒泡:N-3
…
第N趟冒泡:1 
其为等差数列,(首项+尾项)*项数/2 = 准确次数 （N-1+1）*N/2
其时间复杂度为O(N^2) 
*/


/*
例5:
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
假设查找了X次，即1*2^X = N
其时间复杂度为O(以2为底N的对数),简写成O(logN) 
*/


/*
例6:
阶乘: 
long long Factorial(size_t N)
{
	return N<2?N:Factorial(N-1)*N;
}
递归调用了N次,每次递归运算为O(1)
整体时间复杂度就是O(N) 
*/


/*
例七:
斐波那契递归:
long long Fibonacci(size_t N)
{
	return N<2?N:Fibonacci(N-1):Fibonacci(N-2);
} 
N-1分支和N-2分支每层可再分出两个分支。时间复杂度为O(2^N)
实际上由于N-1和N-2的变化速率不同，N-1分支的调用次数多于N-2分支。 
*/











/*
空间复杂度的概念:
空间复杂度是对一个算法在运行过程中临时占用存储空间大小的度量。(变量的个数) 
*/ 


/*
计算空间复杂度: 
同样使用大O的渐进表示法(估算)
*/ 


/*
例1:
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
其空间复杂度为O(1),变量个数为常数个 
*/ 


/*
例2: 
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
其空间复杂度为O(n) 
*/ 


/*
例3:
long long Factorial(size_t N)
{
	return N < 2?N:Factorial(N-1);
}
递归调用了N层,每次调用建立了一个栈帧，每个栈帧使用了常数个空间 
其空间复杂度为O(N) 
*/



