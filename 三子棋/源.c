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
		printf("恭喜您, 您赢了!\n");
	}
	else if (winner == 'o')
	{
		printf("哈哈，您连人工智障都下不过!\n");
	}
	else
	{
		printf("您只能和人工智障打平手!!\n");
	}
}

int menu()
{
	printf("--------------------------\n");
	printf("--------1.开始游戏--------\n");
	printf("--------0.退出游戏--------\n");
	printf("--------------------------\n");
	int choice = 0;
	printf("请输入你的选择：");
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
			printf("退出游戏,GOODBYE!!!!!\n");
			break;
		}
		else
		{
			printf("输入错误！请重新输入！\n");
			continue;
		}
	}
	return 0;
}























