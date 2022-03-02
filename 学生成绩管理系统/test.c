#define _CRT_SECURE_NO_WARNINGS


#include"test.h"
typedef struct student
{
	char name[20];
	int math, english, chinese, total;
}stu;
stu s[N];
int length;


//清屏
void cs()
{
	int i;
	printf("输入0返回主页:");
	scanf("%d", &i);
	printf("返回首页中");
	for (i = 0; i < 6; i++)
	{
		Sleep(400);
		printf(".");
	}
	system("cls");
}


//读出学生成绩
int Readfile()
{
	FILE* fp;
	int i=0;
	length = 0;
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		fp = fopen("student.txt", "w+");
		fclose(fp);
		return 0;
	}
	for (; !feof(fp); length++)
	{
		fscanf(fp, "%s", s[length].name);
		fscanf(fp, "%d", &s[length].chinese);
		fscanf(fp, "%d", &s[length].math);
		fscanf(fp, "%d", &s[length].english);
		fscanf(fp, "%d", &s[length].total);
	}
	fclose(fp);
	return 0;
}


//将学生成绩写入文件(保存)
void Savefile()
{
	FILE* fp;
	int i;
	fp = fopen("student.txt", "w");
	for (i = 0; i < length; i++)
	{
		fprintf(fp, "%s ", s[i].name);
		fprintf(fp, "%d ", s[i].chinese);
		fprintf(fp, "%d ", s[i].math);
		fprintf(fp, "%d ", s[i].english);
		fprintf(fp, "%d", s[i].total);
	}
	fclose(fp);
	if (length == 0)
	{
		remove("student.txt");
	}
}



//添加学生成绩
void Addstudent()
{
	stu t;
	printf("请输入学生姓名:");
	scanf("%s", t.name);
	printf("请输入该学生的三门成绩(语、数、外):");
	scanf("%d%d%d", &t.chinese, &t.math, &t.english);
	t.total = t.chinese + t.math + t.english;
	s[length++] = t;
	Savefile();
	printf("\n添加成绩！目前共%d条数据\n", length);
	cs();
}



//删除学生成绩
void Delstudent()
{
	char name[20] = {'\0'};
	int i;
	printf("请输入要删除学生的姓名:");
	scanf("%s", name);
	for (i = 0; i < length; i++)
	{
		if (strcmp(s[i].name, name) == 0)
		{
			break;
		}
	}
	for (; i < length - 1; i++)
	{
		s[i] = s[i + 1];
	}
	length--;
	Savefile();
	printf("删除成功！目前共%d条数据\n", length);
	cs();
}


//修改学生成绩
void Moditystudent()
{
	stu t;
	int i;
	printf("请输入要修改成绩的学生的姓名:");
	scanf("%s", &t.name);
	printf("请输入该学生的成绩(语、数、外):");
	scanf("%d%d%d", &t.chinese, &t.math, &t.english);
	t.total = t.chinese + t.math + t.english;
	for (i = 0; i < length; i++)
	{
		if (strcmp(s[i].name, t.name) == 0)
		{
			break;
		}
	}
	s[i] = t;
	Savefile();
	printf("\n修改成功！目前共%d条数据\n", length);
	cs();
}



//根据学生姓名查询成绩
void Searchstudent()
{
	char name[20] = {'\0'};
	int i;
	int flag = 0;
	printf("请输入要查找学生的姓名:");
	scanf("%s",name);
	system("cls");
	for (i = 0; i < length; i++)
	{
		if (strcmp(s[i].name, name) == 0)
		{
			printf("学生姓名:%s\n", s[i].name);
			printf("语文:%d\n", s[i].chinese);
			printf("数学:%d\n", s[i].math);
			printf("英文:%d\n", s[i].english);
			printf("总分为:%d\n",s[i].total);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf("无此名学生的信息！\n");
	}
	cs();
}

//分别统计并输出每门功课的平均成绩
void Avg()
{
	double chinesesum, mathsum, englishsum;
	int i;
	chinesesum = mathsum = englishsum = 0;
	for (i = 0; i < length; i++)
	{
		chinesesum += s[i].chinese;
		mathsum += s[i].math;
		englishsum += s[i].english;
	}
	printf("\t\t三门成绩的平均分分别为:\n");
	printf("\t\t语文平均分为%5.2f:\n", chinesesum / length);
	printf("\t\t数学平均分为%5.2f:\n",mathsum/length);
	printf("\t\t英语平均分为%5.2f:\n", mathsum / length);
	cs();
}


//输出学生成绩
void Dispstudent() 
{
	int i;
	printf("\n");
	printf("\t\t|学生姓名|数学|语文|英语|总分|\n");
	for (i = 0; i < length; i++)
	{
		printf("\t\t|%-8s|%4d|%4d|%4d|%4d|\n", s[i].name, s[i].math, s[i].chinese, s[i].english, s[i].total);
	}
	cs();
}


//按照总分降序
void Sortj()
{
	int i, j, max, k;
	stu t;
	for (i = 0; i < length - 1; i++)
	{
		max = s[i].total, k = i;
		for (j = i + 1; j < length; j++)
			if (max < s[j].total)
			{
				max = s[j].total, k = j;
			}
		t = s[i]; s[i] = s[k]; s[k] = t;
	}
	printf("\t\t********    按总分从大到小排序    ********\n");
	Dispstudent();
	Savefile();
}

//按照总分升序
void Sorts()
{
	int i, j, k;
	char min[20];
	stu t;
	for (i = 0; i < length - 1; i++)
	{
		strcpy(min, s[i].name), k = i;
		for (j = i + 1; j < length; j++)
			if (strcmp(min, s[j].name) > 0)
				strcpy(min, s[j].name), k = j;
		t = s[i]; s[i] = s[k]; s[k] = t;
	}
	printf("\t\t********    按姓名字母升序    ******   \n");
	Dispstudent();
	Savefile();
}






















