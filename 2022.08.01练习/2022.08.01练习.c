#include <stdio.h>
int main()
{
        int a, b, c;
        a = 5;
        c = ++a;
        b = ++c, c++, ++a, a++;
        b += a++ + c;
        printf("a = %d b = %d c = %d\n:", a, b, c);
        return 0;
}




#include<stdio.h>
int main()
{
        int a = 5,b = 7;
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        printf("%d %d", a, b);
        return 0;
}






#include<stdio.h>
int NumberOf1(int n)
{
    int count = 0;
    for (int i = 0; i < 32; ++i)
    {
        if (1 == ((n >> i) & 1))
            ++count;
    }
    return count;
}
int main()
{
    int num = 0;
    scanf("%d", &num);
    int ret = NumberOf1(num);
    printf("%d\n", ret);
    return 0;
}






#include<stdio.h>
int diff_bit(int m,int n)
{
    int ret = m ^ n;
    int count = 0;
    while (ret)
    {
        count++;
        ret = ret & (ret - 1);
    }
    return count;
}
int main()
{
    int num1 = 0,num2 = 0;
    scanf("%d%d", &num1,&num2);
    int ret = diff_bit(num1,num2);
    printf("%d\n", ret);
    return 0;
}








//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
#include<stdio.h>
int main()
{
    int num = 0;
    scanf("%d", &num);

        for (int i = 31; i >= 1; i -= 2)
        {
                printf("%d ", (num >> i) & 1);
        }
        printf("\n");

        for (int i = 30; i >= 0; i -= 2)
        {
                printf("%d ", (num >> i) & 1);
        }
        printf("\n");
    return 0;
}


#include <stdio.h>
int main()
{
    int RolCow = 0;
    scanf("%d", &RolCow);
    int arr[10][10] = { 0 };
    for (int i = 0; i < RolCow; ++i)
    {
        for (int j = 0; j < RolCow; ++j)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i < RolCow; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[i][j] != 0)
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}
