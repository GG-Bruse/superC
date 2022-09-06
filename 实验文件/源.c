#define _CRT_SECURE_NO_WARNINGS

















////for循环
//#include<stdio.h>
//int main()
//{
//    int i = 0;
//    int key = 1;
//    int sum = 0;
//    int n;
//    scanf("%d", &n);
//    for (i = 1; i <= n; i++)
//    {
//        key = key * i;//计算阶乘
//        sum = sum + key;//每个阶乘相加
//    }
//    printf("%d\n", sum);
//    return 0;
//}






////while循环
//#include<stdio.h>
//int main()
//{
//    int i = 1;
//    int key = 1;
//    int sum = 0;
//    int n;
//    scanf("%d", &n);
//    while (i <= n)
//    {
//        key = key * i;//计算阶乘
//        sum = sum + key;//每个阶乘相加
//        i++;
//    }
//    printf("%d\n", sum);
//    return 0;
//}




////do while循环
//#include<stdio.h>
//int main()
//{
//    int i = 1;
//    int key = 1;
//    int sum = 0;
//    int n;
//    scanf("%d", &n);
//    do
//    {
//        key *= i;
//        sum += key;
//        i++;
//    } while (i <= n);
//    
//    printf("%d\n", sum);
//    return 0;
//}








////将for循环封装为函数
//#include<stdio.h>
//int Factorial(int n);
//int main()
//{
//	int n;
//	int ret;
//	scanf("%d", &n);
//	ret=Factorial(n);
//	printf("%d\n", ret);
//	return 0;
//}
//int Factorial(int n)
//{
//	int i;
//	int temp=1;
//	int ret=0;
//	for (i = 1; i <= n; i++)
//	{
//		temp *= i;
//		ret += temp;
//	}
//	return ret;
//}





////函数归递
//#include<stdio.h>
//int Factorial(int n)//计算单个阶乘
//{
//	if (n <= 1)
//	{
//		return 1;
//	}                                                                                     
//	else
//	{	
//		return  n * Factorial(n - 1);
//	}
//}
//int FAC(int i)//计算各个阶乘相加
//{
//	int key=1;
//	int sum=0;
//	for (; i >= 1; i--)
//	{
//		key = Factorial(i);
//		sum += key;
//	}
//	return sum;
//}
//int main()
//{
//	int n;
//	int ret;
//	scanf("%d", &n);
//	ret=FAC(n);
//	printf("%d\n", ret);
//	return 0;
//}
//















//#include<stdio.h>
//#include<ctype.h>
//int main()
//{
//	int i;
//	int a=0;//英文字母
//	int b=0;//空格
//	int c=0;//数字
//	int d=0;//其他字符
//	char str[100] = {0};
//	gets(str);
//	for (i = 0; str[i] != '\0'; i++)
//	{
//		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
//		{
//			a++;
//		}
//		else if (str[i]==' ')
//		{
//			b++;
//		}
//		else if (isdigit(str[i]))
//		{
//			c++;
//		}
//		else
//		{
//			d++;
//		}
//	}
//	printf("有%d个英文字母\n",a);
//	printf("有%d个空格\n",b);
//	printf("有%d个数字\n",c);
//	printf("有%d个其他字符\n",d);
//	return 0;
//}




//#include<stdio.h>
//int main()
//{
//	int str[100] = {0};
//	int n;//有多少个数据
//	int i;
//	int j;
//	int temp;
//	printf("please input a number(small then 100)\n");
//	scanf("%d", &n);
//	printf("please input %d numbers\n",n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &str[i]);
//	}
//	for (i = 0; i < n-1; i++)
//	{
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (str[j] > str[j + 1])
//			{
//				temp = str[j];
//				str[j] = str[j+1];
//				str[j+1] = temp;
//			}
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%d", str[i]);
//	}
//	return 0;
//}











//#include <stdio.h>
//int main()
//{
//	int a[2][4], b[4][3], c[2][3];
//	int i, j, k, sum;
//
//	//输入矩阵a
//	printf("输入一个2×4的矩阵：\n");
//	for (i = 0; i < 2; i++)                    //行
//		for (j = 0; j < 4; j++)                //列
//			scanf("%d", &a[i][j]);  
//
//	//输入矩阵b
//	printf("输入一个4×3的矩阵；\n");
//	for (i = 0; i < 4; i++)                   //行
//		for (j = 0; j < 3; j++)               //列
//			scanf("%d", &b[i][j]);    
//
//	//对矩阵c进行处理
//	for (i = 0; i < 2; i++)                 
//	{
//		for (j = 0; j < 3; j++)
//		{
//			sum = 0;
//			for (k = 0; k < 4; k++)   //矩阵c中每一个元素的循环计算
//			{
//				sum += a[i][k] * b[k][j]; //对矩阵c中的某一元素进行计算
//			}        
//			c[i][j] = sum;     //给矩阵c中的某一元素进行赋值
//		}
//	}
//
//	//输出矩阵c
//	printf("得到一个2×3的矩阵：\n");
//	for (i = 0; i < 2; i++)            
//	{
//		for (j = 0; j < 3; j++)
//			printf("%5d", c[i][j]);
//		printf("\n");
//	}
//	return 0;
//}























////杨辉三角
//#include<stdio.h>
//#define ROW 6
//#define COL 11
//#define ROWS ROW+2
//#define COLS COL+2
//
//void Initarr(int arr[ROWS][COLS])
//{
//	int i, j;
//	for (i = 0; i < ROWS; i++)
//	{
//		for (j = 0; j < COLS; j++)
//		{
//			arr[i][j] = 0;
//		}
//	}
//}
//
//void Display(int arr[ROWS][COLS])
//{
//	int i, j;
//	for (i = 1; i <= ROW; i++)
//	{
//		for (j = 1; j <= COL; j++)
//		{
//			if (arr[i][j] != 0)
//			{
//				printf("%3d ", arr[i][j]);
//			}
//			else
//			{
//				printf("    ");
//			}
//		}
//		printf("\n");
//	}
//}
//
//void Handle(int arr[ROWS][COLS])
//{
//	int i, j;
//	arr[1][6] = 1;
//	for (i = 1; i <= ROW; i++)
//	{
//		for (j = 0; j <= COL; j++)
//		{
//			arr[i + 1][j + 1] = arr[i][j] + arr[i][j + 2];
//		}
//	}
//}
//
//int main()
//{
//	int showarr[ROWS][COLS];
//	char arr[ROWS][COLS];
//	//初始化
//	Initarr(showarr);
//	//处理
//	Handle(showarr);
//	//输出
//	Display(showarr);
//	return 0;
//}






















//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char s1[80] = {'1','2','3',' ','6'};
//	char s2[80] = "handsome";
//	printf("%s,%s\n", s1, s2);
//	return 0;
//}





//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char a[7] = "abcdef";
//	char b[4] = "ABC";
//	strcpy(a, b);
//	printf("%c",a[5]);
//
//	return 0;
//}




//#include<stdio.h>
//int main()
//{
//	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int i, j, sum=0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			sum = sum + a[i][j];
//		}
//	}
//	printf("%d\n", sum);
//	return 0;
//}







//#include<stdio.h>
//int main()
//{
//	int i, k = 0;
//	int a[] = { 31,50,15,27,37,23,69,82,52,15 };
//	for (i = 0; i < 10; i++)
//	{
//		if (a[k] < a[i]) k = i;
//
//	}
//	printf("m=%d,k=%d\n", a[k], k);
//	return 0;
//}




//#include<stdio.h>
//int main()
//{
//
//	int x[10] = { 1,2,3,4,5 };
//	int k;
//	for (k = 1; k < 3; k++)
//	{
//		x[0] = x[0] + x[k];
//	}
//	printf("x[0]=%d\n", x[0]);
//	return 0;
//}




//#include<stdio.h>
//int main()
//{
//	char str[] = "China";
//	printf("%d\n", sizeof(str));//6
//	return 0;
//}







//#include<stdio.h>
//int Factorial(int n)
//{
//	if (n == 0 || n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n* Factorial(n - 1);
//	}
//}
//int main()
//{
//	int n;
//	int ret;
//	printf("please input a number\n");
//	scanf("%d", &n);
//	ret = Factorial(n);
//	printf("%d的阶乘为%d\n", n, ret);
//	return 0;
//}











//#include<stdio.h>
//#define N 10
//int Factorial(int n)
//{
//	if (n == 0 || n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * Factorial(n - 1);
//	}
//}
//int sum(int n)
//{
//	int i;
//	int sum = 0;;
//	for (i = 1; i <= N; i++)
//	{
//		sum += Factorial(i);
//	}
//	return sum;
//}
//int main()
//{
//	int ret;
//	ret = sum(N);
//	printf("%d\n", ret);
//	return 0;
//}





                                                                   //练习

////计算n的阶乘
//#include<stdio.h>
//int main()
//{
//    int a = 1;
//    int n;
//    int key=1;
//    scanf("%d", &n);
//    for (a = 1; a <= n; a++)
//    {
//        key = key * a;
//    }
//    printf("key=%d\n", key);
//    return 0;
//}









//计算1！+2！+3!

//#include<stdio.h>
//int main()
//{
//    int a = 1;
//    int n = 0;
//    int key=1;
//    int sum = 0;
//    for (n = 1; n <= 3; n++)
//    {
//        key = 1;
//        for (a = 1; a <= n; a++)
//        {
//            key = key * a;
//        }
//        sum = sum + key;
//    }
//    printf("%d\n", sum);
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    int key = 1;
//    int sum = 0;
//    for (n = 1; n <= 3; n++)
//    {
//        key = key * n;//key=1 2 6
//        sum = sum + key;//sum=1 3 9
//    }
//    printf("%d\n", sum);
//    return 0;
//}








//在一个有序数组中查找具体的某个数字n

//#include<stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6,7,8,9 };
//    int k =7;//要找到的数字
//    int i = 0;
//    int bjy = sizeof(arr) / sizeof(arr[0]);//计算出数组中的元素个数：9个
//    for (i = 0; i < bjy; i++)
//    {
//        if (k == arr[i])
//        {
//            printf("找到了，下标是：%d\n", i);
//            break;
//        }
//    }
//    if (i == bjy)
//    {
//        printf("找不到了\n");
//    }
//    return 0;
//}

////折半查找算法(二分查找算法)——有序数据中可用
////案例(不完整)
//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//    int k =5;//要找的数据
//    int left = 0;//左下标
//    int a = sizeof(arr) / sizeof(arr[0]);//计算元素个数
//    int right = a - 1;//右下标
//    while (left <= right)
//    {
//        int mid = (right + left)/2;//下标中间数
//        if (arr[mid] > k)
//        {
//            right = mid - 1;
//            //……
//        }
//        else if (arr[mid] < k)
//        {
//            left = mid + 1;
//            //……
//        }
//        else//arr[mid]=k
//        {
//            printf("找到了，下标是：%d\n", mid);
//        }
//        return 0;
//    }
//    if (left > right)
//    {
//        printf("找不到了。\n");
//    }
//}









////编写代码演示多个字符从两端移动向中间汇聚
////############
////w##########!
////we########!!
////wel######!!!
////welc####y!!!
////……
////welcome to bjy!!!
//#include<stdio.h>
//#include<string.h>
//#include<windows.h>
//#include<stdlib.h>
//int main()
//{
//    char arr1[] = "welcome to bjy heart!!!";
//    char arr2[] = "#######################";
//    int left = 0;
//    //int right = (sizeof(arr1)/sizeof(arr1[0]))-1;
//    //错误"\0"
//    //int right = (sizeof(arr1) / sizeof(arr1[0])) - 2;//正确
//    int right = strlen(arr1) - 1; //正确写法
//
//    //逻辑部分
//    while(left<=right)
//    {
//        arr2[left] = arr1[left];
//        arr2[right] = arr1[right];
//        printf("%s\n", arr2);
//        Sleep(1000);//休息一千毫秒
//        //调用Sleep函数需引用 windows.h头文件
//        system("cls");//执行系统命令的函数——cls——清空屏幕
//        //调用system函数需引用 stdlib.h头文件
//        left++;
//        right--;
//    }
//    printf("welcome to bjy heart!!!");
//    return 0;
//}










////编写代码实现，模拟用户登录场景，并只能登录三次(输入密码正确则提示登录成功，三次均输入错误则退出程序)
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    int i = 0;
//    char input[20];
//    for (i = 0; i < 3; i++)
//    {
//        printf("请输入密码!\n");
//        scanf("%s", &input);
//        if (strcmp(input,"123456")==0)
//            //等号不能用来比较两个两个字符串是否相等
//            //应使用一个库函数——strcmp
//            //两个字符串相等返回0
//        {
//            printf("登录成功\n");
//            break;
//        }
//        else
//        {
//            printf("密码错误！\n");
//        }
//    }
//    if (i == 3)
//    {
//        printf("三次密码均错误！\n");
//    }
//    return 0;
//}










////8 10 12 14 16
//#include<stdio.h>
//int sum(int a)
//{
//    int c = 0;
//    static int b = 3;
//    c += 1;
//    b += 2;
//    return (a+b+c);
//}
//int main()
//{
//    int i;
//    int a = 2;
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d\n", sum(a));
//    }
//    return 0;
//}













////死循环打印5
//#include<stdio.h>
//int main()
//{
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        if (i = 5)//i赋值为5   错误
//        {
//            printf("%d\n", i);
//        }
//    }
//    return 0;
//}














////将三个数从大到小输出
//#include<stdio.h>
//int main()
//{
//    int a;
//    int b;
//    int c;
//    scanf("%d%d%d", &a, &b, &c);
//    printf("%d%d%d\n", a, b, c);
//    if (a > b)
//    {
//        if (a > c)
//        {
//            if (b > c)
//            {
//                printf("%d %d %d\n", a, b, c);
//            }
//            else
//            {
//                printf("%d %d %d\n", a, c, b);
//            }
//
//        }
//        else//a<c
//        {
//            printf("%d %d %d\n", c, a, b);
//        }
//    }
//    else//a<b
//    {
//        if (a < c)
//        {
//            if (b > c)
//            {
//                printf("%d %d %d\n", b, c, a);
//            }
//            else//b>c
//            {
//                printf("%d %d %d\n", c, b, a);
//            }
//        }
//        else//a<c
//        {
//            printf("%d %d %d\n", b, a, c);
//        }
//    }
//    return 0;
//}


//#include<stdio.h>
//int main()
//{
//    int a = 0;
//    int b = 0;
//    int c = 0;
//    int temp;
//    scanf("%d%d%d", &a, &b, &c);
//    if (a < b)
//    {
//        temp = a;
//        a = b;
//        b = temp;
//    }
//    if (a < c)
//    {
//        temp = a;
//        a = c;
//        c = temp;
//    }
//    if (b < c)
//    {
//        temp = b;
//        b = c;
//        c = temp;
//    }
//    printf("%d,%d,%d\n", a, b, c);//a中放最大值，b次之，c最小
//    return 0;
//}












////打印1-100中3的倍数
//#include<stdio.h>
//int main()
//{
//    int i;
//    for (i = 1; i <= 100; i++)
//    {
//        if (i % 3 == 0)
//        {
//            printf("%d\n", i);
//        }
//
//    }
//    return 0;
//}













////求两个数的最大公约数
////辗转相除法
//#include<stdio.h>
//int main()
//{
//    int a;
//    int b;
//    int c;
//    scanf("%d%d", &a, &b);
//    while (c=a % b)//为0停止循环
//    {
//        a = b;
//        b = c;
//    }
//    printf("%d\n", b);
//    return 0;
//}









////打印1000-2000年之间的闰年
////闰年—能被4整除但不能被100整除
////能被400整除是闰年
//#include<stdio.h>
//int main()
//{
//    int year;
//    int count = 0;
//    for (year = 1000; year <= 2000; year++)
//    {
//        if ((year % 4 == 0 && year % 100 != 0)||(year%400==0))
//        {
//            printf("%d是闰年\n", year);
//            count++;
//        }
//    }
//    printf("共有%d个闰年\n", count);
//    return 0;
//}













////打印100-200之间的素数

////素数—试除法—只有1和自身能够整除自己
//#include<stdio.h>
//int main()
//{
//    int i;
//    int count = 0;
//    for (i = 100; i <= 200; i++)
//    {
//        int j = 0;
//        for (j = 2; j < i; j++)
//        {
//            if (i % j == 0)
//            {
//                break;
//            }
//        }
//        if (j == i)
//        {
//            count++;
//            printf("素数是%d\n", i);
//        }
//    }
//    printf("素数有%d个\n",count);
//}


////算法优化版
////i=a*b   16=2*8=4*4
////a和b中至少有一个数字<=i的开平方
//#include<stdio.h>
//#include<math.h>//调用sqrt函数所需要引用的头文件
//int main()
//{
//    int i;
//    int j;
//    int count=0;
//    for (i = 101; i <= 200; i+=2)//每次加二跳过所有偶数
//    {
//        for (j = 2; j <=sqrt(i); j++)//sqrt—开平方的数学库函数
//        {
//            if (i % j == 0)
//            {
//                break;
//            }
//        }
//        if (j > sqrt(i))
//        {
//            count++;
//            printf("素数是%d\n", i);
//        }
//    }
//    printf("素数有%d个\n", count);
//    return 0;
//}












////编写一个代码计算1-100的整数之间有多少个数字9
//#include<stdio.h>
//int main()
//{
//    int i;
//    int count=0;
//    for (i = 1; i <= 100; i++)
//    {
//        if ( i / 10 == 9)
//        {
//            count++;
//        }
//        if (i % 10 == 9)
//        {
//            count++;
//        }
//    }
//    printf("共有%d个九\n", count);
//    return 0;
//}










//分数求和
////计算1/1-1/2+1/3-……+1/99-1/100

//#include<stdio.h>
//int main()
//{
//    double a;
//    double b;
//    double sum1=0;
//    double sum2=0;
//    double sum;
//    for (a = 1; a <= 99; a = a + 2)
//    {
//        sum1 = sum1 + (1/a);
//    }
//    for (b = 2; b <= 100; b += 2)
//    {
//        sum2 = sum2 + (1/b);
//    }
//    sum = sum1 - sum2;
//    printf("%f\n", sum);
//    return 0;
//}


//#include<stdio.h>
//int main()
//{
//    float i;
//    float sum=0;
//    float sign = 1;
//    for (i = 1; i <= 100; i++)
//    {
//        sum = sum + sign*(1 / i);
//        sign = -sign;//变换符号
//    }
//    printf("%f", sum);
//    return 0;
//}










////求十个整数中的最大值
//#include<stdio.h>
//int main()
//{
//    int arr[] = { -1,-2,-3,-4,-5,-6,-7,-8,-9,-10 };
//    int max = arr[0];
//    int i;
//    int x = sizeof(arr) / sizeof(arr[0]);//计算元素个数
//    for (i = 1; i < x; i++)
//    {
//        if (max < arr[i])
//        {
//            max = arr[i];
//        }
//    }
//    printf("最大值为%d\n", max);
//    return 0;
//}










////输出9*9的乘法口诀表
//#include<stdio.h>
//int main()
//{
//    int i, j;
//    for (i = 1; i <= 9; i++)
//    {
//        for (j = 1; j <= i; j++)
//        {
//            printf("%d*%d=%-2d ", i, j, i * j);
//        }
//        printf("\n");
//    }
//    return 0;
//}








////输入四门成绩，输出总分、平均分、最高分、最低分
//#include<stdio.h>
//int main()
//{
//    float arr[4], sum=0, p, max, min;
//    int i;
//    for (i = 0; i < 4; i++)
//    {
//        scanf("%f", &arr[i]);
//        sum += arr[i];
//    }
//    p = sum / (sizeof(arr) / sizeof(arr[0]));
//    printf("平均数为%.2f,总数为%.2f\n", p, sum);
//    max = min = arr[0];
//    for (i = 1; i < 4; i++)
//    {
//        if (arr[i] > max)
//        {
//            max = arr[i];
//        }
//        if (arr[i] < min)
//        {
//            min = arr[i];
//        }
//    }
//    printf("最大数为%.2f,最小数为%.2f\n", max, min);
//    return 0;
//}












////打印一个菱形
//#include<stdio.h>
//int main()
//{
//    int i, j, z;
//    for (i = 1; i<=6; i++)
//    {
//        for (j = 6; j >= i; j--)
//        {
//            printf(" ");
//        }
//        for (z = 1; z < 2*i; z++)
//        {
//            printf("*");
//        }
//        printf("\n");
//    }
//    for (i = 1; i <= 7; i++)
//    {
//        for (j = 1; j <i; j++)
//        {
//            printf(" ");
//        }
//        for (z = 16; z >=2*(i+1); z--)
//        {
//            printf("*");
//        }
//        printf("\n");
//    }
//    return 0;
//}










//猜数字游戏
//电脑生成一个随机数字1-100

//rand函数——调用stdlib.h头文件
//生成数字在0-32767之间
//但每次生成数字相同，需使用srand函数设置随机数的生成器

//srand——需调用stdlib.h头文件
//void srand(unsigned int seed);
//若要生成随机数括号中应输入一个随时变化的数(使用时间戳)

//需调用time.h头文件
//time()括号中所需参数类型为指针
//NULL空指针
//函数返回长整型，需强制转化为无符号整型
//时间戳-用于设置随机数的生成起始点
//当前计算机的时间减去计算机的起始时间(1970.1.1.0:0:0)=(xxx)秒

//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void menu()//菜单
//{
//    printf("********************************************\n");
//    printf("********    1. play     0.exit     *********\n");
//    printf("********************************************\n");
//}
//void game()
//{
//    int ret;
//    int guess;//接收猜的数字
//    printf("开始猜数字游戏\n");
//
//    ret =rand()%100+1;//rand-生成随机数
//    //%100后生成0-99的数字
//    
//    while (1)
//    {
//        printf("请猜数字：\n");
//        scanf("%d", &guess);
//        if (guess > ret)
//        {
//            printf("猜大了！\n");
//        }
//        else if (guess < ret) 
//        {
//            printf("猜小了\n");
//        }
//        else//guess==ret
//        {
//            printf("恭喜你猜对了\n");
//            break;
//        }
//    }
//}
//int main()
//{
//    int input;
//    srand((unsigned int)time(NULL));//设计随机数的生成起点 只需设置一次
//    do
//    {
//        menu();
//        printf("请选择:\n");
//        scanf("%d", &input);
//        switch (input)
//        {
//        case 0:
//            printf("退出游戏！\n");
//            break;
//        case 1:
//            game();//猜数字游戏
//            break;
//        default:
//            printf("输入错误！\n");
//        }
//    } while(input);
//    return 0;
//}












////输入一行字符，统计其中有多少个单词
//#include<stdio.h>
//int main()
//{
//    char str[100],c;
//    int i, word = 1;
//    gets(str);
//    for (i = 0; (c = str[i]) != '\0'; i++)
//    {
//        if (c == ' ')
//        {
//            word++;
//        }
//    }
//    printf("共有%d个单词\n", word);
//    return 0;
//}







////不能创建临时变量(第三个变量)，实现两个数的交换

//加减法—可计算的数的范围较小(可能会溢出)
//#include<stdio.h>
//int main()
//{
//    int a = 10;
//    int b = 20;
//    printf("before: a=%d b=%d\n", a, b);
//    a = a + b;
//    b = a - b;
//    a = a - b;
//    printf("after: a=%d b=%d\n", a, b);
//    return 0;
//}

//异或法
//#include<stdio.h>
//int main()
//{
//    int a = 10;
//    int b = 20;
//    a = a ^ b;//进行异或产生密码
//    b = a ^ b;//密码与其中一个数异或产生另一个数
//    a = a ^ b;
//    printf("a=%d,b=%d\n", a, b);
//
//    return 0;
//}







//编写代码：求一个整数存储在内存中的二进制的个数

////只能计算正数
//#include<stdio.h>
//int main()
//{
//    int num;
//    int count = 0;
//    scanf("%d", &num);
//    //统计num的补码中1的个数
//    while (num != 0)
//    {
//        if (num % 2 == 1)
//        {
//            count++;
//            num =num/ 2;
//        }
//    }
//    printf("%d\n", count);
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int num = 0;
//    int count=0;
//    int i = 0;
//    scanf("%d", &num);
//    //若num&1==1,那么num的补码的最后一位一定是1
//    //000000000000000001
//    for (i=0;i<32;i++)
//    {
//        if (((num >> i) & 1) == 1)
//        {
//            count++;
//        }
//    }
//    printf("%d\n", count);
//    return 0;
//}




////发生整型提升
//#include<stdio.h>
//int main()
//{
//    char a = -1;//-1
//    signed char b = -1;//-1
//    unsigned char c = -1;//255
//    printf("a=%d,b=%d,c=%d\n", a, b, c);
//    return 0;
//}








//#include<stdio.h>
//int main()
//{
//    char a = -128;
//    char b = 128;//127+1
//    printf("%u\n", a);
//    printf("%u\n", b);
//    return 0;
//}



















//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    char str1[100];
//    char str2[100];
//    char str3[100];
//    int ret1;
//    int ret2;
//    int ret3;
//    gets(str1);
//    gets(str2);
//    gets(str3);
//    ret1 = strcmp(str1, str2);
//    ret2 = strcmp(str2, str3);
//    ret3 = strcmp(str1, str3);
//    if (ret1>0)//str1>str2
//    {
//        if (ret2 > 0)//str2>str3
//        {
//            puts(str3);
//            puts(str2);
//            puts(str1);
//        }
//        else//str2<=str3
//        {
//            if (ret3 > 0)//str1>str3
//            {
//                puts(str2);
//                puts(str3);
//                puts(str1);
//            }
//            else//str1<=str3
//            {
//                puts(str2);
//                puts(str1);
//                puts(str3);
//            }
//        }
//    }
//    else//str1<=str2
//    {
//        if (ret2 > 0)//str2>str3
//        {
//            if (ret3 > 0)//str1>str3
//            {
//                puts(str3);
//                puts(str1);
//                puts(str2);
//            }
//            else//str1<=str3
//            {
//                puts(str1);
//                puts(str3);
//                puts(str2);
//            }
//        }
//        else//str2<=str3
//        {
//            puts(str1);
//            puts(str2);
//            puts(str3);
//        }
//    }
//    return 0;
//}




////在大部分情况下，数组名即首元素的地址
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    char str[3][100];
//    int ret1;
//    int ret2;
//    int ret3;
//    gets(&str[0][0]);
//    gets(&str[1][0]);
//    gets(&str[2][0]);
//    ret1 = strcmp(&str[0][0], &str[1][0]);
//    ret2 = strcmp(&str[1][0], &str[2][0]);
//    ret3 = strcmp(&str[0][0], &str[2][0]);
//    if (ret1 > 0)
//    {
//        if (ret2 > 0)
//        {
//            puts(&str[2][0]);
//            puts(&str[1][0]);
//            puts(&str[0][0]);
//        }
//        else
//        {
//            if (ret3 > 0)
//            {
//                puts(&str[1][0]);
//                puts(&str[2][0]);
//                puts(&str[0][0]);
//            }
//            else
//            {
//                puts(&str[1][0]);
//                puts(&str[0][0]);
//                puts(&str[2][0]);
//            }
//        }
//    }
//    else
//    {
//        if (ret2 > 0)
//        {
//            if (ret3 > 0)
//            {
//                puts(&str[2][0]);
//                puts(&str[0][0]);
//                puts(&str[1][0]);
//            }
//            else
//            {
//                puts(&str[0][0]);
//                puts(&str[2][0]);
//                puts(&str[1][0]);
//            }
//        }
//        else
//        {
//            puts(&str[0][0]);
//            puts(&str[1][0]);
//            puts(&str[2][0]);
//        }
//    }
//    return 0;
//}



//#include<stdio.h>
//int f(int n)
//{
//    if (n == 1) return 1;
//    else return f(n - 1) + n;
//}
//int main()
//{
//    int i, sum = 0;
//    for (i = 1; i <= 3; i++) sum += f(i);
//    printf("%d\n",sum);
//    return 0;
//}




//#include<stdio.h>
//int w = 3;
//int fun(int k)
//{
//    if (k == 0) return w;
//    return (fun(k - 1) * k);
//}
//int main()
//{
//    int w = 10;
//    printf("%d\n", fun(5) * w);
//    return 0;
//}




//#include<stdio.h>
//void func1(int i);
//void func2(int i);
//char st[] = "hello,friend!";
//void func1(int i)
//{
//    printf("%c", st[i]);
//    if (i < 3) { i += 2; func2(i); }
//}
//void func2(int i)
//{
//    printf("%c", st[i]);
//    if (i < 3) { i += 2; func1(i); }
//}
//int main()
//{
//    int i = 0;
//    func1(i);
//    printf("\n");
//    return 0;
//}







//#include<stdio.h>
//int fun(int n)
//{
//    if (n == 1) return 1;
//    else return n + fun(n - 1);
//}
//int main()
//{
//    int x;
//    scanf("%d", &x);
//    x = fun(x);
//    printf("%d\n", x);
//    return 0;
//}






//#include<stdio.h>
//int fun(int n)
//{
//    int s;
//    if (n == 1 || n == 2) s = 2;
//    else s = n + fun(n - 1);
//    return (s);
//}
//int main()
//{
//    int x;
//    x = fun(4);
//    printf("%d\n", x);
//    return 0;
//}






//#include<stdio.h>
//int power(int x, int n)
//{
//    int p;
//    if (n > 0) p = power(x, n - 1) * x;
//    else p = 1;
//    return p;
//}
//int main()
//{
//    int x = 2, n = 4;
//    printf("%d\n", power(x, n));
//    return 0;
//}




//#include<stdio.h>
//int fib(int n)
//{
//    switch (n)
//    {
//    case 0:return 0;
//    case 1:
//    case 2:return 1;
//    }
//    return (fib(n - 1) + fib(n - 2));
//}
//int main()
//{
//    int k;
//    k = fib(6);
//    printf("%d\n", k);
//    return 0;
//}








//#include<stdio.h>
//void reverse(int a[], int n)
//{
//    int i, t;
//    for (i = 0; i < n / 2; i++)
//    {
//        t = a[i]; a[i] = a[n - 1 - i]; a[n - 1 - i] = t;
//    }
//}
//int main()
//{
//    int b[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    int i, s = 0;
//    reverse(b, 8);
//    for (i = 6; i < 10; i++)
//    {
//        s += b[i];
//    }
//    printf("%d\n", s);
//    return 0;
//}





//#include<stdio.h>
//int f1();
//int i = 5;
//int main()
//{
//    int i = 3;
//    {int i = 10; i++; }
//    i = f1();
//    i += 1;
//    printf("%d\n", i);
//}
//int f1()
//{
//    i = i + 1;
//    return (i);
//}





//#include<stdio.h>
//int a, b;
//void fun()
//{
//    a = 100;
//    b = 200;
//}
//int main()
//{
//    int a = 5, b = 7;
//    fun();
//    printf("%d %d\n", a, b);
//    return 0;
//}





//#include<stdio.h>
//int x = 3;
//void incre()
//{
//    static int x = 1;
//    x *= x + 1;
//    printf("%d", x);
//}
//int main()
//{
//    int i;
//    for (i = 1; i < x; i++)
//    {
//        incre();
//    }
//    return 0;
//}









//#include<stdio.h>
//int a = 3;
//int main()
//{
//    int s = 0;
//    {int a = 5; s += a + 1; }
//    s += a + 1;
//    printf("%d\n", s);
//    return 0;
//}





//#include<stdio.h>
//int fun3(int x)
//{
//    static int a = 3;
//    a += x;
//    return (a);
//}
//int main()
//{
//    int k = 2, m = 1, n;
//    n = fun3(k);
//    n = fun3(m);
//    printf("%d\n", n);
//    return 0;
//}





//#include<stdio.h>
//int m = 13;
//int fun2(int x, int y)
//{
//    int m = 3;
//    return (x * y - m);
//}
//int main()
//{
//    int a = 7, b = 5;
//    printf("%d\n", fun2(a, b) / m);
//    return 0;
//}








//#include<stdio.h>
//#define N 2
//#define M N+1
//#define NUM 2*M+1
//int main()
//{
//    int i;
//    for (i = 1; i <= NUM; i++)
//    {
//        printf("%d\n", i);
//    }
//    return 0;
//}




//#include<stdio.h>
//#define MIN(X,Y) (X)<(Y)?(X):(Y)
//int main()
//{
//    int i, j, k;
//    i = 10, j = 15;
//    k = 10 * MIN(i,j);
//    printf("%d\n", k);
//    return 0;
//}



//#include<stdio.h>
//#define MA(X) X*(X-1)
//int main()
//{
//    int a = 1, b = 2;
//    printf("%d\n",MA(1 + a + b));
//    return 0;
//}





//#include<stdio.h>
//#define SQR(X) X*X
//int main()
//{
//    int a = 14, k = 2, m = 1;
//    a /= SQR(k + m) / SQR(k + m);
//    printf("%d\n", a);
//    return 0;
//}





//#include<stdio.h>
//void sub(int x, int y, int *z)
//{
//    *z = x - y;
//}
//int main()
//{
//    int a, b, c;
//    sub(10, 5, &a);
//    sub(7, a, &b);
//    sub(a, b, &c);
//    printf("%d,%d,%d\n", a, b, c);
//    return 0;
//}







//#include<stdio.h>
//void prtv(int* x)
//{
//    ++* x;
//}
//int main()
//{
//    int a = 25;
//    prtv(&a);
//    printf("%d\n", a);
//    return 0;
//}





//#include<stdio.h>
//#include<string.h>
//void f(char* s, int n)
//{
//    char a, * q1, * q2;
//    for (q1 = s, q2 = s + n - 1; q1 < q2; q1++, q2--)
//    {
//        a = *q1;
//        *q1 = *q2;
//        *q2 = a;
//    }
//}
//int main()
//{
//    char b[] = "ABCDEFG";
//    f(b, strlen(b));
//    puts(b);
//
//    return 0;
//}







//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    char str1[100];
//    char str2[100];
//    char str3[100];
//    int ret1;
//    int ret2;
//    int ret3;
//    gets(str1);
//    gets(str2);
//    gets(str3);
//    ret1 = strcmp(str1, str2);
//    ret2 = strcmp(str2, str3);
//    ret3 = strcmp(str1, str3);
//    if (ret1 > 0)//str1>str2
//    {
//        if (ret2 > 0)//str2>str3
//        {
//            puts(str3);
//            puts(str2);
//            puts(str1);
//        }
//        else//str2<=str3
//        {
//            if (ret3 > 0)//str1>str3
//            {
//                puts(str2);
//                puts(str3);
//                puts(str1);
//            }
//            else//str1<=str3
//            {
//                puts(str2);
//                puts(str1);
//                puts(str3);
//            }
//        }
//    }
//    else//str1<=str2
//    {
//        if (ret2 > 0)//str2>str3
//        {
//            if (ret3 > 0)//str1>str3
//            {
//                puts(str3);
//                puts(str1);
//                puts(str2);
//            }
//            else//str1<=str3
//            {
//                puts(str1);
//                puts(str3);
//                puts(str2);
//            }
//        }
//        else//str2<=str3
//        {
//            puts(str1);
//            puts(str2);
//            puts(str3);
//        }
//    }
//    return 0;
//}


















//#include<stdio.h>
//#include<string.h>
//char* compare(char *p1,char *p2)//返回小的
//{
//    char* ps1 = p1;
//    char* ps2 = p2;
//    while (*p1 != '\0' && *p2 != '\0')
//    {
//        if (*p1 <*p2)
//        {
//            return ps1;
//        }
//        else if(*p1>*p2)
//        {
//            return ps2;
//        }
//        else
//        {
//            p1++;
//            p2++;
//        }
//    }
//    return ps1;
//}
//int main()
//{
//    char str1[100];
//    char str2[100];
//    char str3[100];
//    char *p1;
//    char *p2;
//    char *p3;
//    gets(str1);
//    gets(str2);
//    gets(str3);
//    p1=compare(str1,str2);//2
//    p2=compare(str1, str3);//3
//    p3 = compare(str2, str3);//3
//    if (p1 == p2)//str1为最小
//    {
//        puts(str1);;
//        puts(p3);
//        if (p3 == str2)
//        {
//            puts(str3);
//        }
//        else
//        {
//            puts(str2);
//        }
//    }
//    if (p2 == p3)//str3为最小
//    {
//        puts(str3);
//        puts(p1);
//        if (p1 == str1)
//        {
//            puts(str2);
//        }
//        else
//        {
//            puts(str1);
//        }
//    }
//    if (p1 == p3)//str2为最小
//    {
//        puts(str2);
//        puts(p2);
//        if (p2 == str1)
//        {
//            puts(str3);
//        }
//        else
//        {
//            puts(str1);
//        }
//    }
//    return 0;
//}


























//#include<stdio.h>
//char* compare(char* p1, char* p2)//返回小的
//{
//    char* ps1 = p1;
//    char* ps2 = p2;
//    while (*p1 != '\0' && *p2 != '\0')
//    {
//        if (*p1 < *p2)
//        {
//            return ps1;
//        }
//        else if (*p1 > *p2)
//        {
//            return ps2;
//        }
//        else
//        {
//            p1++;
//            p2++;
//        }
//    }
//    return ps1;
//}
//int main()
//{
//
//    char str1[100];
//    char str2[100];
//    gets(str1);
//    gets(str2);
//    char* p = compare(str1, str2);
//    puts(p);
//    return 0;
//}









#include<stdio.h>
//void bubble_sort()
//{
//
//}
//int main()
//{
//    char str[100][10];
//    char (*pstr)[10] =str;
//    int i = 0;
//    int n;
//    printf("please input number\n");
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        scanf("%s",&str[i][10]);
//    }
//    bubble_sort(arr,);
//    return 0;
//}





//#include<stdio.h>
//#include<string.h>
//void Swap(char* buf1, char* buf2)
//{
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        char temp = *buf1;
//        *buf1 = *buf2;
//        *buf2 = temp;
//        buf1++;
//        buf2++;
//    }
//}
//void f(char* s[], int n)
//{
//    int i, j;
//    for (i = 0; i < n-1 ; i++)
//    {
//        for (j = 0; j < n - i; j++)
//        {
//            if (strcmp( s[j], s[j + 1] )> 0 )
//            {
//                Swap(s[j],s[j+1]);
//            }
//        }
//    }
//}
//int main()
//{
//    char str[100][10] = {0};
//    char* pstr[100];
//    int i, n;
//    printf("please input number\n");
//    scanf("%d", &n);
//    for (i = 0; i < 100; i++)
//        pstr[i] = str[i];
//    for (i = 0; i < n; i++)
//    {
//        scanf("%s",&str[i][10]);
//    }
//    f(pstr, n);
//    for (i = 0; i < n; i++)
//    {
//        puts(&str[i][10]);
//    }
//    return 0;
//}












//#include <stdio.h>
//void Printdeal(double arr[20][7], int n)
//{
//    int i, j;
//    double sum = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 1; j < 6; j++)
//        {
//            sum += arr[i][j];
//        }
//        arr[i][6] = sum / 5;
//        sum = 0;
//    }
//    printf("-------------------------------------------------------\n");
//    printf("   学号   | 英语 | 数学 | C++  | 音乐 | 美术 | 平均值 \n");
//    for (i = 0; i < n ; i++)
//    {
//        for (j = 0; j < 7; j++)
//            if (j < 6)
//                printf("%.0lf  |  ", arr[i][j]);
//            else
//                printf("%.1lf  ", arr[i][j]);
//        printf("\n");
//    }
//}
//void PrintPj(double*p, int n)
//{
//    int i;
//    double sum;
//    double *pa = p;
//    for (i = 1; i < 6; i++)
//    {
//        for (pa++,sum = 0; pa <= p + (n - 1) * 7 + i; pa += 7)
//            sum += *pa;
//        *pa = sum / n +0.000001;
//        pa -= n * 7;
//    }
//    printf(" 平均成绩 | ");
//    for (pa = p+n*7+1 ; pa<p+n*7+6; pa++)
//    {
//                printf("%.1lf | ", *pa);
//    }
//    printf("\n-------------------------------------------------------\n");
//}
//int main()
//{
//    double stu[20][7];
//    double* p = stu[0];
//    int i, j, n;
//    printf("学生有:");
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//        for (j = 0; j < 6; j++)
//            scanf("%lf", &stu[i][j]);
//    Printdeal(stu, n);
//    PrintPj(p,n);
//    return 0;
//}























































//p90t1
//#include<stdio.h>
//int main()
//{
//    float sl, xl;
//    float high;
//    float s;
//    printf("请输入你所要计算梯形的上下底边长:");
//    scanf("%f%f", &sl, &xl);
//    printf("输入梯形的高：");
//    scanf("%f", &high);
//    s = (sl + xl) * high / 2;
//    printf("梯形的面积为%.2f\n", s);
//    return 0;
//}








//p90t2
//#include<stdio.h>
//int main()
//{
//    char e;
//    printf("please input a Englsh word:");
//    scanf("%c", &e);
//    if (e >= 65 && e <= 90)
//    {
//        e = e + 32;
//    }
//    else if (e >= 97 && e <= 122)
//    {
//        e = e - 32;
//    }
//    printf("%c\n", e);
//    return 0;
//}





//p90t3
//#include<stdio.h>
//int main()
//{
//    int i = 0;
//    float arr[4];
//    float sum = 0, avg;
//    float  max, min;
//    for (i = 0; i < 4; i++)
//    {
//        scanf("%f", &arr[i]);
//        sum += arr[i];
//    }
//    avg = sum / 4;
//    max = arr[0];
//    min = arr[0];
//    for (i = 0; i < 4; i++)
//    {
//        if (arr[i] > max)
//        {
//            max = arr[i];
//        }
//        if (arr[i] < min)
//        {
//            min = arr[i];
//        }
//    }
//    printf("四科总分为%.2f\n", sum);
//    printf("四科平均分为%.2f\n", avg);
//    printf("四科最低分为%.2f\n", min);
//    printf("四科最高分为%.2f\n", max);
//    return 0;
//}





//#include<stdio.h>
//int main()
//{
//    int n, m;
//    int j, t;
//    printf("输入鸡和兔的总数量:");
//    scanf("%d", &n);
//    printf("输入鸡和兔的总脚数:");
//    scanf("%d", &m);
//    t = (m - 2 * n) / 2;
//    j = n - t;
//    if ((m - 2 * n) % 2 == 0&& m<=4*n)
//    {
//        printf("鸡的数量为%d\n", j);
//        printf("兔的数量为%d\n", t);
//    }
//    else
//    {
//        printf("no answear\n");
//    }
//    return 0;
//}
//
//






//p90t5
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//    int a, b, c;
//    scanf("%d%d%d", &a, &b, &c);
//    if (a + b > c && a + c > b && b + c > a)
//    {
//        if ( pow(a,2) +pow(b,2) ==pow(c,2)||pow(a,2)+pow(c,2)==pow(b,2)||pow(b,2)+pow(c,2)==pow(a,2))
//        {
//            printf("yes\n");
//        }
//        else
//        {
//            printf("no\n");
//        }
//    }
//    else
//    {
//        printf("not a traingle\n");
//    }
//    return 0;
//}







//p90t11
//#include<stdio.h>
//int main()
//{
//    int n, i, j;
//    int sum = 0;
//    scanf("%d", &n);
//    for (i = 2; i <= n; i++)
//    {
//        for (sum=0,j = 1; j < i; j++)
//        {
//            if (i % j == 0)
//            {
//                sum += j;
//            }
//        }
//        if (sum == i)
//        {
//            printf("完数有%d\n", i);
//        }
//    }
//    return 0;
//}












//p90t12
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//    int a, b, i, j;
//    int flag;
//    scanf("%d%d", &a, &b);
//    for (i = a; i < b; i++)
//    {
//        flag = 1;
//        for (j = 2; j <= sqrt(i); j++)
//        {
//            if (i % j == 0)
//            {
//                flag = 0;
//            }
//        }
//        if (flag != 0)
//        {
//            printf("素数有%d\n", i);
//        }
//    }
//    return 0;
//}







//p90t13
//#include<stdio.h>
//int main()
//{
//    float a, b, ret;
//    char c[2];
//    printf("请输入两个运算数:");
//    scanf("%f%f", &a, &b);
//    printf("请输入运算符:");
//    scanf("%s", c);
//    switch (c[0])
//    {
//    case 43:
//        ret = a + b;
//        break;
//    case 45:
//        ret = a - b;
//        break;
//    case 42:
//        ret = a * b;
//        break;
//    case 47:
//        ret = a / b;
//    }
//    printf("运算结果为%.2f\n", ret);
//    return 0;
//}





//p90t14
//#include<stdio.h>
//#define T 8
//void fun(int nr, int nw, int nb)
//{
//	int i, j, k, count = 0;
//	for (i = 1; i <= nr; i ++)
//	{
//		for (j = 1; j <= nw; j ++)
//		{
//			k = T - i - j;
//			if (k <= nb) count ++;
//			printf("第%d种情况:红球:%d,白球:%d,黑球:%d\n", count, i, j, k);
//		}
//	}
//}
//int main()
//{
//	int nr = 3, nw = 5, nb = 6;
//	fun(nr, nw, nb);
//	return 0;
//}





//p90t15
//#include<stdio.h>
//int main()
//{
//    int i, j;
//    int sum = 0;
//    for (i = 0; i <= 50; i++)
//    {
//        for (j = 0; j <= 20; j++)
//        {
//            if (100 - 2 * i - 5 * j >= 0)
//            {
//                printf("1分%3d个  2分%3d个   5分%3d个\n", 100 - 2 * i - 5 * j, i, j);
//            }
//        }
//    }
//    return 0;
//}



























//p129t1
//#include<stdio.h>
//int search(char s[10], char m)
//{
//    int i;
//    int flag = -1;
//    for (i = 0; i < 10; i++)
//    {
//        if (s[i] == m)
//        {
//            flag = i;
//        }
//    }
//    return flag;
//}
//int main()
//{
//    char s[10] = { 'a','b','c','d','e','f','g','h','i','j'};
//    char m = 'g';
//    int i;
//    i = search(s, m);
//    if (i == -1)
//    {
//        printf("未找到\n");
//    }
//    else
//    {
//        printf("下标为%d\n", i);
//    }
//    return 0;
//}












//p129t2
//#include<stdio.h>
//int main()
//{
//    int arr[100] = { 1,2,3,4,5,6,7,8,9,10 };
//    int n, i, j;
//    scanf("%d", &n);
//    arr[10] = n;
//    for (i = 0; i < 11 - 1; i++)
//    {
//        for (j = 0; j <11 - 1 - i; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//    for (i = 0; i < 11; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}



//p129t3
//#include<stdio.h>
//void del(int a[], int n, int x)
//{
//    int i, j;
//    for (i = 0; i < n; i++)
//    {
//        if (a[i] == x)
//        {
//            for (j = i; j < n; j++)
//            {
//                int temp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = a[j];
//            }
//        }
//    }
//    a[n - 1] = 0;
//    for (i = 0; i < n - 1; i++)
//    {
//        printf("%d ", a[i]);
//    }
//}
//int main()
//{
//    int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    int x = 6;
//    int n = 10;
//    del(a, n, x);
//    return 0;
//}















//p130t4
//#include<stdio.h>
//void huiwen(int n)
//{
//	int s, y = 0;
//	s = n;
//	while (s > 0)
//	{
//		y = s % 10 + y * 10;
//		s = s / 10;
//	}
//	if (y == n)
//	{
//		printf("%d是回文数", n);
//	}
//	else 
//	{
//		printf("%d不是回文数", n);
//	}
//}
//int main() 
//{
//	int n;
//	printf("请输入所要进行判断的数字:");
//	scanf("%d", &n);
//	huiwen(n);
//}













//p130t5
//#include <stdio.h>
//int main()
//{
//    int a, b, i, j, k;
//    scanf("%d%d", &a, &b);
//    for (i = a; i <= b; i++)
//    {
//        for (j = i + 1; j <= b; j++)
//        {
//            for (k = j + 1; k <= b; ++k)
//            {
//                if (i * i + j * j == k * k)
//                {
//                    printf("[%d,%d,%d]\n", i, j, k);
//                }
//            }
//        }
//    }
//    return 0;
//}

















//p162t4
//#include<stdio.h>
//int main()
//{
//    int n, sum1 = 0, sum2 = 0;
//    int arr[100][100];
//    scanf("%d", &n);
//    int i, j;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            scanf("%d", &arr[i][j]);
//            if (i == j)
//            {
//                sum1 += arr[i][j];
//            }
//            if (i + j + 1 == n)
//            {
//                sum2 += arr[i][j];
//            }
//        }
//    }
//    printf("%d %d", sum1, sum2);
//    return 0;
//}
//











//p162t6
//#include<stdio.h>
//int main()
//{
//    int arr[100];
//    int i;
//    int a = 0, b = 0, c = 0, d = 0, e = 0;
//    for (i = 0; i < 100; i++)
//    {
//        scanf("%d", &arr[i]);
//        arr[i] <= 59 ? (a++):
//    }
//    return 0;
//}

















//p209t3
//#include<stdio.h>
//void f(char* s1, char* s2, char* s3)
//{
//    char* flag = s3;
//    while (*s1 != '\0')
//    {
//        *s3 = *s1;
//        s1++;
//        s3++;
//    }
//    while (*s2 != '\0')
//    {
//        *s3 = *s2;
//        s2++;
//        s3++;
//    }
//    *s3 = '\0';
//    s3 = flag;
//}
//int main()
//{
//    char str1[1000];
//    char str2[1000];
//    char str3[1000];
//    char* p1 = str1;
//    char* p2 = str2;
//    char* p3 = str3;
//    gets(str1);
//    gets(str2);
//    f(p1, p2, p3);
//    for (; *p3 != '\0'; p3++)
//    {
//        printf("%c", *p3);
//    }
//    return 0;
//}





















//p210t4
//#include <stdio.h>
//void Printdeal(double arr[20][7], int n)
//{
//    int i, j;
//    double sum = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 1; j < 6; j++)
//        {
//            sum += arr[i][j];
//        }
//        arr[i][6] = sum / 5;
//        sum = 0;
//    }
//    for (i = 0; i < n ; i++)
//    {
//        for (j = 0; j < 7; j++)
//        {
//            if (j < 6)
//                printf("%.0lf     ", arr[i][j]);
//            else
//                printf("%.1lf  ", arr[i][j]);
//        }
//        printf("\n");
//    }
//}
//void PrintPj(double*p, int n)
//{
//    int i;
//    double sum;
//    double *pa = p;
//    for (i = 1; i < 6; i++)
//    {
//        for (pa++,sum = 0; pa <= p + (n - 1) * 7 + i; pa += 7)
//            sum += *pa;
//        *pa = sum / n +0.000001;
//        pa -= n * 7;
//    }
//    for (pa = p+n*7+1 ; pa<p+n*7+6; pa++)
//    {
//                printf("%.1lf   ", *pa);
//    }
//}
//int main()
//{
//    double stu[20][7];
//    double* p = stu[0];
//    int i, j, n;
//    printf("学生有:");
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//        for (j = 0; j < 6; j++)
//            scanf("%lf", &stu[i][j]);
//    Printdeal(stu, n);
//    PrintPj(p,n);
//    return 0;
//}
//
//










//p210t5
//#include<stdio.h>
//void sort(int* p, int n)
//{
//    int* pd = p;
//    int i, j;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n  -1 - i; j++)
//        {
//            if (*(p + j) < *(p + j + 1))
//            {
//                int temp = *(p + j);
//                *(p + j) = *(p + j + 1);
//                *(p + j + 1) = temp;
//            }
//        }
//    }
//}
//int binery_search(int arr[1000],int k,int sz) //如果找到了返回这个数的下标，找不到返回-1
//{
//    int left = 0;   
//    int right = sz - 1;
//    while (left<=right)
//    {
//        int mid = (left + right) / 2;//中间元素的下标
//        if (arr[mid] == k)
//        {
//            return mid;
//        }
//        else if (k < arr[mid])
//        {
//            left = mid+1;
//        }
//        else if (k > arr[mid])
//        {
//            right = mid-1;
//        }
//    }
//    return -1;
//}
//int main()
//{
//    int n, i, ret;
//    int k;//要找的数
//    int arr[1000];
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    scanf("%d", &k);
//    int* p = arr;
//    sort(p,n);
//    ret = binery_search(arr, k, n);
//    if (ret == -1)
//    {
//        printf("wucishu!\n");
//    }
//    else
//    {
//        printf("%d\n", ret+1);
//    }
//    return 0;
//}






//#include<stdio.h>
//int fib(int n)
//{
//    return n > 2 ? n : fib(n - 1) + fib(n - 2);
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    printf("%d\n", fib(n));
//    return 0;
//}


//#include<stdio.h>
//#include<stdlib.h>
//long long fib(int n)
//{
//    long long* p = (long long*)malloc(sizeof(long long) * (n+1));
//    p[0] = 0;
//    p[1] = 1;
//    for (int i = 2; i <= n; ++i)
//    {
//        p[i] = p[i - 1] + p[i - 2];
//    }
//    long long temp = p[n];
//    free(p);
//    p = NULL;
//    return temp;
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    printf("%lld\n", fib(n));
//    return 0;
//}


//#include<stdio.h>
//long long fib(int n)
//{
//    if (n < 2)
//    {
//        return n;
//    }
//    long long left = 0, right = 1, ret = 1;
//    for (int i = 2; i < n; ++i)
//    {
//        left = right;
//        right = ret;
//        ret = left + right;
//    }
//    return ret;
//}
//int main()
//{
    //int n;
    //scanf("%d", &n);
    //printf("%lld\n", fib(n));
//    return 0;
//}



//#include<stdio.h>
//#include<math.h>
//int fib(int n)
//{
//    double sqrt5 = sqrt(5);
//    double fibN = pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n);
//    return round(fibN / sqrt5);
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    printf("%d\n", fib(n));
//    return 0;
//}

//#include<stdio.h>
//struct Matrix
//{
//    int mat[2][2];
//};
//struct Matrix matrixMultiply(struct Matrix* a, struct Matrix* b)
//{
//    struct Matrix c;
//    for (int i = 0; i < 2; i++) {
//        for (int j = 0; j < 2; j++) {
//            c.mat[i][j] = (*a).mat[i][0] * (*b).mat[0][j] + (*a).mat[i][1] * (*b).mat[1][j];
//        }
//    }
//    return c;
//}
//struct Matrix matrixPow(struct Matrix a, int n)
//{
//    struct Matrix ret;
//    ret.mat[0][0] = ret.mat[1][1] = 1;
//    ret.mat[0][1] = ret.mat[1][0] = 0;
//    while (n > 0) {
//        if (n & 1) {
//            ret = matrixMultiply(&ret, &a);
//        }
//        n >>= 1;
//        a = matrixMultiply(&a, &a);
//    }
//    return ret;
//}
//int fib(int n)
//{
//    if (n < 2)
//    {
//        return n;
//    }
//    struct Matrix q;
//    q.mat[0][0] = q.mat[0][1] = q.mat[1][0] = 1;
//    q.mat[1][1] = 0;
//    struct Matrix res = matrixPow(q, n - 1);
//    return res.mat[0][0];
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    printf("%d", fib(n));
//    return 0;
//}










//#include<stdlib.h>
//#include<string.h>
//#include<errno.h>
//#include<stdio.h>
//int main()
//{
//    int* p = (int*)malloc(10 * sizeof(int));
//    if (p == NULL)
//    {
//        printf("%s\n", strerror(errno));
//    }
//    else
//    {
//        for (int i = 0; i < 10; ++i)
//        {
//            *(p + i) = i;
//        }
//        for (int i = 0; i < 10; ++i)
//        {
//            printf("%d ", *(p + i));
//        }
//    }
//    free(p);
//    p = NULL;
//    /*
//    1.断开指针与动态开辟的空间的联系，避免指针的危险操作
//    2.防止对同一块动态空间内存空间的重复释放
//    */
//    return 0;
//}









//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//    int* p = (int*)malloc(sizeof(int) * 10);
//    if (p == NULL)
//    {
//        return 1;
//    }
//    for (int i = 0; i < 10; ++i)
//    {
//        *(p + i) = i;
//    }
//    for (int i = 0; i < 10; ++i)
//    {
//        printf("%d ", *(p++));//这里指针移动
//    }
//    free(p);//导致free释放的不是初始位置的指针，程序崩溃
//    p = NULL;
//    return 0;
//}








//#include<stdio.h>
//#include<stdlib.h>
//struct S
//{
//    int n;
//    int arr[];
//};
//int main()
//{
//    struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//    //给arr分配内存20个字节的空间
//    if (ps == NULL)
//    {
//        return 1;
//    }
//
//    //……………………操作
//
//    free(ps);
//    ps = NULL;
//    return 0;
//}










//#include<stdio.h>
//int main()
//{
//    int arr[2][15] = { {1,2,3,4,5,6,6,5,4,3,2,1,6,5,6},{0,1,0,1,0,1,1,0,1,0,1,0,1,0,1} };
//    int temp[6] = {0};
//    int power_one = temp[0];
//    int max1 = 0;
//    int power_two = temp[0];
//    int max2 = 0;
//    for (int i = 0; i < 15; ++i)
//    {
//        ++temp[arr[0][i] - 1];
//    }
//    for (int i = 0; i < 6; ++i)
//    {
//        if (power_one < temp[i])
//        {
//            power_one = temp[i];
//            max1 = i + 1;
//        }
//    }
//    for (int i = 0; i < 6; ++i)
//    {
//        if (i == max1 - 1)
//        {
//            continue;
//        }
//        if (power_two < temp[i])
//        {
//            power_two = temp[i];
//            max2 = i + 1;
//        }
//    }
//    int left = 0;
//    int right = 0;
//    for (int i = 0; i < 15; ++i)
//    {
//        if (max1 == arr[0][i])
//        {
//            if (arr[1][i] == 0)
//            {
//                left = max1;
//            }
//            else
//            {
//                right = max1;
//            }
//        }
//        if (max2 == arr[0][i])
//        {
//            if (arr[1][i] == 0)
//            {
//                left = max2;
//            }
//            else
//            {
//                right = max2;
//            }
//        }
//    }
//    printf("左left = %d", left);
//    printf("右right = %d", right);
//    return 0;
//}



//#include<stdio.h>
//#define TEST(x) ++x
//int main()
//{
//    int num = 0;
//    TEST(num);//替换 即++num;
//    printf("%d\n", num);//1
//    return 0;
//}


//#include<stdio.h>
//int main()
//{
//    unsigned long long num = 4;
//    printf("%zu\n", sizeof(int));
//    printf("%zu\n", num);
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	a = 5;
//	c = ++a;
//	b = ++c, c++, ++a, a++;
//	b += a++ + c;
//	printf("a = %d b = %d c = %d\n:", a, b, c);
//	return 0;
//}




//#include<stdio.h>
//int main()
//{
//	int a = 5,b = 7;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d", a, b);
//	return 0;
//}


//#include<stdio.h>
//int NumberOf1(int n)
//{
//    int count = 0;
//    for (int i = 0; i < 32; ++i)
//    {
//        if (1 == ((n >> i) & 1))
//            ++count;
//    }
//    return count;
//}
//int main()
//{
//    int num = 0;
//    scanf("%d", &num);
//    int ret = NumberOf1(num);
//    printf("%d\n", ret);
//    return 0;
//}



//#include<stdio.h>
//int diff_bit(int m,int n)
//{
//    int ret = m ^ n;
//    int count = 0;
//    while (ret)
//    {
//        count++;
//        ret = ret & (ret - 1);
//    }
//    return count;
//}
//int main()
//{
//    int num1 = 0,num2 = 0;
//    scanf("%d%d", &num1,&num2);
//    int ret = diff_bit(num1,num2);
//    printf("%d\n", ret);
//    return 0;
//}




//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
/*#include<stdio.h>
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
}*/


//#include <stdio.h>
//int main()
//{
//    int RolCow = 0;
//    scanf("%d", &RolCow);
//    int arr[10][10] = { 0 };
//    for (int i = 0; i < RolCow; ++i)
//    {
//        for (int j = 0; j < RolCow; ++j)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for (int i = 1; i < RolCow; ++i)
//    {
//        for (int j = 0; j < i; ++j)
//        {
//            if (arr[i][j] != 0)
//            {
//                printf("NO\n");
//                return 0;
//            }
//        }
//    }
//    printf("YES\n");
//    return 0;
//}



//#include<stdio.h>
//int main()
//{
//    int year = 0, month = 0;
//    while (scanf("%d%d", &year, &month) != EOF)
//    {
//
//        if (month == 2)
//        {
//            if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
//            {
//                printf("29\n");
//                continue;
//            }
//            else
//            {
//                printf("28\n");
//                continue;
//            }
//        }
//        switch (month)
//        {
//        case 1:
//        case 2:
//        case 3:
//        case 5:
//        case 7:
//        case 8:
//        case 10:
//        case 12:
//            printf("31\n");
//            break;
//        default:
//            printf("30\n");
//            break;
//        }
//    }
//    return 0;
//}


//#include<stdio.h>
//int main()
//{
//    char temp = 0;
//    while (scanf("%c", &temp) != EOF)
//    {
//        if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z'))
//        {
//            printf("%c is an alphabet.\n", temp);
//        }
//        else
//        {
//            printf("%c is not an alphabet.\n", temp);
//        }
//    }
//    return 0;
//}



//#include<stdio.h>
//int main()
//{
//    double val = 0.0;
//    int month = 0, day = 0, coupon = 0;
//    scanf("%lf%d%d%d", &val, &month, &day, &coupon);
//    double discount = 0.0;
//
//    if (month == 11)discount = 0.7;
//    else discount = 0.8;
//
//    double total = 0.0;
//    if (coupon)
//    {
//        total = val * discount - 50;
//    }
//    else
//    {
//        total = val * discount;
//    }
//    if (total < 0)
//    {
//        total = 0.0;
//    }
//    printf("%0.2lf", total);
//    return 0;
//}







/*写一个函数打印arr数组的内容，不使用数组下标，使用指针。
arr是一个整形一维数组。*/
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* parr = arr;
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", *(parr + i));
//	}
//	return 0;
//}








//写一个函数，可以逆序一个字符串的内容。
//#include<stdio.h>
//#include<string.h>
//void Reverse(char* str, int size)
//{
//    char* begin = str;
//    char* end = &str[size - 1];
//    while (begin <= end)
//    {
//        char temp = *begin;
//        *begin = *end;
//        *end = temp;
//        ++begin;
//        --end;
//    }
//}
//int main()
//{
//    char str[10000] = { 0 };
//    gets(str);
//    Reverse(str, (unsigned int)strlen(str));
//    printf("%s", str);
//    return 0;
//}




//打印菱形13行最大15列
//#include<stdio.h>
//#define N 7
//int main()
//{
//	for (int i = 1; i <= N; i++)
//	{	
//		for (int j = 0; j < N - i; j++)
//		{
//			printf(" ");
//		}
//		for (int j = 0; j < 2 * i - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (int i = 1; i <= N - 1; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			printf(" ");
//		}
//		for (int j = 0; j < 2 * (N - 1 - i) + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}



/*求出0～100000之间的所有“水仙花数”并输出。
“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数”。*/
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100000; i++)
//	{
//		int tmp = i;
//		int count = 0;
//		int sum = 0;
//		while (tmp)
//		{
//			tmp /= 10;
//			count++;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow((tmp % 10), count);
//			tmp /= 10;
//		}
//		if (sum == i)
//		{
//			printf("%d是水仙花数\n", i);
//		}
//	}
//	return 0;
//}



//#include<stdio.h>
//#include<stdlib.h>
//int SumDataNum(int a, int N)
//{
//	int sum = 0;
//	int num = 0;
//	for (int i = 0; i < N; i++)
//	{
//		num = num * 10 + a;
//		sum = sum + num;
//	}
//	return sum;
//}
//int main()
//{
//	int ret = SumDataNum(2, 5);
//	printf("ret=%d", ret);
//	return 0;
//}



//#include<stdio.h>
//struct Student
//{
//	char name[20];
//	int age;
//	double hight;
//};
//int main()
//{
//	struct Student s = { .hight = 180.6,.age = 18 };
//	printf("%s %d %0.1lf", s.name, s.age, s.hight);
//	return 0;
//}



//#include<stdio.h>
//struct student
//{
//	int m_age;
//};
//int main()
//{
//	int age = 0;
//	scanf("%d", &age);
//	struct student s = { .m_age = age };
//	printf("%d\n", s.m_age);
//	return 0;
//}



/*喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。*/
//#include<stdio.h>
//int main()
//{
//	int money = 20;
//	int count = 0;
//	int empty_bottle = 0;
//	while (money > 0)
//	{
//		--money;
//		++empty_bottle;
//		++count;
//		if (empty_bottle >= 2)
//		{
//			money += empty_bottle / 2;
//			empty_bottle %= 2;
//		}
//	}
//	printf("可以喝%d瓶汽水\n", count);
//	return 0;
//}





//死循环
//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}



/*
输入一个整数数组，实现一个函数，

来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，

所有偶数位于数组的后半部分。
*/
//#include<stdio.h>
//#include<stdlib.h>
//void adjust(int* arr,int size)
//{
//	int begin = 0, end = size - 1;
//	while (begin < end)
//	{
//		while (begin < end && *(arr + begin) % 2 == 1)//若为奇数，则向后寻找偶数
//		{
//			++begin;
//		}
//		while (begin < end && *(arr + end) % 2 == 0)//若为偶数，则向前寻找奇数
//		{
//			--end;
//		}
//		if (begin < end)
//		{
//			int temp = *(arr + begin);
//			*(arr + begin) = *(arr + end);
//			*(arr + end) = temp;
//		}
//	}
//}
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int* arr = (int*)malloc(sizeof(int) * num);
//	for (int i = 0; i < num; ++i)
//	{
//		scanf("%d", (arr + i));
//	}
//	adjust(arr, num);
//	for (int i = 0; i < num; ++i)
//	{
//		printf("%d ", *(arr + i));
//	}
//	free(arr);
//	arr = NULL;
//	return 0;
//}



//模拟strcpy实现
//#include<stdio.h>
//#include<assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest++ = *src++);
//	return ret;
//}
//int main()
//{
//	char str1[] = "xxxxxxxxxxxxxxxxxx";
//	char str2[] = "hello bjy";
//	char* dest = my_strcpy(str1, str2);
//	printf("%s\n", dest);
//	printf("%s\n", str1);
//	return 0;
//}



//模拟strlen实现
//#include<stdio.h>
//#include<assert.h>
//int my_strlen(const char* str)
//{
//	assert(str);
//	int count = 0;
//	while (*str++ != '\0')
//	{
//		++count;
//	}
//	return count;
//}
//int main()
//{
//	char* test = "hahaha";
//	int ret = my_strlen(test);
//	printf("%d\n", ret);
//	return 0;
//}



//最高分和最低分之差
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int arr[n];
//    for (int i = 0; i < n; ++i)
//    {
//        scanf("%d", &arr[i]);
//    }
//    int max = arr[0], min = arr[0];
//    for (int i = 1; i < n; ++i)
//    {
//        if (max < arr[i])
//        {
//            max = arr[i];
//        }
//        if (min > arr[i])
//        {
//            min = arr[i];
//        }
//    }
//    printf("%d", max - min);
//    return 0;
//}



//有序序列判断
//#include <stdio.h>
//int judge(int* arr, int size)
//{
//    int flag = 0;
//    if (arr[0] < arr[1])
//        flag = 1;
//
//    for (int i = 0; i < size - 1; ++i)
//    {
//        if (flag == 1)//升序
//        {
//            if (arr[i] > arr[i + 1])
//                return 0;
//        }
//        if (flag == 0)//降序
//        {
//            if (arr[i] < arr[i + 1])
//                return 0;
//        }
//    }
//    return 1;
//}
//int main()
//{
//    int N = 0;
//    scanf("%d", &N);
//    int arr[N];
//    for (int i = 0; i < N; ++i)
//    {
//        scanf("%d", &arr[i]);
//    }
//
//    if (judge(arr, N))
//    {
//        printf("sorted\n");
//    }
//    else
//    {
//        printf("unsorted\n");
//    }
//    return 0;
//}




//#include<stdio.h>
//void Swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int GetMid(int* arr, int left, int right)//三数取中
//{
//	int mid = (left + right) >> 1;
//	if (arr[left] < arr[mid])
//	{
//		if (arr[mid] < arr[right])
//		{
//			return mid;
//		}
//		else if (arr[left] > arr[right])
//		{
//			return left;
//		}
//		else
//		{
//			return right;
//		}
//	}
//	else//arr[left] > arr[mid]
//	{
//		if (arr[mid] > arr[right])
//		{
//			return mid;
//		}
//		else if (arr[left] > arr[right])
//		{
//			return right;
//		}
//		else
//		{
//			return left;
//		}
//	}
//}
//void QuickSort(int* arr, int left, int right)
//{
//	if (left >= right)return;
//
//	int index = GetMid(arr, left, right);
//	Swap(&arr[left], &arr[index]);
//
//	int begin = left, end = right;
//	int pivot = begin;
//	int key = arr[begin];
//	while (begin < end)
//	{
//		while (begin < end && arr[end] >= key)
//		{
//			--end;
//		}
//		arr[pivot] = arr[end];
//		pivot = end;
//		while (begin < end && arr[begin] <= key)
//		{
//			++begin;
//		}
//		arr[pivot] = arr[begin];
//		pivot = begin;
//	}
//	pivot = begin;
//	arr[pivot] = key;
//
//	QuickSort(arr, left, pivot - 1);
//	QuickSort(arr, pivot + 1, right);
//
//}
//int main()
//{
//	int n = 0;
//	int m = 0;
//	int arr1[1000] = { 0 };
//	int arr2[1000] = { 0 };
//	//输入n和m
//	scanf("%d %d", &n, &m);
//	int i = 0;
//	int j = 0;
//	//输入两个升序序列
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d", &arr2[i]);
//	}
//
//	int arr[1000] = { 0 };
//	for (int i = 0; i < n; ++i)
//	{
//		arr[i] = arr1[i];
//	}
//	for (int i = 0; i < m; ++i)
//	{
//		arr[n + i] = arr2[i];
//	}
//
//	QuickSort(arr, 0, n + m - 1);
//
//	for (int i = 0; i < n + m; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}





//#include <stdio.h>
//int main()
//{
//    int a = 0, b = 0;
//    scanf("%d%d", &a, &b);
//    int m = a < b ? a : b;
//    while (m)
//    {
//        if (m % a == 0 && m % b == 0)
//        {
//            printf("%d", m);
//            break;
//        }
//        m++;
//    }
//    return 0;
//}






//#include<stdio.h>
//#include<string.h>
//void reverse(char* left, char* right)
//{
//    while (left < right)
//    {
//        char temp = *left;
//        *left = *right;
//        *right = temp;
//        left++;
//        right--;
//    }
//}
//int main()
//{
//    char str[200] = { 0 };
//    gets(str);
//    int len = strlen(str);
//    reverse(str,str+len-1);
//    char* strat = str;
//    while (*strat)
//    {
//        char* end = strat;
//        while (*end != ' ' && *end != '\0')
//        {
//            end++;
//        }
//        reverse(strat, end - 1);
//        if (*strat == ' ')
//        {
//            strat = end + 1;
//        }
//        else
//        {
//            strat = end;
//        }
//    }
//    printf("%s\n", str);
//    return 0;
//}







//#include<stdio.h>
//int x = 5, y = 7;
//void swap()
//{
//	int z;
//	z = x;
//	x = y;
//	y = z;
//}
//int main()
//{
//	int x = 3, y = 8;
//	swap();
//	printf("%d,%d\n",x, y);
//	int arr[5 + 3] = { 0, 1, 3, 5, 7, 9 };
//	for (int i = 0; i < 8; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	char c2[] = { '\x10', '\xa', '\8' };//\8
//	double d[5] = { 2.0, 4.0, 6.0, 8.0, 10.0 };
//	char c1[] = { '1','2','3','4','5' };
//	return 0;
//}




//#define INT_PTR int*
//typedef int* int_ptr;
//INT_PTR a, b;
//int_ptr c, d;
//int main()
//{
//	int x = 10;
//	a = &x;
//	b = x;
//	c = &x;
//	d = &x;
//	return 0;
//}




//#include <stdio.h>
//int main()
//{
//    int sum = 0;
//    int month_days[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//    int year = 0, month = 0, day = 0;
//    scanf("%d%d%d", &year, &month, &day);
//    if (month > 1)
//        sum = month_days[month - 2] + day;
//    else
//        sum = day;
//    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && (month > 2))
//        sum++;
//    printf("%d\n", sum);
//    return 0;
//}




//static int arr[100000];
//int* printNumbers(int n, int* returnSize)
//{
//    int num = 1;
//    while (n--)num *= 10;
//    for (int i = 1; i < num; ++i)
//    {
//        arr[i - 1] = i;
//    }
//    *returnSize = num - 1;
//    return arr;
//}





//#include<stdio.h>
//int main()
//{
//	/*unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d  %d", a + b, c);*/
//
//	unsigned int a = 0x1234; unsigned char b = *(unsigned char*)&a;
//
//	printf("%d", b);
//	return 0;
//}





//#include<stdio.h>
//int main()
//{
//	char a[1000] = { 0 };
//	int i = 0;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d", strlen(a));
//	return 0;
//}




/*
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：



A选手说：B第二，我第三；

B选手说：我第二，E第四；

C选手说：我第一，D第二；

D选手说：C最后，我第三；

E选手说：我第四，A第一；

比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
*/
//#include<stdio.h>
//int main()
//{
//    int a = 0, b = 0, c = 0, d = 0, e = 0;
//    for (a = 1; a <= 5; a++)
//    {
//        for (b = 1; b <= 5; b++)
//        {
//            for (c = 1; c <= 5; c++)
//            {
//                for (d = 1; d <= 5; d++)
//                {
//                    for (e = 1; e <= 5; e++)
//                    {
//                        if ((2 == b && 3 != a) || (2 != b && 3 == a) == 1)
//                        {
//                            if ((2 == b && 4 != e) || (2 != b && 4 == e) == 1)
//                            {
//                                if ((1 == c && 2 != d) || (1 != c && 2 == d) == 1)
//                                {
//                                    if ((5 == c && 3 != d) || (5 != c && 3 == d) == 1)
//                                    {
//                                        if ((4 == e && 1 != a) || (4 != e && 1 == a) == 1)
//                                        {
//                                            if (((a != b) && (a != c) && (a != d) && (a != e))
//                                                && ((b != c) && (b != d) && (b != e))
//                                                && ((c != d) && (c != e))
//                                                && ((d != e)))
//                                            {
//                                                printf("a = %d , b = %d , c = %d , d = %d , e = %d\n", a, b, c, d, e);
//                                            }
//                                        }
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//    return 0;
//}





//#include<stdio.h>
//int main()
//{
//	int killer = 0;
//	for (killer = 'A'; killer < 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("killer is  %c\n", killer);
//		}
//	}
//	return 0;
//}



//#include<stdio.h>
//#define MAX 30
//int main()
//{
//    int arr[MAX][MAX] = {0};
//    int n = 0;
//    scanf("%d", &n);
//    arr[0][0] = 1;
//    for (int i = 0; i < n; ++i)
//    {
//        int j = 0;
//        arr[i][0] = arr[i][j] = arr[0][0];
//        for (; j <= i; ++j)
//        {
//            arr[i + 1][j + 1] = arr[i][j] + arr[i][j + 1];
//        }
//    }
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j <= i; ++j)
//        {
//            printf("%-5d", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}




//#include <stdio.h>
//int check_sys_1()
//{
//	int i = 1;
//	char* p = (char*)&i;
//	return *p;
//}
////简化后:
//int check_sys()
//{
//	int i = 1;
//	return (*(char*)&i);
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}



//#include <stdio.h>
//int check_sys()
//{
//	union
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	return un.c;
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}




//#include<stdio.h>
//int main()
//{
//	char a = 5;  //  5的补码为:00000000 00000000 00000000 00000101   截断后保留一个字节为:00000101
//	char b = 126;//126的补码为:00000000 00000000 00000000 01111110   截断后保留一个字节为:01111110
//
//	char c = a + b;//此时a + b进行计算，发生整型提升
//				//00000000 00000000 00000000 00000101
//				//00000000 00000000 00000000 01111110
//		 //相加得:00000000 00000000 00000000 10000011
//		 //存入char类型变量，发生截断,保留一个字节为:10000011
//
//	printf("%d\n", c);//以十进制方式打印signed char(有符号)类型数据，发生整型提升
//					  //补码:11111111 11111111 11111111 10000011
//					  //反码:11111111 11111111 11111111 10000010
//					  //原码:10000000 00000000 00000000 01111101
//					  //即输出-125
//	return 0;
//}






/*
有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。

要求：时间复杂度小于O(N);
*/
//#include<stdio.h>
//#define NUM 5
//int check_num(int* parr[NUM],int check)
//{
//	for (int i = 0; i < NUM ; ++i)
//	{
//		if ((i == NUM - 1)||(*parr[i + 1] > check))
//		{
//			for (int j = 0; j < NUM; ++j)
//			{
//				if (*(parr[i] + j) == check)
//				{
//					return 1;
//				}
//			}
//			return 0;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int check = 0;
//	scanf("%d", &check);
//	int arr1[NUM] = { 1,2,3,4,5 };
//	int arr2[NUM] = { 6,7,8,9,10 };
//	int arr3[NUM] = { 11,12,13,14,15 };
//	int arr4[NUM] = { 16,17,18,19,20 };
//	int arr5[NUM] = { 21,22,23,24,25 };
//	int* parr[NUM] = {arr1,arr2,arr3,arr4,arr5};
//
//	if (check_num(parr, check))
//		printf("找到这个数了\n");
//	else
//		printf("没找到这个数\n");
//	return 0;
//}






/*
实现一个函数，可以左旋字符串中的k个字符。
例如：
ABCD左旋一个字符得到BCDA

ABCD左旋两个字符得到CDAB
*/
//#include<stdio.h>
//#include<string.h>
//void Left_handed(char* str,int k,int size)
//{
//	for (int j = 0; j < k; ++j)
//	{
//		int i = 0;
//		char temp = *str;
//		for (i = 0; i < size; ++i)
//		{
//			str[i] = str[i + 1];
//		}
//		str[i - 1] = temp;
//	}
//}
//int main()
//{
//	char str[100] = { 0 };
//	scanf("%s", str);
//	int k = 0;
//	scanf("%d", &k);
//	Left_handed(str, k, strlen(str));
//	printf("%s", str);
//	return 0;
//}







/*
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 =AABCD和s2 = BCDAA，返回1

给定s1=abcd和s2=ACBD，返回0.
*/
//#include<stdio.h>
//#include<string.h>
//void Left_Once(char* str,int size)
//{
//		int i = 0;
//		char temp = *str;
//		for (i = 0; i < size; ++i)
//		{
//			str[i] = str[i + 1];
//		}
//		str[i - 1] = temp;
//}
//int judge(char* str1,int str2 ,int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		Left_Once(str1, size);
//		if (strcmp(str1, str2) == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char str1[100] = { 0 };
//	scanf("%s", str1);
//	char str2[100] = { 0 };
//	scanf("%s", str2);
//	
//	if (judge(str1, str2, strlen(str1)))
//		printf("str2可由str1旋转得到\n");
//	else
//		printf("str2不可由str1旋转得到\n");
//	return 0;
//}









//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (int i = 0; i < n; ++i)
//        {
//            printf("* ");
//        }
//        printf("\n");
//        for (int i = 0; i < n - 2; ++i)
//        {
//            printf("* ");
//            for (int j = 0; j < n - 2; ++j)
//            {
//                printf("  ");
//            }
//            printf("*\n");
//        }
//        for (int i = 0; i < n; ++i)
//        {
//            printf("* ");
//        }
//        printf("\n");
//    }
//    return 0;
//}








//#include<stdio.h>
//#include<stdlib.h>
//void Insert(int* arr, int size, int key)
//{
//    int i = 0;
//    int temp = 0;
//    for (i = 0; i < size - 1; ++i)
//    {
//        if (key < arr[i])
//        {
//            break;
//        }
//    }
//    temp = i;
//    for (i = size - 1; i > temp; --i)
//    {
//        arr[i] = arr[i - 1];
//    }
//    arr[temp] = key;
//}
//void Print(int* arr, int size)
//{
//    for (int i = 0; i < size; ++i)
//    {
//        printf("%d ", arr[i]);
//    }
//}
//int main()
//{
//    int N = 0;
//    scanf("%d", &N);
//    int* arr = (int*)malloc(sizeof(int) * (N + 1));
//    for (int i = 0; i < N; ++i)
//    {
//        scanf("%d", &arr[i]);
//    }
//    int num = 0;
//    scanf("%d", &num);
//
//    Insert(arr, N + 1, num);
//    Print(arr, N + 1);
//
//    free(arr);
//    return 0;
//}




//#include <stdio.h>
//int main()
//{
//    int n;
//    while (scanf("%d", &n) != EOF)
//    {
//        int start = n * n - n + 1;
//        printf("%d", start);
//        int i;
//        for (i = 1; i < n; i++)
//        {
//            printf("+%d", start + 2 * i);
//        }
//        printf("\n");
//    }
//    return 0;
//}









//#include<stdio.h>
//int main()
//{
//	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//1 6
//	return 0;
//}






//#include<stdio.h>
//int main()
//{
//	int a[5] = { 5, 4, 3, 2, 1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}







//#include<stdio.h>
//#include<stdlib.h>
//
//int compare1(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//void print1(int* arr,int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void test1()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, size, sizeof(arr[0]), compare1);
//	print1(arr, size);
//}
///*************************************************************************/
//int compare2(const void* e1, const void* e2)
//{
//	return *(char*)e1 - *(char*)e2;
//}
//void print2(char* str, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		printf("%c ", str[i]);
//	}
//	printf("\n");
//}
//void test2()
//{
//	char str[10] = { 'j','i','h','g','f','e','d','c','b','a' };
//	int size = sizeof(str) / sizeof(str[0]);
//	qsort(str, size, sizeof(str[0]), compare2);
//	print2(str, size);
//}
///************************************************************************/
//int main()
//{
//	test1();
//	test2();
//	return 0;
//}









//#include<stdio.h>
//void Swap(char* buf1, char* buf2, int width)
//{
//	for (int i = 0; i < width; ++i)
//	{
//		char temp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = temp;
//		++buf1;
//		++buf2;
//	}
//}
//void bubble_sort(void* base,int size,int width,int(*compare)(const void* e1,const void* e2))
//{
//	for (int i = 0; i < size - 1; ++i)
//	{
//		for (int j = 0; j < size - 1 - i; ++j)
//		{
//			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//int compare(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//void print(int* arr,int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,size,sizeof(arr[0]),compare);
//	print(arr,size);
//	return 0;
//}




//#include<stdio.h>
//int main()
//{
//	char a = 101;
//	int sum = 200;
//	a += 27; sum += a;//-128 72
//	printf("%d\n", sum);
//	return 0;
//}





//#include<stdio.h>
//int main()
//{
//	int value = 1024;//0x0000 0400 小端 ——  0004 0000
//	char condition = *((char*)(&value));//00
//	if (condition) 
//		value += 1;
//	condition = *((char*)(&value));
//	if (condition) 
//		value += 1; 
//	condition = *((char*)(&value));
//	printf("%d %d", value, condition);//1024 0
//	return 0;
//}






//32位机器
//#include<stdio.h>
//void func(char para[100])
//{
//	void* p = malloc(100);
//	printf("%d, %d\n", sizeof(para), sizeof(p));//4 4
//}
//int main()
//{
//	char arr[100] = { 0 };
//	func(arr);
//	return 0;
//}







//#include <stdio.h>
//void func(char* p)
//{ 
//	p = p + 1; 
//}
//int main()
//{
//	char s[] = { '1', '2', '3', '4' };
//	func(s);//不改变p
//	printf("%c", *s);//1
//	return 0;
//}








//#include <stdio.h>
//void fun(char** p)
//{
//	int i;
//	for (i = 0; i < 4; i++)
//		printf("%s", p[i]);
//}
//int main()
//{
//	char* s[6] = { "ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX" };//ABCDEFGHIJKLMNOP
//	fun(s);
//	printf("\n");
//	return 0;
//}





//#include<stdio.h>
//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));//16 int [4]
//	printf("%d\n", sizeof(a + 0));//4 为数组第一个元素的地址(即指针类型)
//	printf("%d\n", sizeof(*a));//4 int
//	printf("%d\n", sizeof(a + 1));//4 int*
//	printf("%d\n", sizeof(a[1]));//4 int
//	printf("%d\n", sizeof(&a));//4 整个数组的地址(数组指针)
//	printf("%d\n", sizeof(*&a));//16
//	printf("%d\n", sizeof(&a + 1));//4 数组指针
//	printf("%d\n", sizeof(&a[0]));//4 int*
//	printf("%d\n", sizeof(&a[0] + 1));//4 int*
//	return 0;
//}






//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", sizeof(arr));//6
//	printf("%d\n", sizeof(arr + 0));//4 char*
//	printf("%d\n", sizeof(*arr));//1 char
//	printf("%d\n", sizeof(arr[1]));//1 char
//	printf("%d\n", sizeof(&arr));//4 数组指针
//	printf("%d\n", sizeof(&arr + 1));//4 数组指针
//	printf("%d\n", sizeof(&arr[0] + 1));//4 char*
//
//	printf("%d\n", strlen(arr));//随机值
//	printf("%d\n", strlen(arr + 0));//随机值
//	printf("%d\n", strlen(&arr));//随机值
//	printf("%d\n", strlen(&arr + 1));//随机值
//	printf("%d\n", strlen(&arr[0] + 1));//随机值
//	printf("%d\n", strlen(*arr));//err代码,非法访问	*arr为数组的首元素'a'(即97)
//	printf("%d\n", strlen(arr[1]));//err代码,非法访问
//	return 0;
//}





//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));//7 char [7]
//	printf("%d\n", sizeof(arr + 0));//4 char*
//	printf("%d\n", sizeof(*arr));//1 char
//	printf("%d\n", sizeof(arr[1]));//1 char
//	printf("%d\n", sizeof(&arr));//4 数组指针
//	printf("%d\n", sizeof(&arr + 1));//4 数组指针
//	printf("%d\n", sizeof(&arr[0] + 1));//4 char*
//
//	printf("%d\n", strlen(arr));//6
//	printf("%d\n", strlen(arr + 0));//6
//	printf("%d\n", strlen(&arr));//6
//	printf("%d\n", strlen(&arr + 1));//随机值
//	printf("%d\n", strlen(&arr[0] + 1));//5
//	printf("%d\n", strlen(*arr));//err
//	printf("%d\n", strlen(arr[1]));//err
//	return 0;
//}







//#include<stdio.h>
//int main()
//{
//	char* p = "abcdef";
//	printf("%d\n", sizeof(p));//4 char*
//	printf("%d\n", sizeof(p + 1));//4 char*
//	printf("%d\n", sizeof(*p));//1 char
//	printf("%d\n", sizeof(p[0]));//1 char
//	printf("%d\n", sizeof(&p));//4 char**
//	printf("%d\n", sizeof(&p + 1));//4 char**
//	printf("%d\n", sizeof(&p[0] + 1));//4 char*
//
//	printf("%d\n", strlen(p));//6
//	printf("%d\n", strlen(p + 1));//5
//	printf("%d\n", strlen(&p));//随机值
//	printf("%d\n", strlen(&p + 1));//随机值
//	printf("%d\n", strlen(&p[0] + 1));//5
//	printf("%d\n", strlen(*p));//err
//	printf("%d\n", strlen(p[0]));//err
//	return 0;
//}








//#include<stdio.h>
//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48	3*4*4 = 48
//	printf("%d\n", sizeof(a[0][0]));///4 int
//	printf("%d\n", sizeof(a[0]));//16 int [4]
//	printf("%d\n", sizeof(a[0] + 1));//第一行第二个元素的地址 4 int*
//	printf("%d\n", sizeof(*(a[0] + 1)));//4	int
//	printf("%d\n", sizeof(a + 1));//4 数组指针
//	printf("%d\n", sizeof(*(a + 1)));//16 int [4]
//	printf("%d\n", sizeof(&a[0] + 1));//4 数组指针
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16
//	printf("%d\n", sizeof(*a));//16
//	printf("%d\n", sizeof(a[3]));//16	sizeof在预处理阶段完成，表达式不实际运行
//	return 0;
//}





//#include<stdio.h>
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d %d", *(a + 1), *(ptr - 1));//2 5
//	return 0;
//}





//#include<stdio.h>
////已知，结构体Test类型的变量大小是20个字节
////假设p 的值为0x100000
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);//00100014
//	printf("%p\n", (unsigned long)p + 0x1);//00100001
//	printf("%p\n", (unsigned int*)p + 0x1);//00100004
//	return 0;
//}









//#include<stdio.h>
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x %x", ptr1[-1], *ptr2);//4 2000000
//	return 0;
//}



//#include<stdio.h>
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	int* p = a[0];
//	printf("%d", p[0]);//1
//	return 0;
//}




//#include<stdio.h>
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//FFFFFFFC(-4以地址形式打印),-4
//	return 0;
//}




//#include<stdio.h>
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//10 5
//	return 0;
//}






//#include <stdio.h>
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);//at
//	return 0;
//}





//画图理解
//#include<stdio.h>
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);//POINT
//	printf("%s\n", *-- * ++cpp + 3);//ER
//	printf("%s\n", *cpp[-2] + 3);//ST
//	printf("%s\n", cpp[-1][-1] + 1);//EW
//	return 0;
//}





















/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//struct ListNode 
//{
//    int val;
//    struct ListNode* next;
//};
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
//{
//    struct ListNode* head = NULL, * tail = NULL;
//    int carry = 0;
//    while (l1 || l2) {
//        int n1 = l1 ? l1->val : 0;
//        int n2 = l2 ? l2->val : 0;
//        int sum = n1 + n2 + carry;
//        if (!head) {
//            head = tail = malloc(sizeof(struct ListNode));
//            tail->val = sum % 10;
//            tail->next = NULL;
//        }
//        else {
//            tail->next = malloc(sizeof(struct ListNode));
//            tail->next->val = sum % 10;
//            tail = tail->next;
//            tail->next = NULL;
//        }
//        carry = sum / 10;
//        if (l1) {
//            l1 = l1->next;
//        }
//        if (l2) {
//            l2 = l2->next;
//        }
//    }
//    if (carry > 0) {
//        tail->next = malloc(sizeof(struct ListNode));
//        tail->next->val = carry;
//        tail->next->next = NULL;
//    }
//    return head;
//}
//int main()
//{
//    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    l1->val = 2;
//    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    node1->val = 4;
//    l1->next = node1;
//    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    node2->val = 3;
//    node1->next = node2;
//    node2->next = NULL;
//    //349+465 = 814
//
//    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    l2->val = 5;
//    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    node3->val = 6;
//    l2->next = node3;
//    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    node4->val = 4;
//    node3->next = node4;
//    node4->next = NULL;
//
//    struct ListNode* ret = addTwoNumbers(l1, l2);
//    for (struct ListNode* cur = ret; cur != NULL; cur = cur->next)
//    {
//        printf("%d ", cur->val);
//    }
//    return 0;
//}


































































































