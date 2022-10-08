#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

SLNode* BuyListNode(SLDataType d){
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
	if (newNode == NULL)
		return NULL;
	newNode->data = d;
	newNode->next = NULL;
	return newNode;
}

void SListPushFront(SLNode** ppheader, SLDataType d) {
	SLNode* newNode = BuyListNode(d);
	newNode->next = *ppheader;
	*ppheader = newNode;
}

void SListPushBack(SLNode** ppheader, SLDataType d) {
	SLNode* newNode = BuyListNode(d);
	if (*ppheader == NULL) *ppheader = newNode;
	else{
		SLNode* tail = *ppheader;
		while (tail->next != NULL) tail = tail->next;
		tail->next = newNode;
	}
}

void SlistPopFront(SLNode** ppheader) {
	if (*ppheader == NULL) return;
	SLNode* temp = *ppheader;
	*ppheader = (*ppheader)->next;
	free(temp);
	temp = NULL;
}

void SListPopBack(SLNode** ppheader){
	if (*ppheader == NULL) return;
	else if ((*ppheader)->next == NULL){
		free(*ppheader);
		*ppheader = NULL;
		return;
	}
	SLNode* prev = NULL;
	SLNode* tail = *ppheader;
	for (; tail->next != NULL; tail = tail->next) { prev = tail; }
	free(tail);
	prev->next = NULL;
}

void SListInsert(SLNode** ppheader, SLNode* pos, SLDataType d){
	if (pos == *ppheader){
		SListPushFront(ppheader, d);
	}
	else{
		SLNode* newNode = BuyListNode(d);
		SLNode* prev = *ppheader;
		for (; prev->next != pos; prev = prev->next);
		prev->next = newNode;
		newNode->next = pos;
	}
}

void SListErase(SLNode** ppheader, SLNode* pos){
	if (pos == *ppheader) SlistPopFront(ppheader);
	else{
		SLNode* prev = *ppheader;
		for (; prev->next != pos; prev = prev->next);
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

SLNode* SListFind(SLNode* pheader, char* d){
	SLNode* cur = pheader;
	for (; cur != NULL; cur = cur->next){
		if (strcmp(cur->data.num ,d) == 0){
			return cur;
		}
	}
	return NULL;
}

void SListPrint(SLNode* pheader){
	for (SLNode* cur = pheader; cur != NULL; cur = cur->next)
		printf("编号：%s  姓名：%s  性别：%s  电话：%s  地址：%s\n", cur->data.num, cur->data.name, cur->data.sex, cur->data.phone, cur->data.addr);
	printf("\n");
}