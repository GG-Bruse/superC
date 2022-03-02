#define _CRT_SECURE_NO_WARNINGS

#include"test.h"
void menu()
{
	printf("\n\t\t\t======欢迎使用学生成绩管理系统======\n");
	printf("\t\t\t1.添加学生成绩      2.删除学生成绩\n");
	printf("\t\t\t3.修改学生成绩      4.查询学生成绩\n");
	printf("\t\t\t5.统计学生成绩      6.显示学生信息\n");
	printf("\t\t\t7.按照总分排序      8.按照名字排序\n");
	printf("\t\t\t\t0.保存数据、退出程序\n\n");
	printf("\t\t\t请输入您的选择:");
}
int test()
{
	Readfile();
	int input;
	while (1)
	{
		menu();
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			Addstudent();
			break;
		case 2:
			Delstudent();
			break;
		case 3:
			Moditystudent();
			break;
		case 4:
			Searchstudent();
			break;
		case 5:
			Avg();
			break;
		case 6:
			Dispstudent();
			break;
		case 7:
			Sortj();
			break;
		case 8:
			Sorts();
			break;
		case 0:
			Savefile();
			printf("已退出系统，欢迎下次使用！\n");
			return 0;
		default:
			printf("输入错误,请重新输入！\n");
		}
	}
}
int main()
{
	test();
	return 0;
}



























