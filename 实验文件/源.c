#define _CRT_SECURE_NO_WARNINGS

















////forѭ��
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
//        key = key * i;//����׳�
//        sum = sum + key;//ÿ���׳����
//    }
//    printf("%d\n", sum);
//    return 0;
//}






////whileѭ��
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
//        key = key * i;//����׳�
//        sum = sum + key;//ÿ���׳����
//        i++;
//    }
//    printf("%d\n", sum);
//    return 0;
//}




////do whileѭ��
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








////��forѭ����װΪ����
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





////�������
//#include<stdio.h>
//int Factorial(int n)//���㵥���׳�
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
//int FAC(int i)//��������׳����
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
//	int a=0;//Ӣ����ĸ
//	int b=0;//�ո�
//	int c=0;//����
//	int d=0;//�����ַ�
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
//	printf("��%d��Ӣ����ĸ\n",a);
//	printf("��%d���ո�\n",b);
//	printf("��%d������\n",c);
//	printf("��%d�������ַ�\n",d);
//	return 0;
//}




//#include<stdio.h>
//int main()
//{
//	int str[100] = {0};
//	int n;//�ж��ٸ�����
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
//	//�������a
//	printf("����һ��2��4�ľ���\n");
//	for (i = 0; i < 2; i++)                    //��
//		for (j = 0; j < 4; j++)                //��
//			scanf("%d", &a[i][j]);  
//
//	//�������b
//	printf("����һ��4��3�ľ���\n");
//	for (i = 0; i < 4; i++)                   //��
//		for (j = 0; j < 3; j++)               //��
//			scanf("%d", &b[i][j]);    
//
//	//�Ծ���c���д���
//	for (i = 0; i < 2; i++)                 
//	{
//		for (j = 0; j < 3; j++)
//		{
//			sum = 0;
//			for (k = 0; k < 4; k++)   //����c��ÿһ��Ԫ�ص�ѭ������
//			{
//				sum += a[i][k] * b[k][j]; //�Ծ���c�е�ĳһԪ�ؽ��м���
//			}        
//			c[i][j] = sum;     //������c�е�ĳһԪ�ؽ��и�ֵ
//		}
//	}
//
//	//�������c
//	printf("�õ�һ��2��3�ľ���\n");
//	for (i = 0; i < 2; i++)            
//	{
//		for (j = 0; j < 3; j++)
//			printf("%5d", c[i][j]);
//		printf("\n");
//	}
//	return 0;
//}























////�������
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
//	//��ʼ��
//	Initarr(showarr);
//	//����
//	Handle(showarr);
//	//���
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
//	printf("%d�Ľ׳�Ϊ%d\n", n, ret);
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





                                                                   //��ϰ

////����n�Ľ׳�
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









//����1��+2��+3!

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








//��һ�����������в��Ҿ����ĳ������n

//#include<stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6,7,8,9 };
//    int k =7;//Ҫ�ҵ�������
//    int i = 0;
//    int bjy = sizeof(arr) / sizeof(arr[0]);//����������е�Ԫ�ظ�����9��
//    for (i = 0; i < bjy; i++)
//    {
//        if (k == arr[i])
//        {
//            printf("�ҵ��ˣ��±��ǣ�%d\n", i);
//            break;
//        }
//    }
//    if (i == bjy)
//    {
//        printf("�Ҳ�����\n");
//    }
//    return 0;
//}

////�۰�����㷨(���ֲ����㷨)�������������п���
////����(������)
//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//    int k =5;//Ҫ�ҵ�����
//    int left = 0;//���±�
//    int a = sizeof(arr) / sizeof(arr[0]);//����Ԫ�ظ���
//    int right = a - 1;//���±�
//    while (left <= right)
//    {
//        int mid = (right + left)/2;//�±��м���
//        if (arr[mid] > k)
//        {
//            right = mid - 1;
//            //����
//        }
//        else if (arr[mid] < k)
//        {
//            left = mid + 1;
//            //����
//        }
//        else//arr[mid]=k
//        {
//            printf("�ҵ��ˣ��±��ǣ�%d\n", mid);
//        }
//        return 0;
//    }
//    if (left > right)
//    {
//        printf("�Ҳ����ˡ�\n");
//    }
//}









////��д������ʾ����ַ��������ƶ����м���
////############
////w##########!
////we########!!
////wel######!!!
////welc####y!!!
////����
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
//    //����"\0"
//    //int right = (sizeof(arr1) / sizeof(arr1[0])) - 2;//��ȷ
//    int right = strlen(arr1) - 1; //��ȷд��
//
//    //�߼�����
//    while(left<=right)
//    {
//        arr2[left] = arr1[left];
//        arr2[right] = arr1[right];
//        printf("%s\n", arr2);
//        Sleep(1000);//��Ϣһǧ����
//        //����Sleep���������� windows.hͷ�ļ�
//        system("cls");//ִ��ϵͳ����ĺ�������cls���������Ļ
//        //����system���������� stdlib.hͷ�ļ�
//        left++;
//        right--;
//    }
//    printf("welcome to bjy heart!!!");
//    return 0;
//}










////��д����ʵ�֣�ģ���û���¼��������ֻ�ܵ�¼����(����������ȷ����ʾ��¼�ɹ������ξ�����������˳�����)
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    int i = 0;
//    char input[20];
//    for (i = 0; i < 3; i++)
//    {
//        printf("����������!\n");
//        scanf("%s", &input);
//        if (strcmp(input,"123456")==0)
//            //�ȺŲ��������Ƚ����������ַ����Ƿ����
//            //Ӧʹ��һ���⺯������strcmp
//            //�����ַ�����ȷ���0
//        {
//            printf("��¼�ɹ�\n");
//            break;
//        }
//        else
//        {
//            printf("�������\n");
//        }
//    }
//    if (i == 3)
//    {
//        printf("�������������\n");
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













////��ѭ����ӡ5
//#include<stdio.h>
//int main()
//{
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        if (i = 5)//i��ֵΪ5   ����
//        {
//            printf("%d\n", i);
//        }
//    }
//    return 0;
//}














////���������Ӵ�С���
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
//    printf("%d,%d,%d\n", a, b, c);//a�з����ֵ��b��֮��c��С
//    return 0;
//}












////��ӡ1-100��3�ı���
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













////�������������Լ��
////շת�����
//#include<stdio.h>
//int main()
//{
//    int a;
//    int b;
//    int c;
//    scanf("%d%d", &a, &b);
//    while (c=a % b)//Ϊ0ֹͣѭ��
//    {
//        a = b;
//        b = c;
//    }
//    printf("%d\n", b);
//    return 0;
//}









////��ӡ1000-2000��֮�������
////���ꡪ�ܱ�4���������ܱ�100����
////�ܱ�400����������
//#include<stdio.h>
//int main()
//{
//    int year;
//    int count = 0;
//    for (year = 1000; year <= 2000; year++)
//    {
//        if ((year % 4 == 0 && year % 100 != 0)||(year%400==0))
//        {
//            printf("%d������\n", year);
//            count++;
//        }
//    }
//    printf("����%d������\n", count);
//    return 0;
//}













////��ӡ100-200֮�������

////�������Գ�����ֻ��1�������ܹ������Լ�
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
//            printf("������%d\n", i);
//        }
//    }
//    printf("������%d��\n",count);
//}


////�㷨�Ż���
////i=a*b   16=2*8=4*4
////a��b��������һ������<=i�Ŀ�ƽ��
//#include<stdio.h>
//#include<math.h>//����sqrt��������Ҫ���õ�ͷ�ļ�
//int main()
//{
//    int i;
//    int j;
//    int count=0;
//    for (i = 101; i <= 200; i+=2)//ÿ�μӶ���������ż��
//    {
//        for (j = 2; j <=sqrt(i); j++)//sqrt����ƽ������ѧ�⺯��
//        {
//            if (i % j == 0)
//            {
//                break;
//            }
//        }
//        if (j > sqrt(i))
//        {
//            count++;
//            printf("������%d\n", i);
//        }
//    }
//    printf("������%d��\n", count);
//    return 0;
//}












////��дһ���������1-100������֮���ж��ٸ�����9
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
//    printf("����%d����\n", count);
//    return 0;
//}










//�������
////����1/1-1/2+1/3-����+1/99-1/100

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
//        sign = -sign;//�任����
//    }
//    printf("%f", sum);
//    return 0;
//}










////��ʮ�������е����ֵ
//#include<stdio.h>
//int main()
//{
//    int arr[] = { -1,-2,-3,-4,-5,-6,-7,-8,-9,-10 };
//    int max = arr[0];
//    int i;
//    int x = sizeof(arr) / sizeof(arr[0]);//����Ԫ�ظ���
//    for (i = 1; i < x; i++)
//    {
//        if (max < arr[i])
//        {
//            max = arr[i];
//        }
//    }
//    printf("���ֵΪ%d\n", max);
//    return 0;
//}










////���9*9�ĳ˷��ھ���
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








////�������ųɼ�������ܷ֡�ƽ���֡���߷֡���ͷ�
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
//    printf("ƽ����Ϊ%.2f,����Ϊ%.2f\n", p, sum);
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
//    printf("�����Ϊ%.2f,��С��Ϊ%.2f\n", max, min);
//    return 0;
//}












////��ӡһ������
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










//��������Ϸ
//��������һ���������1-100

//rand������������stdlib.hͷ�ļ�
//����������0-32767֮��
//��ÿ������������ͬ����ʹ��srand���������������������

//srand���������stdlib.hͷ�ļ�
//void srand(unsigned int seed);
//��Ҫ���������������Ӧ����һ����ʱ�仯����(ʹ��ʱ���)

//�����time.hͷ�ļ�
//time()�����������������Ϊָ��
//NULL��ָ��
//�������س����ͣ���ǿ��ת��Ϊ�޷�������
//ʱ���-���������������������ʼ��
//��ǰ�������ʱ���ȥ���������ʼʱ��(1970.1.1.0:0:0)=(xxx)��

//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void menu()//�˵�
//{
//    printf("********************************************\n");
//    printf("********    1. play     0.exit     *********\n");
//    printf("********************************************\n");
//}
//void game()
//{
//    int ret;
//    int guess;//���ղµ�����
//    printf("��ʼ��������Ϸ\n");
//
//    ret =rand()%100+1;//rand-���������
//    //%100������0-99������
//    
//    while (1)
//    {
//        printf("������֣�\n");
//        scanf("%d", &guess);
//        if (guess > ret)
//        {
//            printf("�´��ˣ�\n");
//        }
//        else if (guess < ret) 
//        {
//            printf("��С��\n");
//        }
//        else//guess==ret
//        {
//            printf("��ϲ��¶���\n");
//            break;
//        }
//    }
//}
//int main()
//{
//    int input;
//    srand((unsigned int)time(NULL));//����������������� ֻ������һ��
//    do
//    {
//        menu();
//        printf("��ѡ��:\n");
//        scanf("%d", &input);
//        switch (input)
//        {
//        case 0:
//            printf("�˳���Ϸ��\n");
//            break;
//        case 1:
//            game();//��������Ϸ
//            break;
//        default:
//            printf("�������\n");
//        }
//    } while(input);
//    return 0;
//}












////����һ���ַ���ͳ�������ж��ٸ�����
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
//    printf("����%d������\n", word);
//    return 0;
//}







////���ܴ�����ʱ����(����������)��ʵ���������Ľ���

//�Ӽ������ɼ�������ķ�Χ��С(���ܻ����)
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

//���
//#include<stdio.h>
//int main()
//{
//    int a = 10;
//    int b = 20;
//    a = a ^ b;//��������������
//    b = a ^ b;//����������һ������������һ����
//    a = a ^ b;
//    printf("a=%d,b=%d\n", a, b);
//
//    return 0;
//}







//��д���룺��һ�������洢���ڴ��еĶ����Ƶĸ���

////ֻ�ܼ�������
//#include<stdio.h>
//int main()
//{
//    int num;
//    int count = 0;
//    scanf("%d", &num);
//    //ͳ��num�Ĳ�����1�ĸ���
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
//    //��num&1==1,��ônum�Ĳ�������һλһ����1
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




////������������
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




////�ڴ󲿷�����£�����������Ԫ�صĵ�ַ
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
//char* compare(char *p1,char *p2)//����С��
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
//    if (p1 == p2)//str1Ϊ��С
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
//    if (p2 == p3)//str3Ϊ��С
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
//    if (p1 == p3)//str2Ϊ��С
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
//char* compare(char* p1, char* p2)//����С��
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
//    printf("   ѧ��   | Ӣ�� | ��ѧ | C++  | ���� | ���� | ƽ��ֵ \n");
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
//    printf(" ƽ���ɼ� | ");
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
//    printf("ѧ����:");
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
//    printf("����������Ҫ�������ε����µױ߳�:");
//    scanf("%f%f", &sl, &xl);
//    printf("�������εĸߣ�");
//    scanf("%f", &high);
//    s = (sl + xl) * high / 2;
//    printf("���ε����Ϊ%.2f\n", s);
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
//    printf("�Ŀ��ܷ�Ϊ%.2f\n", sum);
//    printf("�Ŀ�ƽ����Ϊ%.2f\n", avg);
//    printf("�Ŀ���ͷ�Ϊ%.2f\n", min);
//    printf("�Ŀ���߷�Ϊ%.2f\n", max);
//    return 0;
//}





//#include<stdio.h>
//int main()
//{
//    int n, m;
//    int j, t;
//    printf("���뼦���õ�������:");
//    scanf("%d", &n);
//    printf("���뼦���õ��ܽ���:");
//    scanf("%d", &m);
//    t = (m - 2 * n) / 2;
//    j = n - t;
//    if ((m - 2 * n) % 2 == 0&& m<=4*n)
//    {
//        printf("��������Ϊ%d\n", j);
//        printf("�õ�����Ϊ%d\n", t);
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
//            printf("������%d\n", i);
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
//            printf("������%d\n", i);
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
//    printf("����������������:");
//    scanf("%f%f", &a, &b);
//    printf("�����������:");
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
//    printf("������Ϊ%.2f\n", ret);
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
//			printf("��%d�����:����:%d,����:%d,����:%d\n", count, i, j, k);
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
//                printf("1��%3d��  2��%3d��   5��%3d��\n", 100 - 2 * i - 5 * j, i, j);
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
//        printf("δ�ҵ�\n");
//    }
//    else
//    {
//        printf("�±�Ϊ%d\n", i);
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
//		printf("%d�ǻ�����", n);
//	}
//	else 
//	{
//		printf("%d���ǻ�����", n);
//	}
//}
//int main() 
//{
//	int n;
//	printf("��������Ҫ�����жϵ�����:");
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
//    printf("ѧ����:");
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
//int binery_search(int arr[1000],int k,int sz) //����ҵ��˷�����������±꣬�Ҳ�������-1
//{
//    int left = 0;   
//    int right = sz - 1;
//    while (left<=right)
//    {
//        int mid = (left + right) / 2;//�м�Ԫ�ص��±�
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
//    int k;//Ҫ�ҵ���
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
//    1.�Ͽ�ָ���붯̬���ٵĿռ����ϵ������ָ���Σ�ղ���
//    2.��ֹ��ͬһ�鶯̬�ռ��ڴ�ռ���ظ��ͷ�
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
//        printf("%d ", *(p++));//����ָ���ƶ�
//    }
//    free(p);//����free�ͷŵĲ��ǳ�ʼλ�õ�ָ�룬�������
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
//    //��arr�����ڴ�20���ֽڵĿռ�
//    if (ps == NULL)
//    {
//        return 1;
//    }
//
//    //��������������������
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
//    printf("��left = %d", left);
//    printf("��right = %d", right);
//    return 0;
//}



//#include<stdio.h>
//#define TEST(x) ++x
//int main()
//{
//    int num = 0;
//    TEST(num);//�滻 ��++num;
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




//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������
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







/*дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
arr��һ������һά���顣*/
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








//дһ����������������һ���ַ��������ݡ�
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




//��ӡ����13�����15��
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



/*���0��100000֮������С�ˮ�ɻ������������
��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ���������:153��1^3��5^3��3^3����153��һ����ˮ�ɻ�������*/
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
//			printf("%d��ˮ�ɻ���\n", i);
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



/*����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣���*/
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
//	printf("���Ժ�%dƿ��ˮ\n", count);
//	return 0;
//}





//��ѭ��
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
����һ���������飬ʵ��һ��������

�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�

����ż��λ������ĺ�벿�֡�
*/
//#include<stdio.h>
//#include<stdlib.h>
//void adjust(int* arr,int size)
//{
//	int begin = 0, end = size - 1;
//	while (begin < end)
//	{
//		while (begin < end && *(arr + begin) % 2 == 1)//��Ϊ�����������Ѱ��ż��
//		{
//			++begin;
//		}
//		while (begin < end && *(arr + end) % 2 == 0)//��Ϊż��������ǰѰ������
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



//ģ��strcpyʵ��
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



//ģ��strlenʵ��
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



//��߷ֺ���ͷ�֮��
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



//���������ж�
//#include <stdio.h>
//int judge(int* arr, int size)
//{
//    int flag = 0;
//    if (arr[0] < arr[1])
//        flag = 1;
//
//    for (int i = 0; i < size - 1; ++i)
//    {
//        if (flag == 1)//����
//        {
//            if (arr[i] > arr[i + 1])
//                return 0;
//        }
//        if (flag == 0)//����
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
//int GetMid(int* arr, int left, int right)//����ȡ��
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
//	//����n��m
//	scanf("%d %d", &n, &m);
//	int i = 0;
//	int j = 0;
//	//����������������
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
5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������



Aѡ��˵��B�ڶ����ҵ�����

Bѡ��˵���ҵڶ���E���ģ�

Cѡ��˵���ҵ�һ��D�ڶ���

Dѡ��˵��C����ҵ�����

Eѡ��˵���ҵ��ģ�A��һ��

����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
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
////�򻯺�:
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
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
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
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0;
//}




//#include<stdio.h>
//int main()
//{
//	char a = 5;  //  5�Ĳ���Ϊ:00000000 00000000 00000000 00000101   �ضϺ���һ���ֽ�Ϊ:00000101
//	char b = 126;//126�Ĳ���Ϊ:00000000 00000000 00000000 01111110   �ضϺ���һ���ֽ�Ϊ:01111110
//
//	char c = a + b;//��ʱa + b���м��㣬������������
//				//00000000 00000000 00000000 00000101
//				//00000000 00000000 00000000 01111110
//		 //��ӵ�:00000000 00000000 00000000 10000011
//		 //����char���ͱ����������ض�,����һ���ֽ�Ϊ:10000011
//
//	printf("%d\n", c);//��ʮ���Ʒ�ʽ��ӡsigned char(�з���)�������ݣ�������������
//					  //����:11111111 11111111 11111111 10000011
//					  //����:11111111 11111111 11111111 10000010
//					  //ԭ��:10000000 00000000 00000000 01111101
//					  //�����-125
//	return 0;
//}






/*
��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�

Ҫ��ʱ�临�Ӷ�С��O(N);
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
//		printf("�ҵ��������\n");
//	else
//		printf("û�ҵ������\n");
//	return 0;
//}






/*
ʵ��һ�����������������ַ����е�k���ַ���
���磺
ABCD����һ���ַ��õ�BCDA

ABCD���������ַ��õ�CDAB
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
дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
���磺����s1 =AABCD��s2 = BCDAA������1

����s1=abcd��s2=ACBD������0.
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
//		printf("str2����str1��ת�õ�\n");
//	else
//		printf("str2������str1��ת�õ�\n");
//	return 0;
//}
