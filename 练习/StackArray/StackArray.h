#pragma once
#define MAX  1024

#include<iostream>
#include<cstring>
using namespace std;

class Stack
{
public:
	Stack();
	void top_back(void* data);//压栈
	void pop_back();//出栈
	void* top();//返回栈顶
	int size();
	bool isEmpty();
	~Stack();
private:
	void* data[MAX];//指针数组——栈数组
	int m_size;
};