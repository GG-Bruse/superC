/*
ջ:
һ����������Ա�(�������Ա�)����ֻ�����ڹ̶���һ�˽��в����ɾ��Ԫ�ز�����
�������ݲ����ɾ��������һ�˳�Ϊջ������һ�˳�Ϊջ�ס�
ջ�е�����Ԫ�����غ���ȳ�LIFO(Last In First Out)ԭ��

ѹջ:ջ�Ĳ����������Ϊ��ջ/ѹջ/��ջ����������ջ��
��ջ:ջ��ɾ����������Ϊ��ջ����������ջ�� 
*/ 

/*
���������������ʵ��ջ
1.����:(����) 
����β����ջ��������ͷ��ջ�ס�ջ����Ƶ������ɾ����ʹ������β�ɱ�������Ų����
ȱ��:ջ�ռ䲻��ʱ�����ݼ������ݺ�ռ���˷�
2.����:
(������)����ͷ��ջ��������β��ջ�ס�ջ����Ƶ������ɾ����ʹ������ͷ�ɱ���Ƶ������Ѱ��β�ڵ㡣
(˫��ѭ������)����ͷ������β��ջ������ 
*/



//C�������ö�̬����ʵ��ջ(1) 
/*
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
typedef int SKDataType; 
typedef struct stack
{
	SKDataType* data;
	int top;
	int capacity;
}Stack;
void StackInit(Stack* ps)
{
	assert(ps);
	ps->data = (SKDataType*)malloc(sizeof(SKDataType)*4);
	if(ps->data == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	 
	ps->capacity = 4;
	ps->top = 0;//topָ��ջ��Ԫ�ص���һ��λ�� 
}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = ps->top = 0;
}
void StackPush(Stack* ps,SKDataType d)
{
	assert(ps);
	if(ps->top == ps->capacity)
	{
		SKDataType* newSpace = (SKDataType*)realloc(ps->data,ps->capacity * 2 * sizeof(SKDataType));
		if(newSpace == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->data = newSpace;
		ps->capacity *= 2;
	}
	ps->data[ps->top] = d;
	++ps->top; 
}
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);//ջ����Ϊ�� 
	--ps->top;
}
SKDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->data[ps->top - 1];
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
bool StackIsEmpty(Stack* ps) 
{
	assert(ps);
	return ps->top == 0;
} 
int main()
{
	Stack sk;
	StackInit(&sk);
	StackPush(&sk,1);
	StackPush(&sk,2);
	StackPush(&sk,3);
	StackPush(&sk,4);
	StackPush(&sk,5);
	
	while(!StackIsEmpty(&sk))
	{
		printf("%d ",StackTop(&sk));
		StackPop(&sk);
	}
	
	StackDestory(&sk);
	return 0; 
} 
*/


