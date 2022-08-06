#include "game.h"

void init(char chessBoard[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			chessBoard[row][col] = ' ';
		}
	}
}

void print_chessBoard(char chessBoard[MAX_ROW][MAX_COL])
{
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf("| %c | %c | %c |\n", chessBoard[row][0],
			chessBoard[row][1], chessBoard[row][2]);
		printf("+---+---+---+\n");
	}
}

void playerMove(char chessBoard[MAX_ROW][MAX_COL])
{
	while (1)
	{
		int row = 0;
		int col = 0;
		printf("请输入坐标（row col）：");
		scanf("%d %d", &row, &col);
		row -= 1, col -= 1;
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL)
		{
			printf("您的坐标不在合法范围内 [0, 2],请重新输入：\n");
			continue;
		}
		if (chessBoard[row][col] != ' ')
		{
			printf("您的坐标位置已经有子了!\n");
			continue;
		}
		chessBoard[row][col] = 'x';
		break;
	}
}

void computerMove(char chessBoard[MAX_ROW][MAX_COL])
{
	while (1)
	{
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chessBoard[row][col] != ' ')
		{
			continue;
		}
		chessBoard[row][col] = 'o';
		break;
	}
}

int isFull(char chessBoard[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			if (chessBoard[row][col] == ' ')
			{
				return 0;
			}

		}
	}
	return 1;
}

char isWin(char chessBoard[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++)
	{
		if (chessBoard[row][0] != ' ' && chessBoard[row][0] == chessBoard[row][1] && chessBoard[row][0] == chessBoard[row][2])
		{
			return chessBoard[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; col++)
	{
		if (chessBoard[0][col] != ' ' && chessBoard[0][col] == chessBoard[1][col] && chessBoard[0][col] == chessBoard[2][col])
		{
			return chessBoard[0][col];
		}
	}
	if (chessBoard[0][0] != ' ' && chessBoard[0][0] == chessBoard[1][1] && chessBoard[0][0] == chessBoard[2][2])
	{
		return chessBoard[0][0];
	}
	if (chessBoard[2][0] != ' ' && chessBoard[2][0] == chessBoard[1][1] && chessBoard[2][0] == chessBoard[0][2])
	{
		return chessBoard[2][0];
	}
	if (isFull(chessBoard))
	{
		return 'q';
	}
	return ' ';
}





