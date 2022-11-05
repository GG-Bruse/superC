//线性表
/*
线性表是n个具有相同特性的数据元素的有限序列。
常见的线性表:顺序表、链表、栈、队列、字符串等 

线性表在逻辑上是线性结构，但在物理结构上并不一定是连续的。
线性表在物理上存储时，通常以数组和链式结构的形式存储。 
*/ 










//顺序表
/*
顺序表是用一段物理地址连续的单元依次存储数据元素的线性结构。
一般情况下采用数组存储,在数组上完成数据的增删改查。

顺序表一般可分为:
1.静态顺序表:使用定长数组存储
2.动态顺序表:使用动态开辟的数组存储 
*/ 




//静态顺序表C语言实现
/* 
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 1000
typedef int SQDataType;
typedef struct SeqList
{
	SQDataType arr[MAX_SIZE];
	int size;	
}SL;
void SeqListInit(SL* ps) 
{
	memset(ps->arr,0,sizeof(SQDataType)*MAX_SIZE);
	ps->size = 0;
}
void SeqListPushBack(SL* ps,SQDataType data)//尾插 
{
	if(ps->size >= MAX_SIZE)
	{
		printf("SeqList is full\n");
		return;
	}
	ps->arr[ps->size] = data;
	++ps->size;
}
void SeqListPushFront(SL* ps,SQDataType data)//头插 
{
	if(ps->size >= MAX_SIZE)
	{
		printf("SeqList is full\n");
		return;
	}
	for(int i = ps->size;i > 0; --i)
	{
		ps->arr[i] = ps->arr[i-1];
	} 
	ps->arr[0] = data;
	++ps->size;
}
void SeqListPopBack(SL* ps)//尾删 
{
	if(ps->size <= 0)
	{
		return;
	} 
	ps->arr[ps->size] = 0;
	--ps->size;
}
void SeqListPopFront(SL* ps)//头删 
{
	if(ps->size <= 0)
	{
		return;
	} 
	for(int i = 0;i < ps->size-1; ++i)
	{
		ps->arr[i] = ps->arr[i+1];
	} 
	--ps->size;
}
void for_each(SL* ps)//遍历
{
	for(int i = 0;i< ps->size; ++i)
	{
		printf("%d ",ps->arr[i]);
	}
	printf("\n");
}
int main()
{
	SL s;
	SeqListInit(&s);
	SeqListPushBack(&s,1);
	SeqListPushBack(&s,2);
	SeqListPushBack(&s,3);
	SeqListPushBack(&s,4);
	SeqListPushFront(&s,0);
	for_each(&s);
	SeqListPopFront(&s);
	SeqListPopBack(&s);
	for_each(&s);
	return 0;
} 
*/








//动态顺序表C语言实现
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int SQDataType;
typedef struct SeqList
{
	SQDataType* arr;
	int size;//有效数据的个数 
	int capacity;//容量  
}SL;

void SeqListCheckCapacity(SL* ps)//扩容 
{
	if(ps->size >= ps->capacity)
	{
		SQDataType* temp = (SQDataType*)realloc(ps->arr,sizeof(SQDataType)*ps->capacity*2);
		if(temp == NULL)
		{
			printf("realloc fail\n");
			return;
		}
		else
		{
			ps->arr = temp;
			ps->capacity *= 2;
		}
	}
}

void SeqListInit(SL* ps)//初始化 
{
	ps->arr = (SQDataType*)malloc(sizeof(SQDataType)*10); 
	if(ps->arr==NULL)
	{
		printf("malloc fail\n");
		return;
	}
	ps->size = 0;
	ps->capacity = 10;
}

void SeqListDestory(SL* ps)//销毁空间
{
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListInsert(SL* ps,int pos,SQDataType data)//按位置插入 
{
	if(pos > ps->size)
	{
		return;
	}
	SeqListCheckCapacity(ps);
	for(int i = ps->size; i > pos;--i)
	{
		ps->arr[i] = ps->arr[i-1];
	}
	ps->arr[pos] = data;
	++ps->size;
}

void SeqListErase(SL* ps,int pos)//按位置删除 
{
	if(pos >= ps->size)
	{
		return;
	}
	for(int i = pos;i < ps->size-1; ++i)
	{
		ps->arr[i] = ps->arr[i+1];
	}
	--ps->size;
}

void SeqListPushFront(SL* ps,SQDataType data)//头插 
{
	SeqListInsert(ps,0,data);
}

void SeqListPushBack(SL* ps,SQDataType data)//尾插 
{
	SeqListInsert(ps,ps->size,data);
}

void SeqListPopFront(SL* ps)//头删 
{
	SeqListErase(ps,0);
}

void SeqListPopBack(SL* ps)//尾删 
{
	SeqListErase(ps,ps->size-1);
}

void SeqListModity(SL* ps,int pos ,SQDataType data)//改
{
	if (pos >= ps->size)
	{
		return;
	}
	ps->arr[pos] = data;
}

int SeqListFind(SL* ps, SQDataType data)//查
{
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->arr[i] == data)
		{
			return i;
		}
	}
	return -1;
}

void for_each(SL* ps)//遍历
{
	for(int i = 0;i< ps->size; ++i)
	{
		printf("%d ",ps->arr[i]);
	}
	printf("\n");
}

int main()
{
	SL s;
	SeqListInit(&s);
	SeqListPushBack(&s,1);
	SeqListPushBack(&s,2);
	SeqListPushBack(&s,3);
	SeqListPushBack(&s,4);
	SeqListPushFront(&s,0);
	for_each(&s);
	SeqListPopFront(&s);
	SeqListPopBack(&s);
	for_each(&s);
	SeqListInsert(&s,0,-1);
	SeqListErase(&s,2);
	for_each(&s);
	SeqListModity(&s, 0, 1);
	for_each(&s);
	SeqListDestory(&s);
	return 0;
} 
*/









//动态顺序表的缺陷
/*
1.若空间不足，需要增容。增容会付出一定性能消耗，其次可能存在一定的空间浪费。
2.在头部或中部左右的插入删除效率较低，需要挪动数据。
*/




