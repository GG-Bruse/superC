#define _CRT_SECURE_NO_WARNINGS

//������������Ϸ

#include<stdio.h>
#include"game.h"

void menu()
{
	printf("***************************\n");
	printf("***   1.play    0.exit  ***\n");
	printf("***************************\n");
}

//������Ϸ�㷨��ʵ��
void game()
{
	char ret=0;
	//����3*3���飬�����Һ͵��ԵĶ�����Ϣ
	char board[ROW][COL] = { {' ',' ',' ','\0'},{' ',' ',' ','\0'},{' ',' ',' ','\0'}};
	//��ʼ����
	//InitBoard(board,ROW,COL);//ȫ��Ϊ��
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����
	while (1)
	{
		//�������
		Playermove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret=Iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		Computermove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret=Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��һ�ʤ\n");
	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ\n");
	}
	else//ret == 'Q'
	{
		printf("ƽ��\n");
	}
}

void test()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}



int main()
{
	test();
	return 0;
}








































