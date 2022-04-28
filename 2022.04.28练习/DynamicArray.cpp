#include"DynamicArray.h"

dynamicArray::dynamicArray(int capacity)
{
	if (capacity <= 0)return;
	this->m_pAdder = (void**)new (void*[capacity]);
	if (this->m_pAdder == nullptr)return;
	this->m_capacity = capacity;
	this->m_size = 0;
}

void dynamicArray::insert(int pos, void* data)
{
	if (this->m_pAdder == nullptr || data == nullptr)return;
	if (pos<0 || pos>this->m_size)
	{
		pos = this->m_size;//若位置无效则进行尾插
	}
	//动态扩展
	if (this->m_size == this->m_capacity)
	{
		void** newSpace = (void**)new(void*[this->m_capacity * 2]);//每次扩展为原来的两倍
		if (newSpace == nullptr)return;
		memcpy(newSpace, this->m_pAdder, sizeof(void*) * this->m_size);
		delete[]this->m_pAdder;
		this->m_pAdder = newSpace;
		this->m_capacity *= 2;
	}
	//插入元素
	for (int i = this->m_size - 1; i >= pos; --i)//反向遍历
	{
		this->m_pAdder[i + 1] = this->m_pAdder[i];//看似越界实则并没有，m_capacity > m_size
	}
	this->m_pAdder[pos] = data;
	++this->m_size;
}

void dynamicArray::push_back(void* data)
{
	this->insert(this->m_size, data);
}

void dynamicArray::for_each(void(*MyPrint)(void*))
{
	if (this->m_pAdder == nullptr || MyPrint == nullptr)return;
	for (int i = 0; i < this->m_size ; ++i)
	{
		MyPrint(this->m_pAdder[i]);
	}
}

void dynamicArray::remove(int pos)
{
	if (pos<0 || pos>this->m_size - 1)return;
	for (int i = pos; i < this->m_size - 1; ++i)
	{
		this->m_pAdder[i] = this->m_pAdder[i + 1];
	}
	--this->m_size;
}

void dynamicArray::remove(void* value, bool(*MyCompare)(void*, void*))
{
	if (value == nullptr)return;
	for (int i = 0; i < this->m_size; ++i)
	{
		if (MyCompare(this->m_pAdder[i], value))
		{
			this->remove(i);
			--i;
		}
	}
}

dynamicArray:: ~dynamicArray()
{
	if (this->m_pAdder != nullptr)
	{
		delete[]this->m_pAdder;
		this->m_pAdder = nullptr;
	}
}









































