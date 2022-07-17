/*
栈:
一种特殊的线性表(受限线性表)，其只允许在固定的一端进行插入和删除元素操作。
进行数据插入和删除操作的一端称为栈顶，另一端称为栈底。
栈中的数据元素遵守后进先出LIFO(Last In First Out)原则。

压栈:栈的插入操作被称为进栈/压栈/入栈，入数据在栈顶
出栈:栈的删除操作被称为出栈，出数据在栈顶 
*/ 

/*
利用数组和链表都可实现栈
1.数组:(更优) 
数组尾当作栈顶，数组头作栈底。栈顶需频繁插入删除，使用数组尾可避免数据挪动。
缺陷:栈空间不足时的扩容及其扩容后空间的浪费
2.链表:
(单链表)链表头作栈顶，链表尾作栈底。栈顶需频繁插入删除，使用链表头可避免频繁遍历寻找尾节点。
(双向循环链表)链表头、链表尾作栈顶都可 
*/



//C语言利用动态数组实现栈(1) 
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
	ps->top = 0;//top指向栈顶元素的上一个位置 
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
	assert(ps->top > 0);//栈不可为空 
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


