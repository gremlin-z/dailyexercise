#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void game() {
	char Mine[ROWS][COLS] = { 0 };//安排雷
	char Show[ROWS][COLS] = { 0 };//排查雷
	clear_board(Mine, ROWS, COLS, '0');
	clear_board(Show, ROWS, COLS, '*');//初始化
	print_board(Show, ROW, COL);
	//安装雷
	Set_Mine(Mine, ROW, COL,NUM);
	//扫雷
	find_Mine(Mine, Show, ROW, COL);

}

void start() {
	printf("********************\n");
	printf("*** 0.退出 1.继续 **\n");
	printf("********************\n");
}

void text() {
	int input;
	do {
		start();
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出成功！！!\n");
			break;
		default:
			printf("输入错误！！！\n");
			break;
		}
	} while (input);
}

int main()
{
	srand((unsigned int)time(NULL));
	text();
	return 0;
}