/*
链表的概念:
链表是一种物理存储结构上非连续、非顺序的存储结构。
数据元素的逻辑顺序是通过链表中的指针链接依次实现的。
*/
/*
实际中的链表结构非常多样，共8种:
1.单向 双向 
2.带头 不带头(头结点:第一个结点不存储有效数据) 
3.循环 非循环 

常用的两种的链表结构:
1.无头单向非循环链表:
结构简单，一般不会单独用来存储数据。实践应用中一般作为其他数据结构的子结构，如哈希桶、图的邻接表等。
2.带头双向循环链表:
结构最复杂，一般用于单独存储数据。实际中使用的链表都为该种链表。 
*/ 









//无头单向非循环链表的C语言实现
/*
#include<stdio.h>
#include<stdlib.h>
typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SLNode;

SLNode* BuyListNode(SLDataType d)//创建一个结点 
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

void SListPushFront(SLNode** ppheader, SLDataType d)//头插 
{
	assert(ppheader);
	SLNode* newNode = BuyListNode(d);
	newNode->next = *ppheader;
	*ppheader = newNode;
}

void SListPushBack(SLNode** ppheader, SLDataType d)//尾插 
{
	assert(ppheader);
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

void SlistPopFront(SLNode** ppheader)//头删 
{
	if(*ppheader == NULL)
		return;
	SLNode* temp = *ppheader;
	*ppheader = (*ppheader)->next;
	free(temp);
	temp = NULL;
}

void SListPopBack(SLNode** ppheader)//尾删 
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

void SListInsert(SLNode** ppheader,SLNode* pos,SLDataType d)//在pos的前面插入 
{
	assert(ppheader && pos);
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

void SListErase(SLNode** ppheader,SLNode* pos)//删除pos位置的值 
{
	assert(ppheader && pos);
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
	
	//在3前面插入30
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





//带头单向不循环链表C++实现(企业版)
/*
与用户协议:需要自定义数据类型，预留四个字节交予链表链接使用(不需开辟结点) 
*/
/*
#include<iostream>
using namespace std;
class LinkNode
{
	friend class LinkList;
private:
	LinkNode* next;
};
class LinkList
{
public:
	LinkList();
	void insert(int pos, void* data);
	void push_back(void* data);
	void for_each(void(*MyPrint)(void*));
	void remove(int pos);
	~LinkList();
private:
	LinkNode pHeader;
	int m_size;
};
LinkList::LinkList()
{
	this->pHeader.next = nullptr;
	this->m_size = 0;
}

void LinkList::insert(int pos, void* data)
{
	if (data == nullptr)return;
	if (pos<0 || pos>this->m_size)
	{
		pos = this->m_size;//无效位置变为尾插
	}
	LinkNode* NewNode = (LinkNode*)data;
	LinkNode* pCurrent = &(this->pHeader);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;//找到前驱结点
	}
	//变更指针指向
	NewNode->next = pCurrent->next;
	pCurrent->next = NewNode;
	++this->m_size;
}

void LinkList::push_back(void* data)
{
	this->insert(this->m_size, data);
}

void LinkList::for_each(void(*MyPrint)(void*))
{
	LinkNode* node = this->pHeader.next;
	for (int i = 0; i < this->m_size; ++i)
	{
		MyPrint(node);
		node = node->next;
	}
	cout<<endl;
}

void LinkList::remove(int pos)
{
	if (pos<0 || pos>this->m_size - 1)return;
	LinkNode* pCurrent = &(this->pHeader);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;//找到前驱结点
	}
	LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	--this->m_size;
}

LinkList::~LinkList()
{
	this->pHeader.next = nullptr;
	this->m_size = 0;
}


struct data
{
	void* Link;
	int m_data;
};
void MyPrint(void* d)
{
	cout<<(((data*)d)->m_data)<<" ";
}
int main()
{
	LinkList lt;
	
	data p0;
	p0.Link = nullptr;
	p0.m_data = 0;
	data p1;
	p1.Link = nullptr;
	p1.m_data = 1;
	data p2;
	p2.Link = nullptr;
	p2.m_data = 2;
	data p3;
	p3.Link = nullptr;
	p3.m_data = 3;
	data p4;
	p4.Link = nullptr;
	p4.m_data = 4;
	data p5;
	p5.Link = nullptr;
	p5.m_data = 5;
	
	lt.push_back(&p1);
	lt.push_back(&p2);
	lt.push_back(&p3);
	lt.push_back(&p4);
	lt.push_back(&p5);
	lt.insert(0,&p0);
	lt.for_each(MyPrint);
	
	lt.remove(3);
	lt.for_each(MyPrint);
	return 0;
}
*/


/*
单链表的缺陷:
1. 与数组相比，在链表中存储元素需要更多的内存。 因为在链表中，每个节点都包含一个指针，并且它本身需要额外的内存。
2.在链表中很难遍历元素或节点。 我们不能像按索引在数组中那样随机访问任何元素。 
例如，如果我们要访问位置n处的节点，则必须遍历它之前的所有节点。
3.单链表无法反向遍历 
*/














//带头双向循环链表C语言实现
/*
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LDataType;
typedef struct ListNode
{
	struct ListNode* prev;//前驱 
	struct ListNode* next;//后继 
	LDataType data; 
}ListNode;
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
void ListInsert(ListNode* pos,LDataType d)//在pos位置之前插入 
{
	assert(pos);
	ListNode* newNode = BuyListNode(d);
	newNode->next = pos;
	newNode->prev = pos->prev;
	(pos->prev)->next = newNode;
	pos->prev = newNode;
}
void ListErase(ListNode* pos)//删除pos位置的值 
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
带头双向循环链表:
最优的链表结构，在任意位置的插入删除(不包括插入删除结点的查找)都为O(1) 
*/



