/*
����ĸ���:
������һ������洢�ṹ�Ϸ���������˳��Ĵ洢�ṹ��
����Ԫ�ص��߼�˳����ͨ�������е�ָ����������ʵ�ֵġ�
*/



//�������C����ʵ��
#include<stdio.h>
#include<stdlib.h>
typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SLNode;

SLNode* BuyListNode(SLDataType d)//����һ����� 
{
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
	if (newNode == NULL)
		return NULL;
	newNode->data = d;
	newNode->next = NULL;
	return newNode;
}

SLNode* SListFind(SLNode* pheader,SLDataType d)
{
	SLNode* cur = pheader;
	for(;cur != NULL;cur = cur->next)
	{
		if(cur->data == d)
		{
			return cur;
		}
	}
	return NULL;
} 

void SListPushFront(SLNode** ppheader, SLDataType d)//ͷ�� 
{
	SLNode* newNode = BuyListNode(d);
	newNode->next = *ppheader;
	*ppheader = newNode;
}

void SListPushBack(SLNode** ppheader, SLDataType d)//β�� 
{
	SLNode* newNode = BuyListNode(d);

	if (*ppheader == NULL)
	{
		*ppheader = newNode;
	}
	else
	{
		SLNode* tail = *ppheader;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

void SlistPopFront(SLNode** ppheader)//ͷɾ 
{
	if(*ppheader == NULL)
		return;
	SLNode* temp = *ppheader;
	*ppheader = (*ppheader)->next;
	free(temp);
	temp = NULL;
}

void SListPopBack(SLNode** ppheader)//βɾ 
{
	if(*ppheader == NULL)
	{
		return;
	}
	else if((*ppheader)->next == NULL)
	{
		free(*ppheader);
		*ppheader = NULL;
		return;
	} 
		
	SLNode* prev = NULL;
	SLNode* tail = *ppheader;
	for(;tail->next != NULL;tail = tail->next)
	{
		prev = tail;
	}
	free(tail);
	prev->next = NULL;
} 

void SListInsert(SLNode** ppheader,SLNode* pos,SLDataType d)//��pos��ǰ����� 
{
	if(pos == *ppheader)
	{
		SListPushFront(ppheader,d);
	}
	else
	{
		SLNode* newNode = BuyListNode(d);
		SLNode* prev = *ppheader;
		for(;prev->next != pos;prev = prev->next);
		prev->next = newNode;
		newNode->next = pos;
	}
} 

void SListErase(SLNode** ppheader,SLNode* pos)//ɾ��posλ�õ�ֵ 
{
	if(pos == *ppheader)
	{
		SlistPopFront(ppheader);
	}
	else
	{
		SLNode* prev = *ppheader;
		for(;prev->next != pos;prev = prev->next);
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
} 

void SListPrint(SLNode* pheader)
{
	for (SLNode* cur = pheader; cur != NULL; cur = cur->next)
	{
		printf("%d ", cur->data);
	}
	printf("\n");
}

int main()
{
	SLNode* pheader = NULL;
	SListPushBack(&pheader, 1);
	SListPushBack(&pheader, 2);
	SListPushBack(&pheader, 3);
	SListPushBack(&pheader, 4);
	SListPushFront(&pheader,0);

	SListPrint(pheader);
	
	//��3ǰ�����30
	SLNode* pos = SListFind(pheader,3);
	if(pos)
		SListInsert(&pheader,pos,30); 
	
	
	pos = SListFind(pheader,0);
	if(pos)
		SListErase(&pheader,pos);
	
	SListPrint(pheader);
	
	return 0;
}

