/*
����:
һ����������Ա�(�������Ա�)��ֻ������һ�˽��в������ݲ���������һ�˽���ɾ�����ݲ������������Ա�
���о����Ƚ��ȳ�FIFO(First in First out)ԭ��

�����:���в��������һ�˱���Ϊ��β 
������:����ɾ��������һ�˱���Ϊ��ͷ 
*/

/*
���������������ʵ�ֶ��� 
1.����:(���ʺ�)
����ͷ����ͷ������β����β 
2.����:(����) 
(������)����ͷ����ͷ(ͷɾ)������β����β(β��) 
*/





//C����������ͷ����ѭ������ʵ�ֶ���(1)
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
void QueuePush(Queue* pq,QDataType d)//��β�� 
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
void QueuePop(Queue* pq)//��ͷ�� 
{
	assert(pq);
	assert(pq->head);//���в�Ϊ��
	if(pq->head->next == NULL)//ֻ��һ��������� 
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
	printf("������Ԫ�ظ���Ϊ%d\n",QueueSize(&q));

	while(!QueueIsEmpty(&q))
	{
		printf("%d ",QueueFront(&q));
		QueuePop(&q);
	}	
	QueueDestory(&q);
	return 0;
} 
*/












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
	QueueNode* pTail;//���ڼ�¼β��㣬����ͨ�������ҵ�β���
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
bool isLeft(char ch)
{
	return ch == '(';
}
bool isRight(char ch)
{
	return ch == ')';
}
void printError(char* str, string errMsg, char* pos)
{
	cout << "������Ϣ:" << errMsg << endl;
	cout << str << endl;
	int num = pos - str;
	for (int i = 0; i < num; ++i)
	{
		cout << " ";
	}
	cout << "~" << endl;
}
