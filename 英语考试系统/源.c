#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void read();
void readfile();
void part1();
void part2();
void part3();
void Part1ting(int a, char arr[20], char brr[20], char crr[20]);
void Part2reading(int a);
void Part2reading1(int a);

char s1[4][25][200];
char s2[4][45][200];
char s3[4][35][200];
char r1[4][22][200];
char r1a[4][10][20];
char r2[4][58][200];
char r2a[4][2][6];
char A[20];

int main()
{
	read();
	readfile();
	srand((unsigned int)time(NULL));//重新播种
	while (1)
	{
		int XuanXiang = 0;
		printf("\t\t===========================================\n");
		printf("\t\t||            英语试题专项训练           ||\n");
		printf("\t\t===========================================\n");
		printf("\t\t||            1.英语随机出卷             ||\n");
		printf("\t\t||            2.听力专练                 ||\n");
		printf("\t\t||            3.完型专练                 ||\n");
		printf("\t\t||            4.阅读专练                 ||\n");
		printf("\t\t||            0.保存数据、退出系统       ||\n");
		printf("\t\t===========================================\n");
		printf("\t\t请输入您的选择:");
		scanf("%d", &XuanXiang);
		system("cls");//每输一次清屏一次
		switch (XuanXiang)
		{
		case 1:part1(); part2(); part3(); break;
		case 2:part1(); break;
		case 3:part2(); break;
		case 4:part3(); break;
		case 0:return 0;
		default:printf("\n\t\t没有这一选项!请重新选择!\n\n");
		}
	}
	return 0;
}

void read()
{
	FILE* fp;
	if ((fp = fopen("试题库.txt", "r")) == NULL)
	{
		printf("打开文件失败!\a\n");
		fclose(fp);
		exit(0);
	}
	printf("打开文件成功!\n");
	fclose(fp);
}

void readfile()
{
	int i, j;
	FILE* fp;
	fp = fopen("试题库.txt", "r");
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 25; i++)
			fgets(s1[j][i], sizeof(s1[0][0]) / sizeof(s1[0][0][0]), fp);
		for (i = 0; i < 45; i++)
			fgets(s2[j][i], sizeof(s2[0][0]) / sizeof(s2[0][0][0]), fp);
		for (i = 0; i < 35; i++)
			fgets(s3[j][i], sizeof(s3[0][0]) / sizeof(s3[0][0][0]), fp);
	}
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 22; i++)
			fgets(r1[j][i], sizeof(r1[0][0]) / sizeof(r1[0][0][0]), fp);
		for (i = 0; i < 10; i++)
		{
			fscanf(fp, "%s", r1a[j][i]);
			fseek(fp, 1L, 1);
		}
	}
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 58; i++)
			fgets(r2[j][i], sizeof(r1[0][0]) / sizeof(r1[0][0][0]), fp);
		for (i = 0; i < 2; i++)
		{
			fscanf(fp, "%s", r2a[j][i]);
			fseek(fp, 1L, 1);
		}
	}
}

void part1()
{
	int x, a = 1;
	static int y1 = 4, y2 = 4, y3 = 4;
	while (a)
	{
		x = rand() % 4;
		if (x == y1 || x == y2 || x == y3) continue;
		else y3 = y2, y2 = y1, y1 = x, a = 0;
		switch (x)
		{
		case 0:Part1ting(0, "CADD", "BBCADCAD", "DACCDD"); break;
		case 1:Part1ting(1, "BDDC", "BBCDACBA", "CDADAC"); break;
		case 2:Part1ting(2, "CBBD", "DACDBACB", "CBAADC"); break;
		case 3:Part1ting(3, "CBCB", "ADBDBACC", "CDDCBA"); break;
		}
	}
}

void part2()
{
	int x, a = 1;
	static int y1 = 4, y2 = 4, y3 = 4;
	while (a)
	{
		x = rand() % 4;
		if (x == y1 || x == y2 || x == y3) continue;
		else y3 = y2, y2 = y1, y1 = x, a = 0;
		switch (x)
		{
		case 0:Part2reading(0); break;
		case 1:Part2reading(1); break;
		case 2:Part2reading(2); break;
		case 3:Part2reading(3); break;
		}
	}
}

void part3()
{
	int x, a = 1;
	static int y1 = 4, y2 = 4, y3 = 4;
	while (a)
	{
		x = rand() % 4;
		if (x == y1 || x == y2 || x == y3) continue;
		else y3 = y2, y2 = y1, y1 = x, a = 0;
		switch (x)
		{
		case 0:Part2reading1(0); break;
		case 1:Part2reading1(1); break;
		case 2:Part2reading1(2); break;
		case 3:Part2reading1(3); break;
		}
	}
}

void Part1ting(int a, char arr[20], char brr[20], char crr[20])
{
	int i;
	for (i = 0; i < 25; i++)
		fputs(s1[a][i], stdout);
	printf("\n请输入正确答案:");
	scanf("%s", A);
	if (strcmp(A, arr) == 0)
		printf("\n恭喜你!回答正确!\n\n");
	else
	{
		printf("\n回答错误!正确答案:%s\a\n\n", arr);
		Sleep(1 * 1000);
		printf("查看完答案请按下↓键进入下一题!\n");
		while (1) if (GetAsyncKeyState(VK_DOWN) & 0x8000) break;
	}

	for (i = 0; i < 45; i++)
		fputs(s2[a][i], stdout);
	printf("\n请输入正确答案:");
	scanf("%s", A);
	if (strcmp(A, brr) == 0)
		printf("\n恭喜你!回答正确!\n\n");
	else
	{
		printf("\n回答错误!正确答案:%s\a\n\n", brr);
		Sleep(1 * 1000);
		printf("查看完答案请按下↓键进入下一题!\n");
		while (1) if (GetAsyncKeyState(VK_DOWN) & 0x8000) break;
	}

	for (i = 0; i < 35; i++)
		fputs(s3[a][i], stdout);
	printf("\n请输入正确答案:");
	scanf("%s", A);
	if (strcmp(A, crr) == 0)
		printf("\n恭喜你!回答正确!\n\n");
	else
	{
		printf("\n回答错误!正确答案:%s\a\n\n", crr);
		Sleep(1 * 1000);
		printf("查看完答案请按下↓键进入下一题!\n");
		while (1) if (GetAsyncKeyState(VK_DOWN) & 0x8000) break;
	}
}

void Part2reading(int a)
{
	int i, j, x, y[9], z;
	char ca[11], cr[11];
	for (i = 0; i < 22; i++)
		fputs(r1[a][i], stdout);
	printf("\n\t-----------------------------------------------------------------------------------------\n\t");
	for (i = 0; i < 10; i++)
	{
		z = 0;
		x = rand() % 10;
		for (j = 0; j < i; j++)//第一次没有记录的数据，直接跳过
			if (x == y[j])//与记录下的数据对比，防止重复出现
				z = 1;
		if (z)
		{
			i--;
			continue;//发现重复直接跳过
		}
		else
		{
			for (j = 0; j < 8; j++)//记录下每一次循环过的数据
			{
				y[8 - j] = y[7 - j];
			}
			y[0] = x;
		}
		ca[x] = i + 65;//绑定答案与输出顺序
		if (i % 4 != 3)
			printf("|%c%-20s", i + 65, r1a[a][x]);
		else
			printf("|%c%-20s|\n\t", i + 65, r1a[a][x]);
	}
	printf("\n\t-----------------------------------------------------------------------------------------\n");
	printf("\n请输入正确答案:");

	ca[10] = '\0';//将字符改为字符串，进行比较

	scanf("%s", cr);
	if (strcmp(cr, ca) == 0)
		printf("\n恭喜你!回答正确!\n\n");
	else
	{
		printf("\n回答错误!正确答案:%s\a\n\n", ca);
		Sleep(1 * 1000);
		printf("查看完答案请按下↓键进入下一题!\n");
		while (1) if (GetAsyncKeyState(VK_DOWN) & 0x8000) break;
	}
}

void Part2reading1(int a)
{
	int i;
	char cr[6];
	for (i = 0; i < 31; i++)
		fputs(r2[a][i], stdout);
	printf("\n请输入正确答案:");
	scanf("%s", cr);
	if (strcmp(cr, r2a[a][0]) == 0)
		printf("\n恭喜你!回答正确!\n\n");
	else
	{
		printf("\n回答错误!正确答案:%s\a\n\n", r2a[a][0]);
		Sleep(1 * 1000);
		printf("查看完答案请按下↓键进入下一题!\n");
		while (1) if (GetAsyncKeyState(VK_DOWN) & 0x8000) break;
	}
	for (i = 31; i < 58; i++)
		fputs(r2[a][i], stdout);
	printf("\n请输入正确答案:");
	scanf("%s", cr);
	if (strcmp(cr, r2a[a][1]) == 0)
		printf("\n恭喜你!回答正确!\n\n");
	else
	{
		printf("\n回答错误!正确答案:%s\a\n\n", r2a[a][1]);
		Sleep(1 * 1000);
		printf("查看完答案请按下↓键进入下一题!\n");
		while (1) if (GetAsyncKeyState(VK_DOWN) & 0x8000) break;
	}
}



