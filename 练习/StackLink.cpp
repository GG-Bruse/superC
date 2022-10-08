#include"StackLink.h"

StackLink::StackLink()
{
	this->pHeader.next = nullptr;
	this->m_size = 0;
}

void StackLink::top_back(void* data)
{
	if (data == nullptr)return;
	StackNode* myNode = (StackNode*)data;
	myNode->next = this->pHeader.next;
	this->pHeader.next = myNode;
	++this->m_size;
}

void StackLink::pop_back()
{
	StackNode* pDel = this->pHeader.next;
	this->pHeader.next = pDel->next;
	--this->m_size;
}

void* StackLink::top()
{
	if (this->m_size == 0)return nullptr;
	return this->pHeader.next;
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
	this->pHeader.next = nullptr;
	this->m_size = 0;
}





