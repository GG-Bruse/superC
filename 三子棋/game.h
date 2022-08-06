#define _CRT_SECURE_NO_WARNINGS

#define MAX_ROW 3
#define MAX_COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(char chessBoard[MAX_ROW][MAX_COL]);
void print_chessBoard(char chessBoard[MAX_ROW][MAX_COL]);
void playerMove(char chessBoard[MAX_ROW][MAX_COL]);
void computerMove(char chessBoard[MAX_ROW][MAX_COL]);
char isWin(char chessBoard[MAX_ROW][MAX_COL]);