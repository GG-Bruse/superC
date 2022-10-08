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
(������)����ͷ��ջ��������β��ջ�ס�ջ����Ƶ������ɾ����ʹ������ͷ��ջ���ɱ���Ƶ������Ѱ��β�ڵ㡣
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







//C++��������ʵ��ջ 
/*
#define MAX  1024
#include<iostream>
#include<cstring>
using namespace std;

class Stack
{
public:
	Stack();
	void top_back(void* data);//ѹջ
	void pop_back();//��ջ
	void* top();//����ջ��
	int size();
	bool isEmpty();
	~Stack();
private:
	void* data[MAX];//ָ�����顪��ջ����
	int m_size;
};
Stack::Stack()
{
	this->m_size = 0;
	memset(this->data, 0, sizeof(void*) * MAX);
}

void Stack::top_back(void* data)
{
	if (data == nullptr)return;
	this->data[this->m_size] = data;
	++this->m_size;
}

void Stack::pop_back()
{
	this->data[this->m_size - 1] = nullptr;
	--this->m_size;
}

void* Stack::top()
{
	if (this->m_size == 0)return nullptr;
	return this->data[this->m_size - 1];
}

int Stack::size()
{
	return this->m_size;
}

bool Stack::isEmpty()
{
	if (this->m_size == 0)return true;
	return false;
}

Stack::~Stack()
{
	this->m_size = 0;
	memset(this->data, 0, sizeof(void*) * MAX);
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
int main()
{
	char* str = (char*)"5 + 5 * (6) + 9 / 3 * 1 - ( 1 + 310";
	char* p = str;
	Stack sk;
	while (*p != '\0')
	{
		if (isLeft(*p))
		{
			sk.top_back(p);
		}
		if (isRight(*p))
		{
			if (sk.size() > 0)
			{
				sk.pop_back();
			}
			else
			{
				printError(str, "������û��ƥ�䵽��Ӧ��������", p);
			}
		}
		++p;
	}
	while (sk.size() > 0)
	{
		printError(str, "������û��ƥ�䵽������", (char*)sk.top());
		sk.pop_back();
	}
	return 0;
}
*/















//C++���õ�����ʵ��ջ
/*
#include<iostream>
#include<cstdlib>
using namespace std;
class StackNode
{
	friend class StackLink;
private:
	StackNode* next;
	void* data;
};

class StackLink
{
public:
	StackLink();
	void top_back(void* data);
	void pop_back();
	void* top();
	int size();
	bool isEmpty();
	~StackLink();
private:
	StackNode pHeader;
	int m_size;
};
StackLink::StackLink()
{
	this->pHeader.next = nullptr;
	this->m_size = 0;
}

void StackLink::top_back(void* data)
{
	if (data == nullptr)return;
	StackNode* myNode = (StackNode*)malloc(sizeof(StackNode));
	if(myNode == nullptr)return;
	myNode->data = data;
	
	myNode->next = this->pHeader.next;
	this->pHeader.next = myNode;
	++this->m_size;
}

void StackLink::pop_back()
{
	StackNode* pDel = this->pHeader.next;
	this->pHeader.next = pDel->next;
	free(pDel);
	pDel = nullptr;
	--this->m_size;
}

void* StackLink::top()
{
	if (this->m_size == 0)return nullptr;
	return this->pHeader.next->data;
}

int StackLink::size()
{
	return this->m_size;
}

bool StackLink::isEmpty()
{
	if (this->m_size == 0)
	{
		return true;
	}
	return false;
}

StackLink::~StackLink()
{
	for(StackNode* cur = pHeader.next;cur != nullptr;)
	{
		StackNode* next = cur->next;
		free(cur);
		cur = next;
	}
	this->pHeader.next = nullptr;
	this->m_size = 0;
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
int main()
{
	char* str = (char*)"5 + 5 * (6) + 9 / 3 * 1 - ) 1 + 310";
	char* p = str;
	StackLink sk;
	while (*p != '\0')
	{
		if (isLeft(*p))
		{
			sk.top_back(p);
		}
		if (isRight(*p))
		{
			if (sk.size() > 0)
			{
				sk.pop_back();
			}
			else
			{
				printError(str, "������û��ƥ�䵽��Ӧ��������", p);
			}
		}
		++p;
	}
	while (sk.size() > 0)
	{
		printError(str, "������û��ƥ�䵽������", (char*)sk.top());
		sk.pop_back();
	}
	return 0;
}
*/
