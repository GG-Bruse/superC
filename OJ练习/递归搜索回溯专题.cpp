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












/**************************************************** 计算布尔二叉树的值（LeetCode）************************************************/
/*
给你一棵 完整二叉树 的根，这棵树有以下特征：
叶子节点 要么值为 0 要么值为 1 ，其中 0 表示 False ，1 表示 True
非叶子节点 要么值为 2 要么值为 3 ，其中 2 表示逻辑或 OR ，3 表示逻辑与 AND

计算 一个节点的值方式如下：
如果节点是个叶子节点，那么节点的值为它本身，即 True 或者 False
否则，计算两个孩子的节点值，然后将该节点的运算符对两个孩子值进行运算
返回根节点 root 的布尔运算值

完整二叉树 是每个节点有 0 个或者 2 个孩子的二叉树
叶子节点 是没有孩子的节点
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
//        if (root->left == nullptr) return root->val == 0 ? false : true;//完整二叉树,没有左子树,必没有右子树
//        int left = evaluateTree(root->left);
//        int right = evaluateTree(root->right);
//        return root->val == 2 ? (left | right) : left & right;
//    }
//};











/*************************************************** 求根节点到叶节点数字之和（LeetCode）******************************************/
/*
给你一个二叉树的根节点 root ，树中每个节点都存放有一个0到9之间的数字
每条从根节点到叶节点的路径都代表一个数字：

例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字123
计算从根节点到叶节点生成的所有数字之和

叶节点 是指没有子节点的节点
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