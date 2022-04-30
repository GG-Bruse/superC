#include"LinkList.h"

LinkList::LinkList()
{
	this->pHeader.next = nullptr;
	this->m_size = 0;
}

void LinkList::insert(int pos, void* data)
{
	if (data == nullptr)return;
	if (pos<0 || pos>this->m_size)
	{
		pos = this->m_size;//无效位置变为尾插
	}
	LinkNode* NewNode = (LinkNode*)data;
	LinkNode* pCurrent = &(this->pHeader);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;//找到前驱结点
	}
	//变更指针指向
	NewNode->next = pCurrent->next;
	pCurrent->next = NewNode;
	++this->m_size;
}

void LinkList::push_back(void* data)
{
	this->insert(this->m_size, data);
}

void LinkList::for_each(void(*MyPrint)(void*))
{
	LinkNode* node = this->pHeader.next;
	for (int i = 0; i < this->m_size; ++i)
	{
		MyPrint(node);
		node = node->next;
	}
}

void LinkList::remove(int pos)
{
	if (pos<0 || pos>this->m_size - 1)return;
	LinkNode* pCurrent = &(this->pHeader);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;//找到前驱结点
	}
	LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	--this->m_size;
}

LinkList::~LinkList()
{
	this->pHeader.next = nullptr;
	this->m_size = 0;
}