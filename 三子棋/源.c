#define _CRT_SECURE_NO_WARNINGS

//测试三子棋游戏

#include<stdio.h>
#include"game.h"

void menu()
{
	printf("***************************\n");
	printf("***   1.play    0.exit  ***\n");
	printf("***************************\n");
}

//整个游戏算法的实现
void game()
{
	char ret=0;
	//创建3*3数组，存放玩家和电脑的对弈信息
	char board[ROW][COL] = { {' ',' ',' ','\0'},{' ',' ',' ','\0'},{' ',' ',' ','\0'}};
	//初始棋盘
	//InitBoard(board,ROW,COL);//全部为空
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		Playermove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret=Iswin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		Computermove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret=Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家获胜\n");
	}
	else if (ret == '#')
	{
		printf("电脑获胜\n");
	}
	else//ret == 'Q'
	{
		printf("平局\n");
	}
}

void test()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}



int main()
{
	test();
	return 0;
}








































