//死循环
#include <stdio.h>
int main()
{
    int i = 0;
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    for (i = 0; i <= 12; i++)
    {
        arr[i] = 0;
        printf("hello bit\n");
    }
    return 0;
}
















/*
输入一个整数数组，实现一个函数，

来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，

所有偶数位于数组的后半部分。
*/
#include<stdio.h>
#include<stdlib.h>
void adjust(int* arr,int size)
{
        int begin = 0, end = size - 1;
        while (begin < end)
        {
                while (begin < end && *(arr + begin) % 2 == 1)//若为奇数，则向后寻找偶数
                {
                        ++begin;
                }
                while (begin < end && *(arr + end) % 2 == 0)//若为偶数，则向前寻找奇数
                {
                        --end;
                }
                if (begin < end)
                {
                        int temp = *(arr + begin);
                        *(arr + begin) = *(arr + end);
                        *(arr + end) = temp;
                }
        }
}
int main()
{
        int num = 0;
        scanf("%d", &num);
        int* arr = (int*)malloc(sizeof(int) * num);
        for (int i = 0; i < num; ++i)
        {
                scanf("%d", (arr + i));
        }
        adjust(arr, num);
        for (int i = 0; i < num; ++i)
        {
                printf("%d ", *(arr + i));
        }
        free(arr);
        arr = NULL;
        return 0;
}
















//模拟strcpy实现
#include<stdio.h>
#include<assert.h>
char* my_strcpy(char* dest, const char* src)
{
        assert(dest && src);
        char* ret = dest;
        while (*dest++ = *src++);
        return ret;
}
int main()
{
        char str1[] = "xxxxxxxxxxxxxxxxxx";
        char str2[] = "hello bjy";
        char* dest = my_strcpy(str1, str2);
        printf("%s\n", dest);
        printf("%s\n", str1);
        return 0;
}













//模拟strlen实现
#include<stdio.h>
#include<assert.h>
int my_strlen(const char* str)
{
        assert(str);
        int count = 0;
        while (*str++ != '\0')
        {
                ++count;
        }
        return count;
}
int main()
{
        char* test = "hahaha";
        int ret = my_strlen(test);
        printf("%d\n", ret);
        return 0;
}
















//最高分和最低分之差
#include<stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    printf("%d", max - min);
    return 0;
}















//有序序列判断
#include <stdio.h>
int judge(int* arr, int size)
{
    int flag = 0;
    if (arr[0] < arr[1])
        flag = 1;

    for (int i = 0; i < size - 1; ++i)
    {
        if (flag == 1)//升序
        {
            if (arr[i] > arr[i + 1])
                return 0;
        }
        if (flag == 0)//降序
        {
            if (arr[i] < arr[i + 1])
                return 0;
        }
    }
    return 1;
}
int main()
{
    int N = 0;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &arr[i]);
    }

    if (judge(arr, N))
    {
        printf("sorted\n");
    }
    else
    {
        printf("unsorted\n");
    }
    return 0;
}
















#include<stdio.h>
void Swap(int* a, int* b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}
int GetMid(int* arr, int left, int right)//三数取中
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
void QuickSort(int* arr, int left, int right)
{
        if (left >= right)return;

        int index = GetMid(arr, left, right);
        Swap(&arr[left], &arr[index]);

        int begin = left, end = right;
        int pivot = begin;
        int key = arr[begin];
        while (begin < end)
        {
                while (begin < end && arr[end] >= key)
                {
                        --end;
                }
                arr[pivot] = arr[end];
                pivot = end;
                while (begin < end && arr[begin] <= key)
                {
                        ++begin;
                }
                arr[pivot] = arr[begin];
                pivot = begin;
        }
        pivot = begin;
        arr[pivot] = key;

        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);

}
int main()
{
        int n = 0;
        int m = 0;
        int arr1[1000] = { 0 };
        int arr2[1000] = { 0 };
        //输入n和m
        scanf("%d %d", &n, &m);
        int i = 0;
        int j = 0;
        //输入两个升序序列
        for (i = 0; i < n; i++)
        {
                scanf("%d", &arr1[i]);
        }
        for (i = 0; i < m; i++)
        {
                scanf("%d", &arr2[i]);
        }

        int arr[1000] = { 0 };
        for (int i = 0; i < n; ++i)
        {
                arr[i] = arr1[i];
        }
        for (int i = 0; i < m; ++i)
        {
                arr[n + i] = arr2[i];
        }

        QuickSort(arr, 0, n + m - 1);

        for (int i = 0; i < n + m; ++i)
        {
                printf("%d ", arr[i]);
        }
        return 0;
}
