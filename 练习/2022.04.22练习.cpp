/*
给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表
*/

/*
由于给定的链表是排好序的，因此重复的元素在链表中出现的位置是连续的，因此我们只需要对链表进行一次遍历，就可以删除重复的元素。

具体地，我们从指针 cur 指向链表的头节点，随后开始对链表进行遍历。如果当前 cur 与 cur.next 对应的元素相同，
那么我们就将 cur.next 从链表中移除；否则说明链表中已经不存在其它与 cur 对应的元素相同的节点，因此可以将 cur 指向 cur.next。

当遍历完整个链表之后，我们返回链表的头节点即可。

细节

当我们遍历到链表的最后一个节点时，cur.next 为空节点，如果不加以判断，访问 cur.next 对应的元素会产生运行错误。
因此我们只需要遍历到链表的最后一个节点，而不需要遍历完整个链表。
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head)//若头结点为空，则直接返回
        {
            return head;
        }
        ListNode* cur = head;
        while (cur->next)//遍历链表
        {
            if (cur->val == cur->next->val)//发现重复元素
            {
                cur->next = cur->next->next;//通过间隔连接实现删除元素
            }
            else
            {
                cur = cur->next;//移动到下一元素
            }
        }
        return head;
    }
};











//本质为斐波那契数
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
*/


//动态规划
#include<iostream>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        int left = 0, right = 0, ret = 1;
        for (int i = 1; i <= n; ++i)
        {
            left = right;
            right = ret;
            ret = left + right;
        }
        return ret;
    }
};
int main()
{
    Solution s;
    cout << s.climbStairs(3) << endl;
        return 0;
}


//矩阵快速幂
//通项公式
