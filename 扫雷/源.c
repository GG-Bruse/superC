#define _CRT_SECURE_NO_WARNINGS


#include "game.h"

void menu()
{
	printf("********************************\n");
	printf("************  1.play  **********\n");
	printf("************  0.exit  **********\n");
	printf("********************************\n");
}

void game()
{
	//�ҿɼ�
	char mine[ROWS][COLS]={0};
	//�û��ɼ�
	char show[ROWS][COLS] = {0};
	//��ʼ��
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//��ӡ
	Displayboard(show, ROW, COL);
	//������
	Setmine(mine,ROW,COL);
	//ɨ��
	Findmine(mine,show,ROW,COL);
}




void test()
{
	int input;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			system("cls");
			game();
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
}


int main()
{
	test();

	return 0;
}