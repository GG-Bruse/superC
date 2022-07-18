




#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
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
    while (cur != NULL)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType d)//队尾入
{
    assert(pq);
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    if (newNode == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    newNode->next = NULL;
    newNode->data = d;

    if (pq->tail == NULL)
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
    if (pq->head->next == NULL)//只有一个结点的情况
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
    while (cur != NULL)
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

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate() {
    MyStack* ps = (MyStack*)malloc(sizeof(MyStack));
    if (ps == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    QueueInit(&ps->q1);
    QueueInit(&ps->q2);
    return ps;
}

void myStackPush(MyStack* obj, int x) {
    if (!QueueIsEmpty(&obj->q1))
    {
        QueuePush(&obj->q1, x);
    }
    else
    {
        QueuePush(&obj->q2, x);
    }
}

int myStackPop(MyStack* obj) {
    Queue* emptyQ = &obj->q1;
    Queue* noemptyQ = &obj->q2;
    if (!QueueIsEmpty(&obj->q1))
    {
        emptyQ = &obj->q2;
        noemptyQ = &obj->q1;
    }
    while (QueueSize(noemptyQ) > 1)//倒数据
    {
        QueuePush(emptyQ, QueueFront(noemptyQ));
        QueuePop(noemptyQ);
    }
    int top = QueueFront(noemptyQ);
    QueuePop(noemptyQ);
    return top;
}

int myStackTop(MyStack* obj) {
    if (!QueueIsEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
    {
        return QueueBack(&obj->q2);
    }
}

bool myStackEmpty(MyStack* obj) {
    return (QueueIsEmpty(&obj->q1) && QueueIsEmpty(&obj->q2));
}

void myStackFree(MyStack* obj) {
    QueueDestory(&obj->q1);
    QueueDestory(&obj->q2);
    free(obj);
    obj = NULL;
}
int main()
{
    MyStack* sk = myStackCreate();
    myStackPush(sk, 1);
    printf("%d\n", myStackPop(sk));
    myStackPush(sk, 2);
    printf("%d\n", myStackTop(sk));

    printf("%d\n", myStackEmpty(sk));
    return 0;
}



