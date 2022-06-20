#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void clear_board(char board[ROWS][COLS], int row, int col,char n) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			if (board[i][j] == 0) {
				board[i][j] = n;
			}
		}
	}
}

void print_board(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	for (i = 0; i <= row; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		int j = 0;
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void Set_Mine(char board[ROWS][COLS], int row, int col,int num) {
	while (num) {
		int x = rand() % row + 1, y = rand() % col + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			num--;
		}
	}
}

int count_Mine(char board[ROWS][COLS], int x, int y) {
	int count=0;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			count += board[i][j];
		}
	}
	return count - 9 * '0';
}

void clear_show(char show[ROWS][COLS],char mine[ROWS][COLS], int x, int y) {
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL) // µÝ¹é·ÀÖ¹Ô½½ç
	{
		/*if (mine[x][y] == '0')*/
		{
			char count = count_Mine(mine, x, y);
			if (count == 0)
			{
				show[x][y] = ' ';
				if (show[x - 1][y - 1] == '*')
				{
					clear_show(show, mine, x - 1, y - 1);
				}
				if (show[x - 1][y] == '*')
				{
					clear_show(show,mine, x - 1, y);
				}
				if (show[x - 1][y + 1] == '*')
				{
					clear_show(show,mine,  x - 1, y + 1);
				}
				if (show[x][y - 1] == '*')
				{
					clear_show(show,mine, x, y - 1);
				}
				if (show[x][y + 1] == '*')
				{
					clear_show(show,mine, x, y + 1);
				}
				if (show[x + 1][y - 1] == '*')
				{
					clear_show(show,mine, x + 1, y - 1);
				}
				if (show[x + 1][y] == '*')
				{
					clear_show(show,mine, x + 1, y);
				}
				if (show[x + 1][y + 1] == '*')
				{
					clear_show(show,mine, x + 1, y + 1);
				}
			}
			else
			{
				show[x][y] = count+'0';
			}
		}
	}
}

int is_win(char board[ROWS][COLS])
{
	int count = 0;
	int i = 0, j = 0;
	for (i = 1; i <= ROW; i++)
	{
		for (j = 1; j <= COL; j++)
		{
			if ('*' == board[i][j])
			{
				count++;
			}
		}
	}
	return count;
}

void find_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int win = is_win(show);
	int x, y;
	while (win>NUM) {
		printf("ÇëÊäÈë×ø±ê->");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				printf("Äã±»Õ¨ËÀÁË!!!\n");
				show[x][y] ='!';
				print_board(show , row, col);
				break;
			}
			else {

				int count = count_Mine(mine, x, y);
				clear_show(show, mine, x, y);
				print_board(show, row, col);
			}
		}
		else {
			printf("ÊäÈë´íÎó£¬ÇëÖØÐÂÊäÈë\n");
		}
		win = is_win(show);
	}
	if (win == NUM) {
		printf("¹§Ï²ÄãÓ®ÁË£¡£¡£¡\n");
	}
}