/*
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
*/

//递归
#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution
{
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		if (head == nullptr) return head;
		head->next = removeElements(head->next, val);
		return head->val == val ? head->next : head;
	}
};




//迭代
#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
	{
        struct ListNode* dummyHead = new ListNode(0, head);
        struct ListNode* temp = dummyHead;
        while (temp->next != NULL)
		{
            if (temp->next->val == val)
			{
                temp->next = temp->next->next;
            }
            else
			{
                temp = temp->next;
            }
        }
        return dummyHead->next;
    }
};