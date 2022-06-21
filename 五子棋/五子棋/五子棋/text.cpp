#define _CRT_SECURE_NO_WARNINGS

#include "game.h"



void game() {
	char win;
	char board[ROW][COL] = { '0' };
	clear(board,ROW,COL);//初始化board
	print_board(board, ROW, COL);//打印棋盘
	while (1) {
		person_print(board, ROW, COL);//人输入
		print_board(board, ROW, COL);
		win=is_win(board, ROW, COL);
		if (win != 'C') {
			break;
		}
		printf("电脑输入:\n");
		computer_print(board, ROW, COL);//电脑输入
		print_board(board, ROW, COL);
		win = is_win(board, ROW, COL);
		if (win != 'C') {
			break;
		}
	}
	if (win == 'Q') {
		printf("平局\n");
	}else if (win == '*') {
		printf("恭喜你，赢了！！！\n");
	}else if(win=='#') {
		printf("你输了\n");
	}
}


void start() {
	printf("0.退出  1.开始\n");
	printf("请输入->");
}

void text() {
	int n;
	do {
		start();
		scanf("%d", &n);
		switch (n) {
		case 1:
			game();
			break;
		case 0:
			printf("退出成功!");
			break;
		default:
			printf("请重新输入—>");
			break;

		}
	} while (n);
}

int main()
{
	srand((unsigned int)time(NULL));
	text();
	return 0;
}