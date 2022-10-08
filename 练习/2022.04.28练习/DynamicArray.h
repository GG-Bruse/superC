#pragma once
#include<cstring>
class dynamicArray
{
public:
	dynamicArray(int capcity);
	void insert(int pos, void* data);
	void push_back(void* data);
	void for_each(void(*MyPrint)(void*));//第二个参数为函数指针，由用户提供
	void remove(int pos);
	void remove(void* value, bool(*MyCompare)(void*, void*));
	~dynamicArray();

private:
	void** m_pAdder;//维护真实开辟在堆区的指针
	int m_capacity;//容量
	int m_size;//当前大小
};