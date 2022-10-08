/*写一个函数打印arr数组的内容，不使用数组下标，使用指针。
arr是一个整形一维数组。*/
#include<stdio.h>
int main()
{
        int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
        int* parr = arr;
        for (int i = 0; i < 10; ++i)
        {
                printf("%d ", *(parr + i));
        }
        return 0;
}








//写一个函数，可以逆序一个字符串的内容。
#include<stdio.h>
#include<string.h>
void Reverse(char* str, int size)
{
    char* begin = str;
    char* end = &str[size - 1];
    while (begin <= end)
    {
        char temp = *begin;
        *begin = *end;
        *end = temp;
        ++begin;
        --end;
    }
}
int main()
{
    char str[10000] = { 0 };
    gets(str);
    Reverse(str, (unsigned int)strlen(str));
    printf("%s", str);
    return 0;
}




//打印菱形13行最大15列
#include<stdio.h>
#define N 7
int main()
{
        for (int i = 1; i <= N; i++)
        {
                for (int j = 0; j < N - i; j++)
                {
                        printf(" ");
                }
                for (int j = 0; j < 2 * i - 1; j++)
                {
                        printf("*");
                }
                printf("\n");
        }
        for (int i = 1; i <= N - 1; i++)
        {
                for (int j = 0; j < i; j++)
                {
                        printf(" ");
                }
                for (int j = 0; j < 2 * (N - 1 - i) + 1; j++)
                {
                        printf("*");
                }
                printf("\n");
        }
        return 0;
}



/*求出0～100000之间的所有“水仙花数”并输出。
“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数”。*/
#include <stdio.h>
#include <math.h>
int main()
{
        int i = 0;
        for (i = 1; i <= 100000; i++)
        {
                int tmp = i;
                int count = 0;
                int sum = 0;
                while (tmp)
                {
                        tmp /= 10;
                        count++;
                }
                tmp = i;
                while (tmp)
                {
                        sum += pow((tmp % 10), count);
                        tmp /= 10;
                }
                if (sum == i)
                {
                        printf("%d是水仙花数\n", i);
                }
        }
        return 0;
}



#include<stdio.h>
#include<stdlib.h>
int SumDataNum(int a, int N)
{
        int sum = 0;
        int num = 0;
        for (int i = 0; i < N; i++)
        {
                num = num * 10 + a;
                sum = sum + num;
        }
        return sum;
}
int main()
{
        int ret = SumDataNum(2, 5);
        printf("ret=%d", ret);
        return 0;
}
