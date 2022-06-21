#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


void clear(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}

	}
}


void print_board(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			printf("%c", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			printf("- - -\n");
		}
	}
}

void person_print(char board[ROW][COL], int row, int col) {
	int x, y;
again:
	printf("ÇëÊäÈë×ø±ê¡ª>");
	scanf("%d%d", &x, &y);
	if ((x>=0 && x < row ) && (y>=0 && y < col ) && board[x][y]==' ') {
		board[x][y] = '*';
	}
	else {
		goto again;
	}
}

void computer_print(char board[ROW][COL],int row,int col){
	int x, y;
	while (1) {
		x = rand()%row, y = rand()%col;
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}

int is_full(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				goto again;
			}
		}
	}
	return 1;
again:
	return 0;
}


char is_win(char board[ROW][COL], int row, int col) {
	
	int i = 0;
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][2]==board[i][0] && board[i][0] != ' ') {
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[2][i]==board[1][i] && board[0][i] != ' ') {
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[2][2]==board[1][1] && board[1][1]!=' ') return board[1][1];
	if (board[0][2] == board[1][1] && board[0][2]==board[2][0] && board[1][1] != ' ') return board[1][1];
	
	if (is_full(board,ROW,COL)) return 'Q';
	return 'C';
}