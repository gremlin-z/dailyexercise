#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//#define MAX 1000
#define cap 1

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

enum OPTION {
	EXIST,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE,
};

struct PERSONINFO {
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct CON {
	struct PERSONINFO *data;
	int size;
	int capitality;
};//记录动态人的信息和现有的个数，能包含的人数



void InitContact(struct CON* ps);

void AddContact(struct CON* ps);

void ShowContact(const const struct CON*ps);

void DelContact(struct CON*ps);

void SearchContact(const struct CON*ps);

void ModifyContact(const struct CON*ps);

void SortContact(struct CON*ps);

void DestroyContact(struct CON*ps);

void SaveContact(struct CON * ps);

void LoadContact(struct CON * ps);