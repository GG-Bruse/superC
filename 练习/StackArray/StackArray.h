#pragma once
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