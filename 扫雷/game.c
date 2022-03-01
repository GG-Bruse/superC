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
	//��ӡ�к�
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ�к�
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
		int x = rand() % row+1;//ʹ������λ��1-9֮��
		int y = rand() % col+1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}










//�ַ�3��ȥ�ַ�0�õ�����3
//�ַ�1��ȥ�ַ�0�õ�����1
//mine�����ʼ��Ԫ�ض�Ϊ�ַ�0��������Ϊ�ַ�Ԫ��1�����˸�λ�õ��ַ�Ԫ�����ת��Ϊ���ּ�Ϊ��Χ���׵ĸ���

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
	printf("��������Ҫ�Ų��׵�����\n");
	while (win<row*col- EASY_COUNT)//�������˳�
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')//����
			{
				printf("���ź��㱻ը����\n");
				Displayboard(mine, ROW, COL);
				break;
			}
			else//������
			{
				//����x,y������Χ�׵ĸ���
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';//������ת��Ϊ�ַ�����������
				system("cls");
				Displayboard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("��������Ƿ�������������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�����׳ɹ�\n");
		Displayboard(mine, ROW, COL);
	}
}
























