//���Ա�
/*
���Ա���n��������ͬ���Ե�����Ԫ�ص��������С�
���������Ա�:˳�������ջ�����С��ַ����� 

���Ա����߼��������Խṹ����������ṹ�ϲ���һ���������ġ�
���Ա��������ϴ洢ʱ��ͨ�����������ʽ�ṹ����ʽ�洢�� 
*/ 










//˳���
/*
˳�������һ�������ַ�����ĵ�Ԫ���δ洢����Ԫ�ص����Խṹ��
һ������²�������洢,��������������ݵ���ɾ�Ĳ顣

˳���һ��ɷ�Ϊ:
1.��̬˳���:ʹ�ö�������洢
2.��̬˳���:ʹ�ö�̬���ٵ�����洢 
*/ 




//��̬˳���C����ʵ��
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
void SeqListPushBack(SL* ps,SQDataType data)//β�� 
{
	if(ps->size >= MAX_SIZE)
	{
		printf("SeqList is full\n");
		return;
	}
	ps->arr[ps->size] = data;
	++ps->size;
}
void SeqListPushFront(SL* ps,SQDataType data)//ͷ�� 
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
void SeqListPopBack(SL* ps)//βɾ 
{
	if(ps->size <= 0)
	{
		return;
	} 
	ps->arr[ps->size] = 0;
	--ps->size;
}
void SeqListPopFront(SL* ps)//ͷɾ 
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
void for_each(SL* ps)//����
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








//��̬˳���C����ʵ��(1)
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int SQDataType;
typedef struct SeqList
{
	SQDataType* arr;
	int size;//��Ч���ݵĸ��� 
	int capacity;//����  
}SL;

void SeqListCheckCapacity(SL* ps)//���� 
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

void SeqListInit(SL* ps)//��ʼ�� 
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

void SeqListDestory(SL* ps)//���ٿռ�
{
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListInsert(SL* ps,int pos,SQDataType data)//��λ�ò��� 
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

void SeqListErase(SL* ps,int pos)//��λ��ɾ�� 
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

void SeqListPushFront(SL* ps,SQDataType data)//ͷ�� 
{
	SeqListInsert(ps,0,data);
}

void SeqListPushBack(SL* ps,SQDataType data)//β�� 
{
	SeqListInsert(ps,ps->size,data);
}

void SeqListPopFront(SL* ps)//ͷɾ 
{
	SeqListErase(ps,0);
}

void SeqListPopBack(SL* ps)//βɾ 
{
	SeqListErase(ps,ps->size-1);
}

void SeqListModity(SL* ps,int pos ,SQDataType data)//��
{
	if (pos >= ps->size)
	{
		return;
	}
	ps->arr[pos] = data;
}

int SeqListFind(SL* ps, SQDataType data)//��
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

void for_each(SL* ps)//����
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









//��̬˳���(��̬����)C����ʵ��(2)
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct dynamicArray
{
	void** m_pAddr;//ά����ʵ�����ڶ����Ŀռ� 
	int m_capacity;//����
	int m_size;//��ǰ��С	 
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
		pos = array->m_size;//λ����Ч�����β��
	
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

void removebyValue_DynamicArray(struct dynamicArray* array,void* value,int(myCompare)(void*,void*))//==�޷���ɸ����������͵ıȽϣ����û��ṩ�ص����� 
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

void for_each(struct dynamicArray* array,void(*myPrint)(void*))//������Ϊ����ָ�룬���ڲ�֪���������ͣ���Ҫ�û������ṩ�ص����� 
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




//��̬˳����ȱ��
/*
1.���ռ䲻�㣬��Ҫ���ݡ����ݻḶ��һ���������ģ���ο��ܴ���һ���Ŀռ��˷ѡ�
2.��ͷ�����в����ҵĲ���ɾ��Ч�ʽϵͣ���ҪŲ�����ݡ�
*/

