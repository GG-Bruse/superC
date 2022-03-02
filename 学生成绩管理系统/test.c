#define _CRT_SECURE_NO_WARNINGS


#include"test.h"
typedef struct student
{
	char name[20];
	int math, english, chinese, total;
}stu;
stu s[N];
int length;


//����
void cs()
{
	int i;
	printf("����0������ҳ:");
	scanf("%d", &i);
	printf("������ҳ��");
	for (i = 0; i < 6; i++)
	{
		Sleep(400);
		printf(".");
	}
	system("cls");
}


//����ѧ���ɼ�
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


//��ѧ���ɼ�д���ļ�(����)
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



//���ѧ���ɼ�
void Addstudent()
{
	stu t;
	printf("������ѧ������:");
	scanf("%s", t.name);
	printf("�������ѧ�������ųɼ�(�������):");
	scanf("%d%d%d", &t.chinese, &t.math, &t.english);
	t.total = t.chinese + t.math + t.english;
	s[length++] = t;
	Savefile();
	printf("\n��ӳɼ���Ŀǰ��%d������\n", length);
	cs();
}



//ɾ��ѧ���ɼ�
void Delstudent()
{
	char name[20] = {'\0'};
	int i;
	printf("������Ҫɾ��ѧ��������:");
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
	printf("ɾ���ɹ���Ŀǰ��%d������\n", length);
	cs();
}


//�޸�ѧ���ɼ�
void Moditystudent()
{
	stu t;
	int i;
	printf("������Ҫ�޸ĳɼ���ѧ��������:");
	scanf("%s", &t.name);
	printf("�������ѧ���ĳɼ�(�������):");
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
	printf("\n�޸ĳɹ���Ŀǰ��%d������\n", length);
	cs();
}



//����ѧ��������ѯ�ɼ�
void Searchstudent()
{
	char name[20] = {'\0'};
	int i;
	int flag = 0;
	printf("������Ҫ����ѧ��������:");
	scanf("%s",name);
	system("cls");
	for (i = 0; i < length; i++)
	{
		if (strcmp(s[i].name, name) == 0)
		{
			printf("ѧ������:%s\n", s[i].name);
			printf("����:%d\n", s[i].chinese);
			printf("��ѧ:%d\n", s[i].math);
			printf("Ӣ��:%d\n", s[i].english);
			printf("�ܷ�Ϊ:%d\n",s[i].total);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf("�޴���ѧ������Ϣ��\n");
	}
	cs();
}

//�ֱ�ͳ�Ʋ����ÿ�Ź��ε�ƽ���ɼ�
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
	printf("\t\t���ųɼ���ƽ���ֱַ�Ϊ:\n");
	printf("\t\t����ƽ����Ϊ%5.2f:\n", chinesesum / length);
	printf("\t\t��ѧƽ����Ϊ%5.2f:\n",mathsum/length);
	printf("\t\tӢ��ƽ����Ϊ%5.2f:\n", mathsum / length);
	cs();
}


//���ѧ���ɼ�
void Dispstudent() 
{
	int i;
	printf("\n");
	printf("\t\t|ѧ������|��ѧ|����|Ӣ��|�ܷ�|\n");
	for (i = 0; i < length; i++)
	{
		printf("\t\t|%-8s|%4d|%4d|%4d|%4d|\n", s[i].name, s[i].math, s[i].chinese, s[i].english, s[i].total);
	}
	cs();
}


//�����ֽܷ���
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
	printf("\t\t********    ���ִܷӴ�С����    ********\n");
	Dispstudent();
	Savefile();
}

//�����ܷ�����
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
	printf("\t\t********    ��������ĸ����    ******   \n");
	Dispstudent();
	Savefile();
}






















