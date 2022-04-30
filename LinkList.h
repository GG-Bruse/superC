#pragma once
/*
企业版
用户创建自定义类型时，必须预留4个字节的空间用于链表连接
*/
#include<iostream>
using namespace std;
class LinkNode
{
	friend class LinkList;
private:
	LinkNode* next;
};
class LinkList
{
public:
	LinkList();
	void insert(int pos, void* data);
	void push_back(void* data);
	void for_each(void(*MyPrint)(void*));
	void remove(int pos);
	~LinkList();
private:
	LinkNode pHeader;
	int m_size;
};