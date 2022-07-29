#include "List.h"
void for_each(ListNode* pheader)
{
	assert(pheader);
	for (ListNode* cur = pheader->next; cur != pheader; cur = cur->next)
	{
		printf("%d ", cur->data);
	}
	printf("\n");
}
int ListSize(ListNode* pheader)
{
	assert(pheader);
	int count = 0;
	for (ListNode* cur = pheader->next; cur != pheader; cur = cur->next)
	{
		++count;
	}
	return count;
}
ListNode* BuyListNode(LDataType d)//创建一个结点 
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
		return NULL;
	newNode->data = d;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
ListNode* ListInit()
{
	ListNode* pheader = BuyListNode(0);
	pheader->prev = pheader;
	pheader->next = pheader;
	return pheader;
}
void ListDestory(ListNode* pheader)
{
	assert(pheader);
	for (ListNode* cur = pheader->next; cur != pheader;)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(pheader);
	pheader = NULL;
}
//ListNode* ListFind(ListNode* pheader, LDataType d)
//{
//	assert(pheader);
//	for (ListNode* cur = pheader->next; cur != pheader; cur = cur->next)
//	{
//		if (cur->data == d)
//		{
//			return cur;
//		}
//	}
//	return NULL;
//}
void ListInsert(ListNode* pos, LDataType d)
{
	assert(pos);
	ListNode* newNode = BuyListNode(d);
	newNode->next = pos;
	newNode->prev = pos->prev;
	(pos->prev)->next = newNode;
	pos->prev = newNode;
}
void ListErase(ListNode* pos)
{
	assert(pos);
	(pos->prev)->next = pos->next;
	(pos->next)->prev = pos->prev;
	free(pos);
	pos = NULL;
}
void ListPushFront(ListNode* pheader, LDataType d)
{
	assert(pheader);
	ListInsert(pheader->next, d);
}
void ListPushBack(ListNode* pheader, LDataType d)
{
	assert(pheader);
	ListInsert(pheader, d);
}
void ListPopFront(ListNode* pheader)
{
	assert(pheader);
	ListErase(pheader->next);
}
void ListPopBack(ListNode* pheader)
{
	assert(pheader);
	ListErase(pheader->prev);
}

