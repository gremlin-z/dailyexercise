#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear(char board[ROW][COL], int row, int col);

void print_board(char board[ROW][COL], int row, int col);

void person_print(char board[ROW][COL], int row, int col);

void computer_print(char board[ROW][COL], int row, int col);

char is_win(char board[ROW][COL], int row, int col);