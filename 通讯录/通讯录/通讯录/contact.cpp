#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

//��������
void Check(struct CON*ps);

//�����ϴα������Ϣ
void LoadContact(struct CON* ps) {
	struct PERSONINFO tmp = { 0 };
	FILE* pfRead = fopen("Contact.dat", "rb");
	if (pfRead == NULL) {
		printf("pfRead::%s\n", strerror(errno));
	}
	while (fread(&tmp, sizeof(struct PERSONINFO), 1, pfRead)) {
		Check(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

//��ʼ����Ϣ
void InitContact(struct CON* ps) {
	/*memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;*/
	ps->data = (struct PERSONINFO*)malloc(cap * sizeof(struct PERSONINFO));
	ps->size = 0;
	ps->capitality = cap;

	//�����ϴα������Ϣ
	LoadContact(ps);
}

//����ͨѶ¼
void Check(struct CON*ps) {
	if (ps->capitality == ps->size) {
		struct PERSONINFO*ptr = (struct PERSONINFO*)realloc(ps->data, ps->capitality*sizeof(struct PERSONINFO) + 2 * sizeof(struct PERSONINFO));
		if (ptr != NULL) {
			ps->data = ptr;
			ps->capitality += 2;
			printf("���ݳɹ�\n");
		}else{
			printf("����ʧ��\n");
		}
	}
}

//����һ����Ϣ
void AddContact(struct CON* ps) {
	Check(ps);//����Ƿ����㹻�Ŀռ�
	printf("���������֣�");
	scanf("%s", ps->data[ps->size].name);
	printf("���������䣺");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰��");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ��");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;
	printf("����ɹ�\n");
	/*if (ps->size == MAX) {
		printf("ͨѶ¼��������");
	}
	else {
		printf("���������֣�");
		scanf("%s", ps->data[ps->size].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰��");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("����ɹ�\n");
	}*/
}

//��ӡͨѶ¼
void ShowContact(const struct CON*ps) {
	if (ps->size == 0){
		printf("ͨѶ¼Ϊ�ա�\n");
	}
	else {
		printf("%-10s\t %-5s\t %-4s\t %-15s\t %-10s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		int i = 0;
		for (i = 0; i < ps->size; i++) {
			printf("%-10s\t %-5s\t %-4d\t %-15s\t %-10s\n",
				ps->data[i].name,
				ps->data[i].sex,
				ps->data[i].age,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//�������ֵ��±�
static int SearchName(const struct CON*ps,const char name[MAX_NAME]) {
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		if (0 == strcmp(ps->data[i].name, name)) {
			return i;
		}
	}
	return -1;
}

//ɾ����Ϣ
void DelContact(struct CON*ps) {
	char name[MAX_NAME] = { 0 };
	printf("����������:");
	scanf("%s", name);
	int i = SearchName(ps, name);
	if (i == -1) {
		printf("���޴���\n");
	}
	else {
		int j = 0;
		for (j = i; j < ps->size - 1; j++) {
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

//������Ϣ
void SearchContact(const struct CON*ps) {
	char name[MAX_NAME] = { 0 };
	printf("������������");
	scanf("%s", name);
	int i = SearchName(ps, name);
	if (i == -1) {
		printf("���޴���\n");
	}
	else {
		printf("%-10s\t %-5s\t %-4s\t %-15s\t %-10s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%-10s\t %-5s\t %-4d\t %-15s\t %-10s\n",
			ps->data[i].name,
			ps->data[i].sex,
			ps->data[i].age,
			ps->data[i].tele,
			ps->data[i].addr);
		
	}
}

//�޸���Ϣ
void ModifyContact(const struct CON*ps) {
	char name[MAX_NAME] = { 0 };
	printf("���������֣�");
	scanf("%s", name);
	int i = SearchName(ps, name);
	if (i == -1) {
		printf("���޴���\n");
	}
	else {
		printf("���������֣�");
		scanf("%s", ps->data[i].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[i].age));
		printf("�������Ա�");
		scanf("%s", ps->data[i].sex);
		printf("������绰��");
		scanf("%s", ps->data[i].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[i].addr);

		printf("�޸ĳɹ�\n");
	}
}

//�����Ӻ���(�ַ���)
static int my_cmpchar(const void* e1,const void* e2) {
	return strcmp(((struct PERSONINFO*)e1)->name, ((struct PERSONINFO*)e2)->name);
}

//�����Ӻ���(����)
static int my_cmpint(const void* e1, const void* e2) {
	return ((struct PERSONINFO*)e1)->age - ((struct PERSONINFO*)e2)->age;
}

//������Ϣ
void SortContact(struct CON*ps) {
again:
	printf("1.name   2.age\n");
	printf("3.sex    4.tele\n");
	printf("5.addr\n");
	printf("��ѡ��");
	int i = 0;
	scanf("%d", &i);
	if (i < 1 || i>5) {
		printf("�������");
		goto again;
	}
	else if (i == 2) {
		qsort(ps->data, ps->size, sizeof(ps->data[0]), my_cmpint);
	}
	else {
		qsort(ps->data, ps->size, sizeof(ps->data[0]), my_cmpchar);
	}
		printf("����ɹ�\n");
}

//�ͷ��ڴ�
void DestroyContact(struct CON*ps) {
	free(ps->data);
	ps->data = NULL;
	printf("���ٳɹ�\n");

}

//������Ϣ
void SaveContact(struct CON * ps) {
	FILE* pfWrite = fopen("Contact.dat", "wb");
	if (pfWrite == NULL) {
		printf("pfWrite::%s\n", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		fwrite(&(ps->data[i]), sizeof(struct PERSONINFO), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
	printf("����ɹ�\n");
}