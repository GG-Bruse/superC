/****************************************************** ��ŵ�����⣨LeetCode��*******************************************************/
/*
�ھ��人ŵ�������У��� 3 �����Ӽ� N ����ͬ��С�Ĵ���Բ�̣����ӿ��Ի�������һ������
һ��ʼ�������������϶��°������������ڵ�һ��������(��ÿһ������ֻ�ܷ��ڸ������������)���ƶ�Բ��ʱ�ܵ���������:
(1) ÿ��ֻ���ƶ�һ������;
(2) ����ֻ�ܴ����Ӷ��˻����Ƶ���һ������;
(3) ����ֻ�ܵ��ڱ������������

ʾ��1:
 ���룺A = [2, 1, 0], B = [], C = []
 �����C = [2, 1, 0]
ʾ��2:
 ���룺A = [1, 0], B = [], C = []
 �����C = [1, 0]
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    void _hanota(vector<int>& A, vector<int>& B, vector<int>& C, int n)//��X�ϵ����ӽ���Y����Z��
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











/***************************************************** �ϲ�������������LeetCode��*************************************************/
/*
��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
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












/******************************************************* ��ת����LeetCode��*******************************************************/
/*
���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
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