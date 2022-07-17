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
	if(pq->head == NULL)//只有一个结点的情况 
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




















