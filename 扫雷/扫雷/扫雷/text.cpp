#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void game() {
	char Mine[ROWS][COLS] = { 0 };//������
	char Show[ROWS][COLS] = { 0 };//�Ų���
	clear_board(Mine, ROWS, COLS, '0');
	clear_board(Show, ROWS, COLS, '*');//��ʼ��
	print_board(Show, ROW, COL);
	//��װ��
	Set_Mine(Mine, ROW, COL,NUM);
	//ɨ��
	find_Mine(Mine, Show, ROW, COL);

}

void start() {
	printf("********************\n");
	printf("*** 0.�˳� 1.���� **\n");
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
			printf("�˳��ɹ�����!\n");
			break;
		default:
			printf("������󣡣���\n");
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