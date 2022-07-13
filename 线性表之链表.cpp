/*
链表的概念:
链表是一种物理存储结构上非连续、非顺序的存储结构。
数据元素的逻辑顺序是通过链表中的指针链接依次实现的。
*/


/*
单链表:
第一个结点的指针域内存入第二个结点的首地址，第二个结点存放第三个结点的首地址。
依次串联，最后一个结点的指针域赋为NULL。 
*/


//单链表的C语言实现

#include<stdio.h>
#include<stdlib.h>
typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SLNode;

SLNode* ButNode()
{
	
}

void SListPushFront(SLNode* pheader, SLDataType d)//头插 
{
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
	newNode->data= d;
	newNode->next = NULL;
	
	SLNode* cur = pheader
	
	
}
void SListPushBack(SLNode** ppheader, SLDataType d)//尾插 
{
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
	newNode->data= d;
	newNode->next = NULL;
	
	if(*ppheader == NULL)
	{
		*ppheader = newNode;
	}
	else
	{
		SLNode* tail = *ppheader;
		while(tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
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
	SListPrint(pheader); 
	return 0;
}

