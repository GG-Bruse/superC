#pragma once
/*
��ҵ��
�û������Զ�������ʱ������Ԥ��4���ֽڵĿռ�������������
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