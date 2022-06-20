#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define NUM 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_board(char board[ROWS][COLS], int row, int col,char n);

void print_board(char board[ROWS][COLS], int row, int col);

void Set_Mine(char board[ROWS][COLS], int row, int col,int num);

void find_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);