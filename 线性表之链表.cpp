/*
链表的概念:
链表是一种物理存储结构上非连续、非顺序的存储结构。
数据元素的逻辑顺序是通过链表中的指针链接依次实现的。
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
void SListPushFront(SLNode* pheader, SLDataType data)//头插 
{

}
void SListPushBack(SLNode* pheader, SLDataType data)//尾插 
{
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));

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
	SListPushBack(pheader, 1);
	SListPushBack(pheader, 2);
	SListPushBack(pheader, 3);
	SListPushBack(pheader, 4);
	return 0;
}

