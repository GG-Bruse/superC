#pragma once
#include<cstring>
class dynamicArray
{
public:
	dynamicArray(int capcity);
	void insert(int pos, void* data);
	void push_back(void* data);
	void for_each(void(*MyPrint)(void*));//�ڶ�������Ϊ����ָ�룬���û��ṩ
	void remove(int pos);
	void remove(void* value, bool(*MyCompare)(void*, void*));
	~dynamicArray();

private:
	void** m_pAdder;//ά����ʵ�����ڶ�����ָ��
	int m_capacity;//����
	int m_size;//��ǰ��С
};