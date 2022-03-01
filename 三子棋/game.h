#define ROW 3//行
#define COL 3//列

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//函数声明
void InitBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void Playermove(char board[ROW][COL], int row, int col);

void Computermove(char board[ROW][COL], int row, int col);

char Iswin(char board[ROW][COL],int row,int col);
//四种状态
//玩家赢 "*"
//电脑赢 "#"
//平局   "Q"
//继续   "C"


