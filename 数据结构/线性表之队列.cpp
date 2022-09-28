/*
队列:
一种特殊的线性表(受限线性表)。只允许在一端进行插入数据操作，在另一端进行删除数据操作的特殊线性表。
队列具有先进先出FIFO(First in First out)原则

入队列:进行插入操作的一端被称为队尾 
出队列:进行删除操作的一端被称为队头 
*/

/*
利用数组和链表都可实现队列 
1.数组:(不适合)
数组头作队头，数组尾作队尾 
2.链表:(更优) 
(单链表)链表头作队头(头删)，链表尾作队尾(尾插) 
*/





//C语言利用无头单向不循环链表实现队列(1)
/*
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;
typedef struct Queue
{
	QNode* head;
	QNode* tail;	
}Queue;

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while(cur != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
void QueuePush(Queue* pq,QDataType d)//队尾入 
{
	assert(pq);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if(newNode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newNode->next = NULL;
	newNode->data = d;
	
	if(pq->tail == NULL)
	{
		pq->head = pq->tail = newNode;
	} 
	else
	{
		pq->tail->next = newNode;
		pq->tail = newNode;
	}
}
void QueuePop(Queue* pq)//队头出 
{
	assert(pq);
	assert(pq->head);//队列不为空
	if(pq->head->next == NULL)//只有一个结点的情况 
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
} 
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->head;
	while(cur != NULL)
	{
		++size;
		cur = cur->next;
	}
	return size;
}
bool QueueIsEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL; 
}
int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,1);
	QueuePush(&q,2);
	QueuePush(&q,3);
	QueuePush(&q,4);
	QueuePush(&q,5);
	printf("队列中元素个数为%d\n",QueueSize(&q));

	while(!QueueIsEmpty(&q))
	{
		printf("%d ",QueueFront(&q));
		QueuePop(&q);
	}	
	QueueDestory(&q);
	return 0;
} 
*/











//C++利用带头单向不循环链表实现队列
/*
#include<iostream>
#include<string>
using namespace std;
class QueueNode
{
	friend class QueueLink;
private:
	QueueNode* next;
};

class QueueLink
{
public:
	QueueLink();
	void push_QueueLink(void* data);
	void pop_QueueLink();
	int size();
	void* head();
	void* tail();
	bool isEmpty();
	~QueueLink();
private:
	QueueNode pHeader;
	QueueNode* pTail;//用于记录尾结点，不必通过遍历找到尾结点
	int m_size;
};
QueueLink::QueueLink()
{
	this->m_size = 0;
	this->pHeader.next = nullptr;
	this->pTail = &this->pHeader;
}

void QueueLink::push_QueueLink(void* data)
{
	if (data == nullptr)return;
	QueueNode* myNode = (QueueNode*)data;
	this->pTail->next = myNode;
	myNode->next = nullptr;
	this->pTail = myNode;
	++this->m_size;
}

void QueueLink::pop_QueueLink()
{
	if (this->m_size == 0)return;
	if (this->m_size == 1)
	{
		this->pHeader.next = nullptr;
		this->pTail = &this->pHeader;
	}
	else
	{
		QueueNode* pDel = this->pHeader.next;
		this->pHeader.next = pDel->next;
	}
	--this->m_size;
}

int QueueLink::size()
{
	return this->m_size;
}

void* QueueLink::head()
{
	return this->pHeader.next;
}

void* QueueLink::tail()
{
	return this->pTail;
}

bool QueueLink::isEmpty()
{
	if (this->m_size == 0)return true;
	return false;
}

QueueLink::~QueueLink()
{
	this->m_size = 0;
	this->pHeader.next = nullptr;
	this->pTail = &this->pHeader;
}

struct data
{
	void* Link;
	int m_data;
};
int main()
{
	QueueLink q;
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
	
	q.push_QueueLink(&p1);
	q.push_QueueLink(&p2);
	q.push_QueueLink(&p3);
	q.push_QueueLink(&p4);
	q.push_QueueLink(&p5);
	
	cout<<"队列中元素个数为:"<<q.size()<<endl;
	while(!q.isEmpty())
	{
		cout<<((data*)q.head())->m_data<<" ";
		q.pop_QueueLink();
	}	
	return 0;
}
*/
