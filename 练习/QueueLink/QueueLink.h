#pragma once
class QueueNode
{
	friend class QueueLink;
private:
	QueueNode* next;
};

class QueueLink
{
public:
	QueueLink();
	void push_QueueLink(void* data);
	void pop_QueueLink();
	int size();
	void* head();
	void* tail();
	bool isEmpty();
	~QueueLink();
private:
	QueueNode pHeader;
	QueueNode* pTail;//用于记录尾结点，不必通过遍历找到尾结点
	int m_size;
};