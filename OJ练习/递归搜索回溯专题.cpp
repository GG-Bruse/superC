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










/******************************************************* 二叉树剪枝（LeetCode）******************************************************/
/*
给你二叉树的根结点root，此外树的每个结点的值要么是0，要么是1
返回移除了所有不包含 1 的子树的原二叉树
节点node的子树为node本身加上所有node的后代
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
//    TreeNode* pruneTree(TreeNode* root)
//    {
//        if (root == nullptr) return nullptr;
//
//        root->left = pruneTree(root->left);
//        root->right = pruneTree(root->right);
//        if (root->left == nullptr && root->right == nullptr && root->val == 0) {
//            delete root;
//            root = nullptr;
//        }
//        return root;
//    }
//};











/***************************************************** 验证二叉搜索树（LeetCode）****************************************************/
/*
给你一个二叉树的根节点root ，判断其是否是一个有效的二叉搜索树
有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数
节点的右子树只包含 大于 当前节点的数
所有左子树和右子树自身必须也是二叉搜索树
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
//    long prev = LONG_MIN;//记录前一个值,在二叉搜索树中,中序遍历的情况下,前一个数必比后一个数小
//    bool isValidBST(TreeNode* root)
//    {
//        if (root == nullptr) return true;
//
//        bool left = isValidBST(root->left);
//        if (!left) return false;//剪枝
//
//        bool current = false;
//        if (root->val > prev) current = true;
//        if (!current) return false;//剪枝
//        prev = root->val;
//
//        bool right = isValidBST(root->right);
//
//        return left && right && current;
//    }
//};










/************************************************** 二叉搜索树中第K小的元素（LeetCode）*********************************************/
/*
给定一个二叉搜索树的根节点root，和一个整数k，请你设计一个算法查找其中第k个最小元素（从1开始计数）
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
//    int count = 0;
//    int ret = 0;
//    int kthSmallest(TreeNode* root, int k) {
//        count = k;
//        dfs(root);
//        return ret;
//    }
//    void dfs(TreeNode* root)
//    {
//        if (root == nullptr || count == 0) return;
//        dfs(root->left);
//        --count;
//        if (count == 0) ret = root->val;
//        dfs(root->right);
//    }
//};











/******************************************************** 二叉树的所有路径（LeetCode）***********************************************************/
/*
给你一个二叉树的根节点 root ，按任意顺序 ，返回所有从根节点到叶子节点的路径
叶子节点 是指没有子节点的节点
*/
//#include <iostream>
//#include <vector>
//#include <string>
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
//    vector<string> ret;
//    void dfs(TreeNode* root, string str)//不用引用是关键
//    {
//        str += to_string(root->val);
//        if (root->left == nullptr && root->right == nullptr) {
//            ret.push_back(str);
//            return;
//        }
//        str += "->";
//        if (root->left) dfs(root->left, str);
//        if (root->right) dfs(root->right, str);
//    }
//    vector<string> binaryTreePaths(TreeNode* root) {
//        if (root == nullptr) return ret;
//
//        string str;
//        dfs(root, str);
//        return ret;
//    }
//};









/********************************************************** 全排列（LeetCode）*******************************************************/
/*
给定一个不含重复数字的数组nums ，返回其所有可能的全排列 。你可以按任意顺序 返回答案
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> ret;
//
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<int> tmp;
//        dfs(nums, tmp);
//        return ret;
//    }
//    void dfs(vector<int> nums, vector<int> retNum)
//    {
//        int size = nums.size();
//        if (size == 0) {
//            ret.push_back(retNum);
//            return;
//        }
//        for (int i = 0; i < size; ++i)
//        {
//            vector<int> tmp(nums.begin(), nums.end());
//            retNum.push_back(nums[i]);
//            tmp.erase(tmp.begin() + i);
//            dfs(tmp, retNum);
//            retNum.pop_back();
//        }
//    }
//};










/******************************************************* 子集（LeetCode）************************************************************/
/*
给你一个整数数组nums ，数组中的元素互不相同 。返回该数组所有可能的子集（幂集）
解集不能包含重复的子集。你可以按任意顺序返回解集
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//
//    vector<vector<int>> subsets(vector<int>& nums) {
//        dfs(nums);
//        return ret;
//    }
//    void dfs(vector<int> nums) {
//        ret.push_back(path);
//        for (int i = 0; i < nums.size(); ++i) {
//            path.push_back(nums[i]);
//            dfs(vector<int>(nums.begin() + i + 1, nums.end()));
//            path.pop_back();
//        }
//    }
//};











/************************************************ 找出所有子集的异或总和再求和（LeetCode）*******************************************/
/*
一个数组的异或总和定义为数组中所有元素按位XOR的结果；如果数组为空，则异或总和为0
例如，数组[2,5,6]的异或总和为2 XOR 5 XOR 6 = 1
给你一个数组nums，请你求出nums中每个子集的异或总和，计算并返回这些值相加之和

注意：在本题中，元素相同的不同子集应多次计数
数组a是数组b的一个子集的前提条件是：从b删除几个（也可能不删除）元素能够得到a
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int sum = 0;
//    int path = 0;
//
//    int subsetXORSum(vector<int>& nums)
//    {
//        dfs(nums, 0);
//        return sum;
//    }
//    void dfs(vector<int> nums, int pos)
//    {
//        sum += path;
//        for (int i = pos; i < nums.size(); ++i) {
//            path ^= nums[i];
//            dfs(nums, i + 1);
//            path ^= nums[i];
//        }
//    }
//};










/******************************************************* 全排列 II（LeetCode）*******************************************************/
/*
给定一个可包含重复数字的序列nums，按任意顺序返回所有不重复的全排列
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    bool check[9];//标志nums中该下标是否使用过
//
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        dfs(nums, 0);
//        return ret;
//    }
//    void dfs(vector<int> nums, int pos)
//    {
//        if (nums.size() == pos) {
//            ret.push_back(path);
//            return;
//        }
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            if (check[i] == false && (i == 0 || nums[i - 1] != nums[i] || check[i - 1] == true)) //剪枝
//            {
//                path.push_back(nums[i]);
//                check[i] = true;
//                dfs(nums, pos + 1);
//                path.pop_back();
//                check[i] = false;
//            }
//        }
//    }
//};









/**************************************************** 电话号码的字母组合（LeetCode）*********************************************/
/*
给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合。答案可以按任意顺序返回
给出数字到字母的映射如下（与电话按键相同）。注意1不对应任何字母
*/
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    unordered_map<char, string> hash{ {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
//            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
//    vector<string> ret;
//    string path;
//    vector<string> letterCombinations(string digits)
//    {
//        if (digits.size() == 0) return ret;
//        dfs(digits, 0);
//        return ret;
//    }
//    void dfs(string digits, int pos)
//    {
//        if (digits.size() == pos) {
//            ret.push_back(path);
//            return;
//        }
//        string tmp = hash[digits[pos]];
//        for (int i = 0; i < tmp.size(); ++i) {
//            path.push_back(tmp[i]);
//            dfs(digits, pos + 1);
//            path.pop_back();
//        }
//    }
//};









/******************************************************** 括号生成（LeetCode）****************************************************/
/*
数字n代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且有效的括号组合
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    vector<string> ret;
//    string path;
//    int left = 0, right = 0, num = 0;
//    /*
//    左括号数量 = 右括号数量 = 括号对数
//    从头开始的任意一个子串, 左括号的数量 >= 右括号的数量
//    */
//    vector<string> generateParenthesis(int n) {
//        num = n;
//        dfs();
//        return ret;
//    }
//    void dfs()
//    {
//        if (num == right) {
//            ret.push_back(path);
//            return;
//        }
//        if (left < num) {
//            path.push_back('('), ++left;
//            dfs();
//            path.pop_back(), --left;
//        }
//        if (right < left) {
//            path.push_back(')'), ++right;
//            dfs();
//            path.pop_back(), --right;
//        }
//    }
//};










/****************************************************** 组合（LeetCode）*********************************************************/
/*
给定两个整数n和k，返回范围[1, n]中所有可能的k个数的组合
你可以按 任何顺序 返回答案
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    int num = 0, knum = 0;
//
//    vector<vector<int>> combine(int n, int k) {
//        num = n, knum = k;
//        dfs(1);
//        return ret;
//    }
//    void dfs(int start)
//    {
//        if (path.size() == knum) {
//            ret.push_back(path);
//            return;
//        }
//        for (int i = start; i <= num; ++i) {
//            path.push_back(i);
//            dfs(i + 1);
//            path.pop_back();
//        }
//    }
//};










/******************************************************** 目标和（LeetCode）*********************************************************/
/*
给你一个非负整数数组nums和一个整数target
向数组中的每个整数前添加'+'或'-'，然后串联起所有整数，可以构造一个表达式：
例如，nums = [2, 1] ，可以在2之前添加'+'，在1之前添加'-'，然后串联起来得到表达式"+2-1"
返回可以通过上述方法构造的、运算结果等于target的不同表达式的数目
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int ret = 0;
//    int target = 0;
//
//    int findTargetSumWays(vector<int>& nums, int _target) {
//        target = _target;
//        dfs(nums, 0, 0);
//        return ret;
//    }
//    void dfs(vector<int>& nums, int pos, int sum)
//    {
//        if (pos == nums.size()) {
//            if (sum == target) ++ret;
//            return;
//        }
//        dfs(nums, pos + 1, sum + nums[pos]);
//        dfs(nums, pos + 1, sum - nums[pos]);
//    }
//};









/**************************************************** 组合总和（LeetCode）**********************************************************/
/*
给你一个无重复元素的整数数组candidates和一个目标整数target，找出candidates中可以使数字和为目标数target的所有不同组合，
并以列表形式返回。你可以按任意顺序返回这些组合
candidates中的同一个数字可以无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的
对于给定的输入，保证和为target的不同组合数少于150个
*/
///*每次考虑每个位置放什么数*/
//#include <iostream>
//#include <vector>
//using namespcae std;
//class Solution
//{
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    int aim = 0;
//
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        aim = target;
//        dfs(candidates, 0, 0);
//        return ret;
//    }
//    void dfs(vector<int>& candidates, int pos, int sum)
//    {
//        if (sum >= aim || pos == candidates.size()) {
//            if (sum == aim) ret.push_back(path);
//            return;
//        }
//        for (int i = pos; i < candidates.size(); ++i) {
//            path.push_back(candidates[i]);
//            dfs(candidates, i, sum + candidates[i]);
//            path.pop_back();
//        }
//    }
//};
///*每次考虑每个数使用了几次*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution
//{
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    int aim = 0;
//
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        aim = target;
//        dfs(candidates, 0, 0);
//        return ret;
//    }
//    void dfs(vector<int>& candidates, int pos, int sum)
//    {
//        if (sum >= aim || pos == candidates.size()) {
//            if (sum == aim) ret.push_back(path);
//            return;
//        }
//        for (int i = 0; i * candidates[pos] + sum <= aim; ++i) {
//            if (i) path.push_back(candidates[pos]);
//            dfs(candidates, pos + 1, sum + i * candidates[pos]);
//        }
//        for (int k = 1; k * candidates[pos] + sum <= aim; ++k) path.pop_back();
//    }
//};











/**************************************************** 字母大小写全排列（LeetCode）***************************************************/
/*
给定一个字符串s，通过将字符串s中的每个字母转变大小写，我们可以获得一个新的字符串
返回 所有可能得到的字符串集合 。以 任意顺序 返回输出
*/
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution
//{
//public:
//    vector<string> ret;
//    string path;
//
//    vector<string> letterCasePermutation(string s)
//    {
//        dfs(s, 0);
//        return ret;
//    }
//    void dfs(string& str, int pos)
//    {
//        if (pos == str.size()) {
//            ret.push_back(path);
//            return;
//        }
//        //不改变
//        path.push_back(str[pos]);
//        dfs(str, pos + 1);
//        path.pop_back();
//        //改变
//        if (isalpha(str[pos]))
//        {
//            if (str[pos] <= 'Z' && str[pos] >= 'A') path.push_back(tolower(str[pos]));
//            else path.push_back(toupper(str[pos]));
//            dfs(str, pos + 1);
//            path.pop_back();
//        }
//    }
//};










/********************************************************** 优美的排列（LeetCode）***************************************************/
/*
假设有从1到n的n个整数。用这些整数构造一个数组perm（下标从1开始），只要满足下述条件之一，该数组就是一个优美的排列：
perm[i]能够被i整除
i能够被perm[i]整除
给你一个整数n，返回可以构造的优美排列的数量
*/
//#include <iostream>
//using namespace std;
//class Solution {
//public:
//    int ret = 0;
//    int nums = 0;
//    bool check[16];
//
//    int countArrangement(int n) {
//        nums = n;
//        dfs(1);
//        return ret;
//    }
//    void dfs(int pos)
//    {
//        if (pos == nums + 1) {
//            ++ret;
//            return;
//        }
//        for (int i = 1; i <= nums; ++i) {
//            if (check[i] == false && (pos % i == 0 || i % pos == 0)) {
//                check[i] = true;
//                dfs(pos + 1);
//                check[i] = false;
//            }
//        }
//    }
//};










/**************************************************** N 皇后（LeetCode）************************************************/
/*
按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子
n皇后问题研究的是如何将n个皇后放置在n×n的棋盘上，并且使皇后彼此之间不能相互攻击
给你一个整数n，返回所有不同的n皇后问题的解决方案
每一种解法包含一个不同的n皇后问题的棋子放置方案，该方案中'Q'和'.'分别代表了皇后和空位
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    vector<vector<string>> ret;
//    vector<string> path;
//    bool checkCol[9], checkDig1[18], checkDig2[18];
//    int num = 0;
//    /*
//    checkCol记录每一列是否有位置被使用
//
//    checkDig1记录每条主对角线是否被使用
//    y = x + b 即 y - x = b, 处在通过主对角线的点的横坐标 - 纵坐标 = 固定值
//    全部+n, 避免越界(出现负数)
//
//    checkDig2记录每条副对角线是否被使用
//    y = -x + b 即 y - x = b, 处在通过副对角线的点的横坐标 + 纵坐标 = 固定值
//    */
//    vector<vector<string>> solveNQueens(int n)
//    {
//        num = n;
//        path = vector<string>(n, string(n, '.'));
//        dfs(0);
//        return ret;
//    }
//    void dfs(int row)
//    {
//        if (row == num) {
//            ret.push_back(path);
//            return;
//        }
//        for (int col = 0; col < num; ++col)
//        {
//            if (!checkCol[col] && !checkDig1[col - row + num] && !checkDig2[col + row])
//            {
//                path[row][col] = 'Q';
//                checkCol[col] = checkDig1[col - row + num] = checkDig2[col + row] = true;
//                dfs(row + 1);
//                checkCol[col] = checkDig1[col - row + num] = checkDig2[col + row] = false;
//                path[row][col] = '.';
//            }
//        }
//    }
//};











/************************************************* 解数独（LeetCode）************************************************/
/*
编写一个程序，通过填充空格来解决数独问题
数独的解法需 遵循如下规则：
数字 1-9 在每一行只能出现一次
数字 1-9 在每一列只能出现一次
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    bool checkRow[9][9];//数字i - 1在j行是否出现过 
//    bool checkCol[9][9];//数字i - 1在j列是否出现过
//    bool checkArea[3][3][9];//i行j列的区域是否出现过数字k - 1
//
//    void solveSudoku(vector<vector<char>>& board)
//    {
//        for (int i = 0; i < 9; ++i) {
//            for (int j = 0; j < 9; ++j) {
//                if (board[i][j] != '.')
//                {
//                    int num = board[i][j] - '0';
//                    checkRow[num - 1][i] = checkCol[num - 1][j] = checkArea[i / 3][j / 3][num - 1] = true;
//                }
//            }
//        }
//        dfs(board);
//    }
//    bool dfs(vector<vector<char>>& board)
//    {
//        for (int row = 0; row < 9; ++row)
//        {
//            for (int col = 0; col < 9; ++col)
//            {
//                if (board[row][col] == '.') //填数
//                {
//                    for (int num = 1; num <= 9; ++num)//枚举每个可能填的数
//                    {
//                        if (!checkRow[num - 1][row] && !checkCol[num - 1][col] && !checkArea[row / 3][col / 3][num - 1])//满足要求
//                        {
//                            checkRow[num - 1][row] = checkCol[num - 1][col] = checkArea[row / 3][col / 3][num - 1] = true;
//                            board[row][col] = num + '0';
//                            if (dfs(board))  return true;
//                            board[row][col] = '.';
//                            checkRow[num - 1][row] = checkCol[num - 1][col] = checkArea[row / 3][col / 3][num - 1] = false;
//                        }
//                    }
//                    return false;//所有数都不满足要求,之前填的值存在问题
//                }
//            }
//        }
//        return true;
//    }
//};











/************************************************ 单词搜索（LeetCode）***********************************************/
/*
给定一个mxn二维字符网格board和一个字符串单词 word
如果word存在于网格中，返回true；否则，返回false
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格
同一个单元格内的字母不允许被重复使用
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    bool pos[6][6];//i行j列的值是否被选中
//    int row = 0, col = 0;
//    string word;
//
//    bool exist(vector<vector<char>>& board, string _word)
//    {
//        row = board.size(), col = board[0].size();
//        word = _word;
//        for (int i = 0; i < row; ++i)
//        {
//            for (int j = 0; j < col; ++j)
//            {
//                if (board[i][j] == word[0])
//                {
//                    pos[i][j] = true;
//                    if (dfs(board, i, j, 1)) return true;
//                    pos[i][j] = false;
//                }
//            }
//        }
//        return false;
//    }
//    int dx[4] = { 0, 0, -1, 1 };
//    int dy[4] = { 1, -1, 0, 0 };
//    bool dfs(vector<vector<char>>& board, int i, int j, int k)//i、j表示矩阵的位置,k表示在字符串中的位置
//    {
//        if (k == word.size()) return true;
//
//        for (int p = 0; p < 4; ++p) //遍历四个位置
//        {
//            int x = i + dx[p], y = j + dy[p];
//            if (x >= 0 && y >= 0 && x < row && y < col && !pos[x][y] && board[x][y] == word[k])//合法
//            {
//                pos[x][y] = true;
//                if (dfs(board, x, y, k + 1)) return true;
//                pos[x][y] = false;
//            }
//        }
//        return false;
//    }
//};