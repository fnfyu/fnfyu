#define _CRT_SECURE_NO_WARNINGS 1//���Է�ֹ����vsʱ ��ʾ����ȫҪ�� _s 

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
	ADD,//1  ö������˴���Ŀɶ��� 
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
	int size;//��ŵ�ǰ���еĸ��� 
	int capacity;//��ǰ������� 
};
void Init(struct Contact *p);
void AddInfo(struct Contact *p);
void Showcontact(const struct Contact*p);
void DelInfo(struct Contact*p);//ɾ��ָ����ϵ�� 
void SearchContact(const struct Contact*p);//����ָ���˵���Ϣ
void EditInfo(struct Contact * p);//�޸�
void SortContact(struct Contact * p);
void DestroyContact(struct Contact*p); 
void SaveInfo(struct Contact *p);
void LoadContact(struct Contact*p);
