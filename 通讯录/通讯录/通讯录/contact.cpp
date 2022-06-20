#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

//声明函数
void Check(struct CON*ps);

//加载上次保存的信息
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

//初始化信息
void InitContact(struct CON* ps) {
	/*memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;*/
	ps->data = (struct PERSONINFO*)malloc(cap * sizeof(struct PERSONINFO));
	ps->size = 0;
	ps->capitality = cap;

	//加载上次保存的信息
	LoadContact(ps);
}

//扩容通讯录
void Check(struct CON*ps) {
	if (ps->capitality == ps->size) {
		struct PERSONINFO*ptr = (struct PERSONINFO*)realloc(ps->data, ps->capitality*sizeof(struct PERSONINFO) + 2 * sizeof(struct PERSONINFO));
		if (ptr != NULL) {
			ps->data = ptr;
			ps->capitality += 2;
			printf("增容成功\n");
		}else{
			printf("增容失败\n");
		}
	}
}

//增加一个信息
void AddContact(struct CON* ps) {
	Check(ps);//检测是否有足够的空间
	printf("请输入名字：");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄：");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别：");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话：");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址：");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;
	printf("输入成功\n");
	/*if (ps->size == MAX) {
		printf("通讯录人数已满");
	}
	else {
		printf("请输入名字：");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别：");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("输入成功\n");
	}*/
}

//打印通讯录
void ShowContact(const struct CON*ps) {
	if (ps->size == 0){
		printf("通讯录为空。\n");
	}
	else {
		printf("%-10s\t %-5s\t %-4s\t %-15s\t %-10s\n", "姓名", "性别", "年龄", "电话", "地址");
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

//查找名字的下标
static int SearchName(const struct CON*ps,const char name[MAX_NAME]) {
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		if (0 == strcmp(ps->data[i].name, name)) {
			return i;
		}
	}
	return -1;
}

//删除信息
void DelContact(struct CON*ps) {
	char name[MAX_NAME] = { 0 };
	printf("请输入名字:");
	scanf("%s", name);
	int i = SearchName(ps, name);
	if (i == -1) {
		printf("查无此人\n");
	}
	else {
		int j = 0;
		for (j = i; j < ps->size - 1; j++) {
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

//查找信息
void SearchContact(const struct CON*ps) {
	char name[MAX_NAME] = { 0 };
	printf("请输入姓名：");
	scanf("%s", name);
	int i = SearchName(ps, name);
	if (i == -1) {
		printf("查无此人\n");
	}
	else {
		printf("%-10s\t %-5s\t %-4s\t %-15s\t %-10s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%-10s\t %-5s\t %-4d\t %-15s\t %-10s\n",
			ps->data[i].name,
			ps->data[i].sex,
			ps->data[i].age,
			ps->data[i].tele,
			ps->data[i].addr);
		
	}
}

//修改信息
void ModifyContact(const struct CON*ps) {
	char name[MAX_NAME] = { 0 };
	printf("请输入名字：");
	scanf("%s", name);
	int i = SearchName(ps, name);
	if (i == -1) {
		printf("查无此人\n");
	}
	else {
		printf("请输入名字：");
		scanf("%s", ps->data[i].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[i].age));
		printf("请输入性别：");
		scanf("%s", ps->data[i].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[i].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[i].addr);

		printf("修改成功\n");
	}
}

//排序子函数(字符串)
static int my_cmpchar(const void* e1,const void* e2) {
	return strcmp(((struct PERSONINFO*)e1)->name, ((struct PERSONINFO*)e2)->name);
}

//排序子函数(整数)
static int my_cmpint(const void* e1, const void* e2) {
	return ((struct PERSONINFO*)e1)->age - ((struct PERSONINFO*)e2)->age;
}

//排序信息
void SortContact(struct CON*ps) {
again:
	printf("1.name   2.age\n");
	printf("3.sex    4.tele\n");
	printf("5.addr\n");
	printf("请选择：");
	int i = 0;
	scanf("%d", &i);
	if (i < 1 || i>5) {
		printf("输入错误");
		goto again;
	}
	else if (i == 2) {
		qsort(ps->data, ps->size, sizeof(ps->data[0]), my_cmpint);
	}
	else {
		qsort(ps->data, ps->size, sizeof(ps->data[0]), my_cmpchar);
	}
		printf("排序成功\n");
}

//释放内存
void DestroyContact(struct CON*ps) {
	free(ps->data);
	ps->data = NULL;
	printf("销毁成功\n");

}

//保存信息
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
	printf("保存成功\n");
}