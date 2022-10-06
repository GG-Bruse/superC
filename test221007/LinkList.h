#pragma once

typedef struct data//ͨѶ�ߵĽ������
{
	char num[5];//���
	char name[9];//����
	char sex[3];//�Ա�
	char phone[13];//�绰
	char addr[31];//��ַ
}DataType;

typedef DataType SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SLNode;

typedef  SLNode* LinkList;
SLNode* pos;
LinkList  head;


SLNode* BuyListNode(SLDataType d);

void SListPushFront(SLNode** ppheader, SLDataType d);

void SListPushBack(SLNode** ppheader, SLDataType d);

void SlistPopFront(SLNode** ppheader);

void SListPopBack(SLNode** ppheader);

void SListInsert(SLNode** ppheader, SLNode* pos, SLDataType d);

void SListErase(SLNode** ppheader, SLNode* pos);

SLNode* SListFind(SLNode* pheader, char* d);

void SListPrint(SLNode* pheader);