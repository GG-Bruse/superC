#include"StackArray.h"

Stack::Stack()
{
	this->m_size = 0;
	memset(this->data, 0, sizeof(void*) * MAX);
}

void Stack::top_back(void* data)
{
	if (data == nullptr)return;
	this->data[MAX - (this->m_size + 1)] = data;
	++this->m_size;
}

void Stack::pop_back()
{
	this->data[MAX - (this->m_size + 1)] = nullptr;
	--this->m_size;
}

void* Stack::top()
{
	if (this->m_size == 0)return nullptr;
	return this->data[MAX - (this->m_size)];
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
