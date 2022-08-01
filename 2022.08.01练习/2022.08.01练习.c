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





#include<stdio.h>
int main()
{
    int year = 0, month = 0;
    while (scanf("%d%d", &year, &month) != EOF)
    {

        if (month == 2)
        {
            if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
            {
                printf("29\n");
                continue;
            }
            else
            {
                printf("28\n");
                continue;
            }
        }
        switch (month)
        {
        case 1:
        case 2:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31\n");
            break;
        default:
            printf("30\n");
            break;
        }
    }
    return 0;
}








#include<stdio.h>
int main()
{
    char temp = 0;
    while (scanf("%c", &temp) != EOF)
    {
        if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z'))
        {
            printf("%c is an alphabet.\n", temp);
        }
        else
        {
            printf("%c is not an alphabet.\n", temp);
        }
    }
    return 0;
}







#include<stdio.h>
int main()
{
    double val = 0.0;
    int month = 0, day = 0, coupon = 0;
    scanf("%lf%d%d%d", &val, &month, &day, &coupon);
    double discount = 0.0;

    if (month == 11)discount = 0.7;
    else discount = 0.8;

    double total = 0.0;
    if (coupon)
    {
        total = val * discount - 50;
    }
    else
    {
        total = val * discount;
    }
    if (total < 0)
    {
        total = 0.0;
    }
    printf("%0.2lf", total);
    return 0;
}





