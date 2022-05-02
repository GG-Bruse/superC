#pragma once
class StackNode
{
	friend class StackLink;
private:
	StackNode* next;
};

class StackLink
{
public:
	StackLink();
	void top_back(void* data);
	void pop_back();
	void* top();
	int size();
	bool isEmpty();
	~StackLink();
private:
	StackNode pHeader;
	int m_size;
};