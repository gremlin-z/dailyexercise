#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"
void menu() {
	printf("1.add     2.del\n");
	printf("3.search  4.modify\n");
	printf("5.show    6.sort\n");
	printf("7.save    0.exist\n");
}

int main()
{
	int input = 0;
	struct CON con;//通讯录，包含成员和人数
	InitContact(&con);//初始化通讯录
	do {
		menu();
		printf("请选择:->");
		scanf("%d", &input);
		switch (input) {
		case ADD:
			AddContact(&con);//添加人的信息
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIST:
			SaveContact(&con);
			DestroyContact(&con);
			printf("成功退出!");
			break;
		case SAVE:
			SaveContact(&con);
			break;
		default:
			printf("输入错误!");
		}
	} while (input);
	return 0;
}