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
void SListPushFront(SLNode* pheader, SLDataType data)//ͷ�� 
{

}
void SListPushBack(SLNode* pheader, SLDataType data)//β�� 
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

