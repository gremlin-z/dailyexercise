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
	struct CON con;//ͨѶ¼��������Ա������
	InitContact(&con);//��ʼ��ͨѶ¼
	do {
		menu();
		printf("��ѡ��:->");
		scanf("%d", &input);
		switch (input) {
		case ADD:
			AddContact(&con);//����˵���Ϣ
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
			printf("�ɹ��˳�!");
			break;
		case SAVE:
			SaveContact(&con);
			break;
		default:
			printf("�������!");
		}
	} while (input);
	return 0;
}