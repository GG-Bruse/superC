#define _CRT_SECURE_NO_WARNINGS
#include"game.h"



void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i, j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = set;
		}
	}
}





void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 1, j = 1;
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}





void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row+1;//使其余数位于1-9之间
		int y = rand() % col+1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}










//字符3减去字符0得到数字3
//字符1减去字符0得到数字1
//mine数组初始化元素都为字符0，放置雷为字符元素1，将八个位置的字符元素相加转化为数字即为周围的雷的个数

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}





void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win=0;
	printf("请输入所要排查雷的坐标\n");
	while (win<row*col- EASY_COUNT)//排完雷退出
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')//踩雷
			{
				printf("很遗憾你被炸死了\n");
				Displayboard(mine, ROW, COL);
				break;
			}
			else//不是雷
			{
				//计算x,y坐标周围雷的个数
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';//将数字转化为字符放入数组中
				system("cls");
				Displayboard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你排雷成功\n");
		Displayboard(mine, ROW, COL);
	}
}
























