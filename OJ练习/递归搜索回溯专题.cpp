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











/************************************************* �������������еĽڵ㣨LeetCode��*************************************************/
/*
����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣������ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻����
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









/******************************************************** Pow(x, n)��LeetCode��*****************************************************/
/*
ʵ�� pow(x, n) �������� x ������ n ���ݺ���������xn ��
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












/**************************************************** ���㲼����������ֵ��LeetCode��************************************************/
/*
����һ�� ���������� �ĸ��������������������
Ҷ�ӽڵ� ҪôֵΪ 0 ҪôֵΪ 1 ������ 0 ��ʾ False ��1 ��ʾ True
��Ҷ�ӽڵ� ҪôֵΪ 2 ҪôֵΪ 3 ������ 2 ��ʾ�߼��� OR ��3 ��ʾ�߼��� AND

���� һ���ڵ��ֵ��ʽ���£�
����ڵ��Ǹ�Ҷ�ӽڵ㣬��ô�ڵ��ֵΪ�������� True ���� False
���򣬼����������ӵĽڵ�ֵ��Ȼ�󽫸ýڵ�����������������ֵ��������
���ظ��ڵ� root �Ĳ�������ֵ

���������� ��ÿ���ڵ��� 0 ������ 2 �����ӵĶ�����
Ҷ�ӽڵ� ��û�к��ӵĽڵ�
*/
//#include <iostream>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}    
//};
//class Solution {
//public:
//    bool evaluateTree(TreeNode* root)
//    {
//        if (root->left == nullptr) return root->val == 0 ? false : true;//����������,û��������,��û��������
//        int left = evaluateTree(root->left);
//        int right = evaluateTree(root->right);
//        return root->val == 2 ? (left | right) : left & right;
//    }
//};











/*************************************************** ����ڵ㵽Ҷ�ڵ�����֮�ͣ�LeetCode��******************************************/
/*
����һ���������ĸ��ڵ� root ������ÿ���ڵ㶼�����һ��0��9֮�������
ÿ���Ӹ��ڵ㵽Ҷ�ڵ��·��������һ�����֣�

���磬�Ӹ��ڵ㵽Ҷ�ڵ��·�� 1 -> 2 -> 3 ��ʾ����123
����Ӹ��ڵ㵽Ҷ�ڵ����ɵ���������֮��

Ҷ�ڵ� ��ָû���ӽڵ�Ľڵ�
*/
//#include <iostream>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}    
//};
//class Solution {
//public:
//    int dfs(TreeNode* root, int num)
//    {
//        num = num * 10 + root->val;
//        if (root->left == nullptr && root->right == nullptr) return num;
//        int ret = 0;
//        if (root->left != nullptr) ret += dfs(root->left, num);
//        if (root->right != nullptr) ret += dfs(root->right, num);
//        return ret;
//    }
//    int sumNumbers(TreeNode* root) {
//        return dfs(root, 0);
//    }
//};