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
1.����:(���š�����Ч�ʸ���) 
����β����ջ��������ͷ��ջ�ס�ջ����Ƶ������ɾ����ʹ������β�ɱ�������Ų����
ȱ��:ջ�ռ䲻��ʱ�����ݼ������ݺ�ռ���˷�
2.����:
(������)����ͷ��ջ��������β��ջ�ס�ջ����Ƶ������ɾ����ʹ������ͷ��ջ���ɱ���Ƶ������Ѱ��β�ڵ㡣
(˫��ѭ������)����ͷ������β��ջ������
*/



//C�������ö�̬����ʵ��ջ
//#include<stdio.h>
//#include<stdbool.h>
//#include<stdlib.h>
//#include<assert.h>
//typedef int SKDataType; 
//typedef struct stack
//{
//	SKDataType* data;
//	int top;//ָ�����һ�����ݵ���һ��λ��
//	int capacity;
//}Stack;
//void StackInit(Stack* ps)
//{
//	assert(ps);
//	ps->data = NULL;
//	ps->capacity = ps->top = 0;
//}
//void StackDestory(Stack* ps)
//{
//	assert(ps);
//	free(ps->data);
//	ps->data = NULL;
//	ps->capacity = ps->top = 0;
//}
//void StackPush(Stack* ps,SKDataType d)
//{
//	assert(ps);
//	if(ps->top == ps->capacity)
//	{
//		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		SKDataType* newSpace = (SKDataType*)realloc(ps->data,newCapacity * sizeof(SKDataType));
//		if(newSpace == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		ps->data = newSpace;
//		ps->capacity = newCapacity;
//	}
//	ps->data[ps->top] = d;
//	++ps->top;
//}
//void StackPop(Stack* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);//ջ����Ϊ�� 
//	--ps->top;
//}
//SKDataType StackTop(Stack* ps)
//{
//	assert(ps);
//	assert(ps->top > 0);
//	return ps->data[ps->top - 1];
//}
//int StackSize(Stack* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//bool StackIsEmpty(Stack* ps) 
//{
//	assert(ps);
//	return ps->top == 0;
//} 
//int main()
//{
//	Stack sk;
//	StackInit(&sk);
//	StackPush(&sk,1);
//	StackPush(&sk,2);
//	StackPush(&sk,3);
//	StackPush(&sk,4);
//	StackPush(&sk,5);
//	
//	while(!StackIsEmpty(&sk))
//	{
//		printf("%d ",StackTop(&sk));
//		StackPop(&sk);
//	}
//	
//	StackDestory(&sk);
//	return 0; 
//} 















//��׺���ʽת��׺���ʽ
/*
������׺���ʽ
1.��������ֱ�����
2.���ڷ���:
			(1)������ֱ�ӽ�ջ(Ĭ�����������ȼ����)
			(2)�������ջ�����Ž��бȽ�:
									��ջ���������ȼ����ڵ������������ջ�����ŵ������ٽ������ѹջ
									��ջ���������ȼ��ϵͣ���ֱ�ӽ������ѹջ
			(3)������:��ջ�����ŵ����������ֱ��ƥ�䵽�����ţ�����������ͬʱ����
����������ջ�����з��ŵ��������
*/

//��׺���ʽ����
/*
������׺���ʽ
1.��������ֱ�ӽ�ջ
2.���ڷ���:
			(1)ջ�е�������Ԫ�أ��ֱ�Ϊ�Ҳ��������������
			(2)���㣬�������ѹ��ջ��
��������ʱ��ջ��Ψһ����Ϊ������
*/

