#ifndef __BOOM_H__
#define __BOOM_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS (ROW + 2)
#define COLS (COL + 2)

#define EASY_MODE_NUM 10

void initBoard(char board[ROWS][COLS],int row,int col,char set);
void displayBoard(char board[ROWS][COLS],int row,int col);
void arrangeBoomPos(char board[ROWS][COLS],int row,int col);
int boomNumAroundCurrentPos(char mine[ROWS][COLS], int row, int col);
void findBoom(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

#endif
