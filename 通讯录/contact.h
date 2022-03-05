#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define DEFAULT_SZ 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//ͨѶ¼����
struct Contact
{
	struct PeoInfo* data;//�����Ϣ
	int size;//��¼��ǰ�Ѿ��е����ݸ���
	int capacity;//��ǰͨѶ¼���������
};




void InitContact(struct Contact* ps);

void AddContact(struct Contact* ps);

void DelContact(struct Contact* ps);

void SearchContact(const struct Contact* ps);

void ModifyContact(struct Contact* ps);

void ShowContact(const struct Contact* ps);

void DestroyContact(struct Contact* ps);

void SaveContact(struct Contact* ps);

void LoadContact(struct Contact* ps);
