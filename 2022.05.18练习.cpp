/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/


/*
在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），它的 next 指针指向链表的头节点。
这样一来，我们就不需要对头节点进行特殊的判断了
我们可以从哑节点开始遍历 L−n+1 个节点。当遍历到第 L-n+1L−n+1 个节点时，它的下一个节点就是我们需要删除的节点，
这样我们只需要修改一次指针，就能完成删除操作
*/

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
    int getLength(ListNode* head)
    {
        int length = 0;
        while (head)
        {
            ++length;
            head = head->next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* dummy = new ListNode(0, head);
        int length = getLength(head);
        ListNode* cur = dummy;
        for (int i = 1; i < length - n + 1; ++i)
        {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};


