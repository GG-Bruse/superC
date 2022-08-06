#define _CRT_SECURE_NO_WARNINGS

#include"game.h"




void game()
{
	char chessBoard[MAX_ROW][MAX_COL] = { 0 };
	init(chessBoard);
	char winner = ' ';
	while (1)
	{
		system("cls");
		print_chessBoard(chessBoard);
		playerMove(chessBoard);
		winner = isWin(chessBoard);
		if (winner != ' ')
		{
			break;
		}
		computerMove(chessBoard);
		winner = isWin(chessBoard);
		if (winner != ' ')
		{
			break;
		}
	}
	print_chessBoard(chessBoard);
	if (winner == 'x')
	{
		printf("��ϲ��, ��Ӯ��!\n");
	}
	else if (winner == 'o')
	{
		printf("�����������˹����϶��²���!\n");
	}
	else
	{
		printf("��ֻ�ܺ��˹����ϴ�ƽ��!!\n");
	}
}

int menu()
{
	printf("--------------------------\n");
	printf("--------1.��ʼ��Ϸ--------\n");
	printf("--------0.�˳���Ϸ--------\n");
	printf("--------------------------\n");
	int choice = 0;
	printf("���������ѡ��");
	scanf("%d", &choice);
	return choice;
}
int main()
{
	srand((unsigned int)time(0));
	while (1)
	{
		int choice = menu();
		if (choice == 1)
		{
			game();
		}
		else if (choice == 0)
		{
			printf("�˳���Ϸ,GOODBYE!!!!!\n");
			break;
		}
		else
		{
			printf("����������������룡\n");
			continue;
		}
	}
	return 0;
}























