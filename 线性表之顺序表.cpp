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








//动态顺序表C语言实现(1)
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









//动态顺序表(动态数组)C语言实现(2)
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct dynamicArray
{
	void** m_pAddr;//维护真实开辟在堆区的空间 
	int m_capacity;//容量
	int m_size;//当前大小	 
};

struct dynamicArray* init_DynamicArray(int capacity)
{
	if(capacity <= 0)
		return NULL;
	
	struct dynamicArray* array = (struct dynamicArray*)malloc(sizeof(struct dynamicArray));
	if(array == NULL)
		return NULL;
	
	array->m_pAddr = (void**)malloc(sizeof(void*)*capacity);
	array->m_capacity = capacity;
	array->m_size = 0;
	return array;
}

void insert_DynamicArray(struct dynamicArray* array,int pos,void* data)
{
	if(array == NULL || data == NULL)
		return;
	if(pos < 0 || pos > array->m_size)
		pos = array->m_size;//位置无效则进行尾插
	
	if(array->m_size >= array->m_capacity)
	{
		void** newSpace = (void**)realloc(array->m_pAddr,sizeof(void*)*array->m_capacity*2);
		if(newSpace == NULL)
			return;
		free(array->m_pAddr);
		array->m_pAddr = newSpace;
		array->m_capacity *= 2;
	}
	
	for(int i = array->m_size; i > pos;--i)
	{
		array->m_pAddr[i] = array->m_pAddr[i-1];
	}
	array->m_pAddr[pos] = data;
	++array->m_size;
}

void removebyPos_DynamicArray(struct dynamicArray* array,int pos)
{
	if(array == NULL || pos<0 || pos>array->m_size-1)
		return;
	for(int i = pos;i<array->m_size-1;++i)
	{
		array->m_pAddr[i] = array->m_pAddr[i+1]; 
	}
	--array->m_size;
}

void removebyValue_DynamicArray(struct dynamicArray* array,void* value,int(myCompare)(void*,void*))//==无法完成各种数据类型的比较，由用户提供回调函数 
{
	if(array == NULL || value == NULL || myCompare == NULL)
		return;
	for(int i = 0;i<array->m_size;++i)
	{
		if(myCompare(array->m_pAddr[i],value))
		{
			removebyPos_DynamicArray(array,i);
			break;
		}
	} 
}

void for_each(struct dynamicArray* array,void(*myPrint)(void*))//参数三为函数指针，由于不知道数据类型，需要用户自行提供回调函数 
{
	if(array == NULL || myPrint == NULL)
		return;
	for(int i = 0;i<array->m_size;++i)
	{
		myPrint(array->m_pAddr[i]);
	}
	printf("\n");
}

void destory_DynamicArray(struct dynamicArray* array)
{
	if(array == NULL)
		return;
	if(array->m_pAddr != NULL)
	{
		free(array->m_pAddr);
		array->m_pAddr = NULL;
	}
	free(array);
	array = NULL;
}


void myPrint(void* data)
{
	printf("%d ",*(int*)data);
}
int myCompare(void* a,void* b)
{
	return (*(int*)a == *(int*)b);
}
int main()
{
	int p1 = 1;
	int p2 = 2;
	int p3 = 3;
	int p4 = 4;
	int p5 = 5;
	int p6 = 6;
	int compare = 1;
	struct dynamicArray* array = init_DynamicArray(10);
	insert_DynamicArray(array,0,&p1);
	insert_DynamicArray(array,0,&p2);
	insert_DynamicArray(array,0,&p3);
	insert_DynamicArray(array,0,&p4);
	insert_DynamicArray(array,0,&p5);
	insert_DynamicArray(array,0,&p6);
	for_each(array,myPrint);
	removebyPos_DynamicArray(array,0);
	removebyValue_DynamicArray(array,&compare,myCompare);
	for_each(array,myPrint);
	destory_DynamicArray(array);
	return 0;
}
*/




//动态顺序表的缺陷
/*
1.若空间不足，需要增容。增容会付出一定性能消耗，其次可能存在一定的空间浪费。
2.在头部或中部左右的插入删除效率较低，需要挪动数据。
*/

