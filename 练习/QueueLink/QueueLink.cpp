#include"QueueLink.h"

QueueLink::QueueLink()
{
	this->m_size = 0;
	this->pHeader.next = nullptr;
	this->pTail = &this->pHeader;
}

void QueueLink::push_QueueLink(void* data)
{
	if (data == nullptr)return;
	QueueNode* myNode = (QueueNode*)data;
	this->pTail->next = myNode;
	myNode->next = nullptr;
	this->pTail = myNode;
	++this->m_size;
}

void QueueLink::pop_QueueLink()
{
	if (this->m_size == 0)return;
	if (this->m_size == 1)
	{
		this->pHeader.next = nullptr;
		this->pTail = &this->pHeader;
	}
	else
	{
		QueueNode* pDel = this->pHeader.next;
		this->pHeader.next = pDel->next;
	}
	--this->m_size;
}

int QueueLink::size()
{
	return this->m_size;
}

void* QueueLink::head()
{
	return this->pHeader.next;
}

void* QueueLink::tail()
{
	return this->pTail;
}

bool QueueLink::isEmpty()
{
	if (this->m_size == 0)return true;
	return false;
}

QueueLink::~QueueLink()
{
	this->m_size = 0;
	this->pHeader.next = nullptr;
	this->pTail = &this->pHeader;
}