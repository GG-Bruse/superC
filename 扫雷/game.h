#define ROW 9//行
#define COL 9//列

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10//十个雷



#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);

void Displayboard(char board[ROWS][COLS],int row,int col);

void Setmine(char board[ROWS][COLS],int row,int col);

void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);









