#include<stdio.h>
struct Student
{
        char name[20];
        int age;
        double hight;
};
int main()
{
        struct Student s = { .hight = 180.6,.age = 18 };
        printf("%s %d %0.1lf", s.name, s.age, s.hight);
        return 0;
}








#include<stdio.h>
struct student
{
        int m_age;
};
int main()
{
        int age = 0;
        scanf("%d", &age);
        struct student s = { .m_age = age };
        printf("%d\n", s.m_age);
        return 0;
}







/*喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。*/
#include<stdio.h>
int main()
{
        int money = 20;
        int count = 0;
        int empty_bottle = 0;
        while (money > 0)
        {
                --money;
                ++empty_bottle;
                ++count;
                if (empty_bottle >= 2)
                {
                        money += empty_bottle / 2;
                        empty_bottle %= 2;
                }
        }
        printf("可以喝%d瓶汽水\n", count);
        return 0;
}
