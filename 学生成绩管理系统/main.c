#define _CRT_SECURE_NO_WARNINGS

#include"test.h"
void menu()
{
	printf("\n\t\t\t======��ӭʹ��ѧ���ɼ�����ϵͳ======\n");
	printf("\t\t\t1.���ѧ���ɼ�      2.ɾ��ѧ���ɼ�\n");
	printf("\t\t\t3.�޸�ѧ���ɼ�      4.��ѯѧ���ɼ�\n");
	printf("\t\t\t5.ͳ��ѧ���ɼ�      6.��ʾѧ����Ϣ\n");
	printf("\t\t\t7.�����ܷ�����      8.������������\n");
	printf("\t\t\t\t0.�������ݡ��˳�����\n\n");
	printf("\t\t\t����������ѡ��:");
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
			printf("���˳�ϵͳ����ӭ�´�ʹ�ã�\n");
			return 0;
		default:
			printf("�������,���������룡\n");
		}
	}
}
int main()
{
	test();
	return 0;
}



























