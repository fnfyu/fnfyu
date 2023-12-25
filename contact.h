#define _CRT_SECURE_NO_WARNINGS 1//可以防止在用vs时 提示不安全要用 _s 

//#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_TELE 20
#define MAX_ADDR 20
#define DEFAULTSZ 3
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
enum Option
{
	EXIT,//0
	ADD,//1  枚举提高了代码的可读性 
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE	
};
enum OptionSort
{
	NAME=1,
	AGE=2
};	
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR]; 
};
struct Contact
{
	struct PeoInfo *Data;
	int size;//存放当前已有的个数 
	int capacity;//当前最大容量 
};
void Init(struct Contact *p);
void AddInfo(struct Contact *p);
void Showcontact(const struct Contact*p);
void DelInfo(struct Contact*p);//删除指定联系人 
void SearchContact(const struct Contact*p);//查找指定人的信息
void EditInfo(struct Contact * p);//修改
void SortContact(struct Contact * p);
void DestroyContact(struct Contact*p); 
void SaveInfo(struct Contact *p);
void LoadContact(struct Contact*p);
