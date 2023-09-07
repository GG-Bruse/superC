/****************************************************** 汉诺塔问题（LeetCode）*******************************************************/
/*
在经典汉诺塔问题中，有 3 根柱子及 N 个不同大小的穿孔圆盘，盘子可以滑入任意一根柱子
一开始，所有盘子自上而下按升序依次套在第一根柱子上(即每一个盘子只能放在更大的盘子上面)。移动圆盘时受到以下限制:
(1) 每次只能移动一个盘子;
(2) 盘子只能从柱子顶端滑出移到下一根柱子;
(3) 盘子只能叠在比它大的盘子上

示例1:
 输入：A = [2, 1, 0], B = [], C = []
 输出：C = [2, 1, 0]
示例2:
 输入：A = [1, 0], B = [], C = []
 输出：C = [1, 0]
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    void _hanota(vector<int>& A, vector<int>& B, vector<int>& C, int n)//将X上的盘子借助Y放入Z上
//    {
//        if (n == 1) {
//            C.push_back(A.back());
//            A.pop_back();
//            return;
//        }
//        _hanota(A, C, B, n - 1);
//        C.push_back(A.back());
//        A.pop_back();
//        _hanota(B, A, C, n - 1);
//
//    }
//    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
//        _hanota(A, B, C, A.size());
//    }
//};











/***************************************************** 合并两个有序链表（LeetCode）*************************************************/
/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
*/
//#include <iostream>
//using namespace std;
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//    
//};
//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
//    {
//        if (list1 == nullptr) return list2;
//        if (list2 == nullptr) return list1;
//
//        if (list1->val <= list2->val) {
//            list1->next = mergeTwoLists(list1->next, list2);
//            return list1;
//        }
//        else {
//            list2->next = mergeTwoLists(list1, list2->next);
//            return list2;
//        }
//    }
//};












/******************************************************* 反转链表（LeetCode）*******************************************************/
/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表
*/
//#include <iostream>
//using namespace std;
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//    
//};
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head)
//    {
//        if (head == nullptr || head->next == nullptr) return head;
//        ListNode* newhead = reverseList(head->next);
//        head->next->next = head;
//        head->next = nullptr;
//        return newhead;
//    }
//};











/************************************************* 两两交换链表中的节点（LeetCode）*************************************************/
/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）
*/
//#include <iostream>
//using namespace std;
//struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head)
//    {
//        if (head == nullptr || head->next == nullptr) return head;
//        ListNode* next = head->next;
//        head->next = swapPairs(next->next);
//        next->next = head;
//        return next;
//    }
//};









/******************************************************** Pow(x, n)（LeetCode）*****************************************************/
/*
实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）
*/
//#include <iostream>
//#include <cmath>
//using namespace std;
//class Solution {
//public:
//    double myPow(double x, int n) {
//        return n < 0 ? 1.0 / pow(x, -1.0 * n) : pow(x, n);
//    }
//    double Pow(double x, int n)
//    {
//        if (n == 0) return 1.0;
//        double ret = myPow(x, n / 2);
//        return n % 2 == 0 ? ret * ret : ret * ret * x;
//    }
//};