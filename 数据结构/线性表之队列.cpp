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





//C����������ͷ����ѭ������ʵ�ֶ���
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<stdbool.h>
//typedef int QDataType;
//typedef struct QueueNode
//{
//	struct QueueNode* next;
//	QDataType data;
//}QNode;
//typedef struct Queue
//{
//	QNode* head;
//	QNode* tail;	
//}Queue;
//
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = pq->tail = NULL;
//}
//void QueueDestory(Queue* pq)
//{
//	assert(pq);
//	QNode* cur = pq->head;
//	while(cur != NULL)
//	{
//		QNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pq->head = pq->tail = NULL;
//}
//void QueuePush(Queue* pq,QDataType d)//��β�� 
//{
//	assert(pq);
//	QNode* newNode = (QNode*)malloc(sizeof(QNode));
//	if(newNode == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	newNode->next = NULL;
//	newNode->data = d;
//	
//	if(pq->tail == NULL)
//	{
//		pq->head = pq->tail = newNode;
//	} 
//	else
//	{
//		pq->tail->next = newNode;
//		pq->tail = newNode;
//	}
//}
//void QueuePop(Queue* pq)//��ͷ�� 
//{
//	assert(pq);
//	assert(pq->head);//���в�Ϊ��
//	if(pq->head->next == NULL)//ֻ��һ��������� 
//	{
//		free(pq->head);
//		pq->head = pq->tail = NULL;
//	}
//	else
//	{
//		QNode* next = pq->head->next;
//		free(pq->head);
//		pq->head = next;
//	}
//}
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(pq->head);
//	return pq->head->data;
//} 
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(pq->tail);
//	return pq->tail->data;
//}
//int QueueSize(Queue* pq)//Ҳ����struct Queue������һ�����ݳ�Աsize
//{
//	assert(pq);
//	int size = 0;
//	for(QNode* cur = pq->head; cur != NULL; cur = cur->next){
//		++size;
//	}
//	return size;
//}
//bool QueueIsEmpty(Queue* pq)
//{
//	assert(pq);
//	return pq->head == NULL; 
//}
//int main()
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q,1);
//	QueuePush(&q,2);
//	QueuePush(&q,3);
//	QueuePush(&q,4);
//	QueuePush(&q,5);
//	printf("������Ԫ�ظ���Ϊ%d\n",QueueSize(&q));
//
//	while(!QueueIsEmpty(&q))
//	{
//		printf("%d ",QueueFront(&q));
//		QueuePop(&q);
//	}	
//	QueueDestory(&q);
//	return 0;
//} 








