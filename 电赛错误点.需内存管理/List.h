#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LDataType;
typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LDataType data;
}ListNode;

void for_each(ListNode* pheader);
ListNode* BuyListNode(LDataType d);
ListNode* ListInit();
void ListDestory(ListNode* pheader);
//ListNode* ListFind(ListNode* pheader, LDataType d);
void ListInsert(ListNode* pos, LDataType d);
void ListErase(ListNode* pos);
void ListPushFront(ListNode* pheader, LDataType d);
void ListPushBack(ListNode* pheader, LDataType d);
void ListPopFront(ListNode* pheader);
void ListPopBack(ListNode* pheader);
int ListSize(ListNode* pheader);