#include "sort_.h"

void print_array(int *arr, int n)
// 打印数组
{
    if(n==0){
        printf("ERROR: Array length is ZERO\n");
        return;
    }
    printf("%d", arr[0]);
    for (int i=1; i<n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

void sort_array(int *arr, int n)
//  编程实现《选择排序算法》：将乱序序列arr转化为升序序列
//  函数参数：乱序整数数组（无重复元素） 数组长度
//  要求输出：调用print_array(int *arr, int n)输出前三次选择操作后的序列，以及最终的升序序列
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i,j;
    int min = 0;
    for(i = 0;i < n - 1;i++)//排序次数
    {
        min = i;
        for(j = i + 1;j < n;j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;//记录交换的元素下标值
            }
        }
        if(i != min)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        if(i < 3)
        {
            print_array(arr,n);
        }
    }
    print_array(arr,n);

    /********** End **********/
}




#include "sort_.h"

void print_array(int *arr, int n)
// 打印数组
{
    if(n==0){
        printf("ERROR: Array length is ZERO\n");
        return;
    }
    printf("%d", arr[0]);
    for (int i=1; i<n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}



void sort_array(int *arr, int n)
//  编程实现《冒泡排序算法》：将乱序序列arr转化为升序序列
//  函数参数：乱序整数数组arr 数组长度
//  要求输出：调用print_array(int *arr, int n)输出前三次冒泡操作后的序列，以及最终的升序序列
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for(int i = 0;i<n; ++i)
    {
        for(int j = 0;j < n - 1; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(i < 3)
        {
            print_array(arr,n);
        }
    }
    print_array(arr,n);
    /********** End **********/
}






#include <stdio.h>
void main()
{
    /*********  Begin  **********/
    int a,b;
    scanf("%d%d",&a,&b);
    int tempa = a;
    int tempb = b;
    int c;
	while (b > 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
    if(tempa < tempb)
    {
        int temp = tempa;
        tempa = tempb;
        tempb = temp;
    }
    printf("%d和%d的最大公约数是%d",tempa,tempb,a);
    /*********  End  **********/
}





#include <stdio.h>
void main()
{
    /*********  Begin  **********/
    int a,b;
    scanf("%d%d",&a,&b);
    int tempa = a;
    int tempb = b;
    int c;
	while (b > 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
    if(tempa < tempb)
    {
        int temp = tempa;
        tempa = tempb;
        tempb = temp;
    }
    printf("%d和%d的最大公约数是%d",tempa,tempb,a);
    /*********  End  **********/
}








#include <stdio.h>

void main()
{
    int a;
    scanf("%d",&a);
    if(a%3==0 && a%5==0 && a%7==0)
            printf("能被3、5、7同时整除");
    else if(a%3==0 && a%5==0)
            printf("能被3和5整除");
    else if(a%3==0 && a%7==0)
            printf("能被3和7整除");
    else if(a%5==0 && a%7==0)
            printf("能被5和7整除");
    else if(a%3==0)
            printf("能被3整除");
    else if(a%5==0)
            printf("能被5整除");
    else if(a%7==0)
            printf("能被7整除");
    else
            printf("不能被3、5、7中的任何一个整除");
}



