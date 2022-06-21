#define _CRT_SECURE_NO_WARNINGS

#include "game.h"



void game() {
	char win;
	char board[ROW][COL] = { '0' };
	clear(board,ROW,COL);//��ʼ��board
	print_board(board, ROW, COL);//��ӡ����
	while (1) {
		person_print(board, ROW, COL);//������
		print_board(board, ROW, COL);
		win=is_win(board, ROW, COL);
		if (win != 'C') {
			break;
		}
		printf("��������:\n");
		computer_print(board, ROW, COL);//��������
		print_board(board, ROW, COL);
		win = is_win(board, ROW, COL);
		if (win != 'C') {
			break;
		}
	}
	if (win == 'Q') {
		printf("ƽ��\n");
	}else if (win == '*') {
		printf("��ϲ�㣬Ӯ�ˣ�����\n");
	}else if(win=='#') {
		printf("������\n");
	}
}


void start() {
	printf("0.�˳�  1.��ʼ\n");
	printf("������->");
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
			printf("�˳��ɹ�!");
			break;
		default:
			printf("���������롪>");
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