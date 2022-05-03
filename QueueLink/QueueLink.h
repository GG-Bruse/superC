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
	QueueNode* pTail;//���ڼ�¼β��㣬����ͨ�������ҵ�β���
	int m_size;
};