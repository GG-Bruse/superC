/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int size = nums.size();
        if (size < 2)return size;
        int slow = 2, fast = 2;
        while (fast < size)
        {
            if (nums[slow - 2] != nums[fast])
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
int main()
{
    vector<int>nums{ 1, 1, 1, 2, 2, 3 };
    Solution s;
    int num = s.removeDuplicates(nums);
    for (int i = 0; i < num; ++i)
    {
        cout << nums[i] << " ";
    }
    return 0;
}









/*
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
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
        if (head == nullptr)
        {
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while (cur->next && cur->next->next)
        {
            if (cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x)
                {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
