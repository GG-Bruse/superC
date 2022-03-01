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
	//我可见
	char mine[ROWS][COLS]={0};
	//用户可见
	char show[ROWS][COLS] = {0};
	//初始化
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//打印
	Displayboard(show, ROW, COL);
	//布置雷
	Setmine(mine,ROW,COL);
	//扫雷
	Findmine(mine,show,ROW,COL);
}




void test()
{
	int input;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			system("cls");
			game();
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
}


int main()
{
	test();

	return 0;
}