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








//��̬˳���C����ʵ��
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









//��̬˳����ȱ��
/*
1.���ռ䲻�㣬��Ҫ���ݡ����ݻḶ��һ���������ģ���ο��ܴ���һ���Ŀռ��˷ѡ�
2.��ͷ�����в����ҵĲ���ɾ��Ч�ʽϵͣ���ҪŲ�����ݡ�
*/




