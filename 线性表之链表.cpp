/*
����ĸ���:
������һ������洢�ṹ�Ϸ���������˳��Ĵ洢�ṹ��
����Ԫ�ص��߼�˳����ͨ�������е�ָ����������ʵ�ֵġ�
*/
/*
ʵ���е�����ṹ�ǳ���������8��:
1.���� ˫�� 
2.��ͷ ����ͷ(ͷ���:��һ����㲻�洢��Ч����) 
3.ѭ�� ��ѭ�� 

���õ����ֵ�����ṹ:
1.��ͷ�����ѭ������:
�ṹ�򵥣�һ�㲻�ᵥ�������洢���ݡ�ʵ��Ӧ����һ����Ϊ�������ݽṹ���ӽṹ�����ϣͰ��ͼ���ڽӱ�ȡ�
2.��ͷ˫��ѭ������:
�ṹ��ӣ�һ�����ڵ����洢���ݡ�ʵ����ʹ�õ�����Ϊ�������� 
*/ 









//��ͷ�����ѭ�������C����ʵ��
/*
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
*/





/*
�������ȱ��:
1. ��������ȣ��������д洢Ԫ����Ҫ������ڴ档 ��Ϊ�������У�ÿ���ڵ㶼����һ��ָ�룬������������Ҫ������ڴ档
2.�������к��ѱ���Ԫ�ػ�ڵ㡣 ���ǲ�����������������������������κ�Ԫ�ء� 
���磬�������Ҫ����λ��n���Ľڵ㣬����������֮ǰ�����нڵ㡣
3.�������޷�������� 
*/



















//��ͷ˫��ѭ������C����ʵ��
/*
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LDataType;
typedef struct ListNode
{
	struct ListNode* prev;//ǰ�� 
	struct ListNode* next;//��� 
	LDataType data; 
}ListNode;
ListNode* BuyListNode(LDataType d)//����һ����� 
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
		return NULL;
	newNode->data = d;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
void for_each(ListNode* pheader)
{
	assert(pheader);
	for(ListNode* cur = pheader->next;cur != pheader;cur = cur->next)
	{
		printf("%d ",cur->data);
	}
	printf("\n");
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
	for(ListNode* cur = pheader->next;cur != pheader;)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(pheader);
	pheader = NULL;
}





ListNode* ListFind(ListNode* pheader,LDataType d)
{
	assert(pheader);
	for(ListNode* cur = pheader->next;cur != pheader;cur = cur->next)
	{
		if(cur->data == d)
		{
			return cur;
		}
	}
	return NULL;
} 
void ListInsert(ListNode* pos,LDataType d)//��posλ��֮ǰ���� 
{
	assert(pos);
	ListNode* newNode = BuyListNode(d);
	newNode->next = pos;
	newNode->prev = pos->prev;
	(pos->prev)->next = newNode;
	pos->prev = newNode;
}
void ListErase(ListNode* pos)//ɾ��posλ�õ�ֵ 
{
	assert(pos);
	(pos->prev)->next = pos->next;
	(pos->next)->prev = pos->prev;
	free(pos);
	pos = NULL;
}





void ListPushFront(ListNode* pheader,LDataType d)
{
	//assert(pheader);
	//ListNode* newNode = BuyListNode(d);
	//newNode->next = pheader->next;
	//(pheader->next)->prev = newNode;
	//pheader->next = newNode;
	//newNode->prev = pheader;

	assert(pheader);
	ListInsert(pheader->next,d);
}
void ListPushBack(ListNode* pheader,LDataType d)
{
	//assert(pheader);
	//ListNode* newNode = BuyListNode(d);
	//(pheader->prev)->next = newNode;
	//newNode->prev = pheader->prev;
	//newNode->next = pheader;
	//pheader->prev = newNode;
	
	ListInsert(pheader,d);
}
void ListPopFront(ListNode* pheader)
{
	//assert(pheader);
	//assert(pheader->next != pheader);
	//ListNode* first = pheader->next;
	//(first->next)->prev = pheader; 
	//pheader->next = first->next;
	//free(first);
	//first = NULL;
	
	assert(pheader);
	ListErase(pheader->next);
}
void ListPopBack(ListNode* pheader)
{
	//assert(pheader);
	//assert(pheader->next != pheader);
	//ListNode* tail = pheader->prev;
	//(tail->prev)->next =pheader;
	//pheader->prev = tail->prev;
	//free(tail);
	//tail = NULL;
	
	assert(pheader);
	ListErase(pheader->prev); 
}





int main()
{
	ListNode* pheader = ListInit();

	ListPushBack(pheader,3);
	ListPushBack(pheader,2);
	ListPushBack(pheader,1);
	ListPushBack(pheader,0);
	ListPushFront(pheader,4);
	ListPushFront(pheader,5);
	for_each(pheader);
	
	ListPopFront(pheader);
	ListPopBack(pheader);
	for_each(pheader);
	
	ListNode* pos = ListFind(pheader,2);
	if(pos)
	{
		ListInsert(pos,200); 
	}
	for_each(pheader);
	
	pos = ListFind(pheader,200);
	if(pos)
	{
		ListErase(pos);
	}
	for_each(pheader);
	
	ListDestory(pheader);
	return 0;
} 
*/

/*
��ͷ˫��ѭ������:
���ŵ�����ṹ��������λ�õĲ���ɾ��(����������ɾ�����Ĳ���)��ΪO(1) 
*/



