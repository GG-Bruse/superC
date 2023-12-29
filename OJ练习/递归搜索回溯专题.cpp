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











/************************************************* 黄金矿工（LeetCode）**********************************************/
/*
你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 进行了标注
每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0

为了使收益最大化，矿工需要按以下规则来开采黄金：

每当矿工进入一个单元，就会收集该单元格中的所有黄金。
矿工每次可以从当前位置向上下左右四个方向走。
每个单元格只能被开采（进入）一次。
不得开采（进入）黄金数目为 0 的单元格。
矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    bool pos[15][15] = {false};//i行j列这个位置是否被开采过
//    int row = 0, col = 0;
//    int ret = 0, path = 0;
//    int getMaximumGold(vector<vector<int>>& grid)
//    {
//        row = grid.size(), col = grid[0].size();
//        for (int i = 0; i < row; ++i)
//        {
//            for (int j = 0; j < col; ++j)
//            {
//                if (grid[i][j] != 0)
//                {
//                    pos[i][j] = true;
//                    path = grid[i][j];
//                    dfs(grid, i, j);
//                    path = 0;
//                    pos[i][j] = false;
//                }
//            }
//        }
//        return ret;
//    }
//    int dx[4] = { 0, 0, 1, -1 };
//    int dy[4] = { 1, -1, 0, 0 };
//    void dfs(vector<vector<int>>& grid, int i, int j)
//    {
//        for (int k = 0; k < 4; ++k)
//        {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && y >= 0 && x < row && y < col && !pos[x][y] && grid[x][y] != 0)
//            {
//                pos[x][y] = true;
//                path += grid[x][y];
//                dfs(grid, x, y);
//                path -= grid[x][y];
//                pos[x][y] = false;
//            }
//        }
//        ret = max(ret, path);
//    }
//};












/************************************************** 不同路径 III（LeetCode）*****************************************/
/*
在二维网格 grid 上，有 4 种类型的方格：
1 表示起始方格。且只有一个起始方格
2 表示结束方格，且只有一个结束方格
0 表示我们可以走过的空方格
-1 表示我们无法跨越的障碍
返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目
每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    bool pos[20][20] = { false };//该位置是否走过
//    int row = 0, col = 0;
//    int ret = 0;
//    int uniquePathsIII(vector<vector<int>>& grid)
//    {
//        row = grid.size(), col = grid[0].size();
//        int x = 0, y = 0;
//        //初始化
//        for (int i = 0; i < row; ++i)
//            for (int j = 0; j < col; ++j) {
//                if (grid[i][j] == -1) pos[i][j] = true;
//                if (grid[i][j] == 1) x = i, y = j, pos[i][j] = true;
//            }
//        dfs(grid, x, y);
//        return ret;
//    }
//    int dx[4] = { 0, 0, 1, -1 };
//    int dy[4] = { 1, -1, 0, 0 };
//    void dfs(vector<vector<int>>& grid, int i, int j)
//    {
//        if (grid[i][j] == 2)
//        {
//            int flag = true;
//            for (int m = 0; m < row; ++m)
//                for (int n = 0; n < col; ++n)
//                    if (pos[m][n] == false) flag = false;
//            if (flag) ++ret;
//        }
//        for (int k = 0; k < 4; ++k)
//        {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && y >= 0 && x < row && y < col && !pos[x][y] && (grid[x][y] == 0 || grid[x][y] == 2))
//            {
//                pos[x][y] = true;
//                dfs(grid, x, y);
//                pos[x][y] = false;
//            }
//        }
//    }
//};










/**************************************************** 图像渲染（LeetCode）**********************************************/
/*
有一幅以 m x n 的二维整数数组表示的图画 image ，其中image[i][j]表示该图画的像素值大小
你也被给予三个整数sr ,sc 和newColor。你应该从像素image[sr][sc]开始对图像进行 上色填充
为了完成上色工作 ，从初始像素开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，
接着再记录这四个方向上符合条件的像素点与他们对应 四个方向上 像素值与初始坐标相同的相连像素点，……，
重复该过程。将所有有记录的像素点的颜色值改为newColor
最后返回 经过上色渲染后的图像
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int row = 0, col = 0;
//    int prevColor = 0, newColor = 0;
//    int dx[4] = { 1, -1, 0, 0 };
//    int dy[4] = { 0, 0, 1, -1 };
//
//    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
//    {
//        row = image.size(), col = image[0].size();
//        prevColor = image[sr][sc], newColor = color;
//        if (prevColor == newColor) return image;
//
//        dfs(image, sr, sc);
//        return image;
//    }
//    void dfs(vector<vector<int>>& image, int i, int j)
//    {
//        image[i][j] = newColor;
//        for (int k = 0; k < 4; ++k) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && y >= 0 && x < row && y < col && image[x][y] == prevColor) dfs(image, x, y);
//        }
//    }
//};











/************************************************* 岛屿数量（LeetCode）*************************************************/
/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成
此外，你可以假设该网格的四条边均被水包围
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int row = 0, col = 0;
//    int ret = 0;
//    int dx[4] = { 1, -1, 0, 0 };
//    int dy[4] = { 0, 0, 1, -1 };
//
//    int numIslands(vector<vector<char>>& grid)
//    {
//        row = grid.size(), col = grid[0].size();
//        for (int i = 0; i < row; ++i) {
//            for (int j = 0; j < col; ++j) {
//                if (grid[i][j] == '1') dfs(grid, i, j), ++ret;
//            }
//        }
//        return ret;
//    }
//    void dfs(vector<vector<char>>& grid, int i, int j)
//    {
//        grid[i][j] = '2';
//        for (int k = 0; k < 4; ++k) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && y >= 0 && x < row && y < col && grid[x][y] == '1') dfs(grid, x, y);
//        }
//    }
//};









/********************************************* 岛屿的最大面积（LeetCode）********************************************/
/*
给你一个大小为m x n的二进制矩阵grid
岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻
你可以假设 grid 的四个边缘都被 0（代表水）包围着
岛屿的面积是岛上值为 1 的单元格的数目
计算并返回grid 中最大的岛屿面积。如果没有岛屿，则返回面积为
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int maxArea = 0;
//    int path = 0;
//    int row = 0, col = 0;
//    int dx[4] = { 0, 0, 1, -1 };
//    int dy[4] = { 1, -1, 0, 0 };
//
//    int maxAreaOfIsland(vector<vector<int>>& grid)
//    {
//        row = grid.size(), col = grid[0].size();
//        for (int i = 0; i < row; ++i) {
//            for (int j = 0; j < col; ++j) {
//                if (grid[i][j] == 1)
//                {
//                    dfs(grid, i, j);
//                    maxArea = max(maxArea, path);
//                    path = 0;
//                }
//            }
//        }
//        return maxArea;
//    }
//    void dfs(vector<vector<int>>& grid, int i, int j)
//    {
//        grid[i][j] = 2, ++path;
//        for (int k = 0; k < 4; ++k) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && y >= 0 && x < row && y < col && grid[x][y] == 1) dfs(grid, x, y);
//        }
//    }
//};









/********************************************** 被围绕的区域（LeetCode）*********************************************/
/*
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，
并将这些区域里所有的 'O' 用 'X' 填充
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int row = 0, col = 0;
//    int dx[4] = { 0, 0, 1, -1 };
//    int dy[4] = { 1, -1, 0, 0 };
//
//    void solve(vector<vector<char>>& board)
//    {
//        row = board.size(), col = board[0].size();
//        //将与在边界上的O所在的连通块都修改为@
//        for (int i = 0; i < row; ++i) {
//            if (board[i][0] == 'O') dfs(board, i, 0);
//            if (board[i][col - 1] == 'O') dfs(board, i, col - 1);
//        }
//        for (int j = 0; j < col; ++j) {
//            if (board[0][j] == 'O') dfs(board, 0, j);
//            if (board[row - 1][j] == 'O') dfs(board, row - 1, j);
//        }
//        //将所有O改为X, 所有@改为O
//        for (int i = 0; i < row; ++i) {
//            for (int j = 0; j < col; ++j) {
//                if (board[i][j] == 'O') board[i][j] = 'X';
//                if (board[i][j] == '@') board[i][j] = 'O';
//            }
//        }
//    }
//    void dfs(vector<vector<char>>& board, int i, int j)
//    {
//        board[i][j] = '@';
//        for (int k = 0; k < 4; ++k) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && y >= 0 && x < row && y < col && board[x][y] == 'O') dfs(board, x, y);
//        }
//    }
//};










/****************************************** 太平洋大西洋水流问题（LeetCode）*****************************************/
/*
有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，
而 “大西洋” 处于大陆的右边界和下边界
这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ，
heights[r][c] 表示坐标 (r, c) 上单元格高于海平面的高度
岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格
水可以从海洋附近的任何单元格流入海洋
返回网格坐标result的2D列表 ，其中result[i]=[ri, ci]表示雨水从单元格(ri, ci)流动既可流向太平洋也可流向大西洋
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int row = 0, col = 0;
//    int dx[4] = { 0, 0, 1, -1 };
//    int dy[4] = { 1, -1, 0, 0 };
//
//    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
//    {
//        vector<vector<int>> ret;
//        row = heights.size(), col = heights[0].size();
//        vector<vector<bool>> posPac(row, vector<bool>(col));
//        vector<vector<bool>> posAtl(row, vector<bool>(col));
//
//        //标记所有可以流向太平洋的的位置
//        for (int i = 0; i < row; ++i) dfs(heights, i, 0, posPac);
//        for (int j = 0; j < col; ++j) dfs(heights, 0, j, posPac);
//        //标记所有可以流向大西洋的的位置
//        for (int i = 0; i < row; ++i) dfs(heights, i, col - 1, posAtl);
//        for (int j = 0; j < col; ++j) dfs(heights, row - 1, j, posAtl);
//
//        for (int i = 0; i < row; ++i)
//            for (int j = 0; j < col; ++j)
//                if (posPac[i][j] && posAtl[i][j]) ret.push_back({ i, j });
//        return  ret;
//    }
//    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& pos)
//    {
//        pos[i][j] = true;
//        for (int k = 0; k < 4; ++k) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && y >= 0 && x < row && y < col && !pos[x][y] && heights[x][y] >= heights[i][j])
//                dfs(heights, x, y, pos);
//        }
//    }
//};










/*********************************************** 扫雷游戏（LeetCode）***********************************************/
/*
https://leetcode.cn/problems/minesweeper/description/
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int row = 0, col = 0;
//    int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
//    int dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };
//
//    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
//    {
//        row = board.size(), col = board[0].size();
//        int x = click[0], y = click[1];
//        if (board[x][y] == 'M') {
//            board[x][y] = 'X';
//            return board;
//        }
//        dfs(board, x, y);
//        return board;
//    }
//    void dfs(vector<vector<char>>& board, int i, int j)
//    {
//        int count = 0;
//        for (int k = 0; k < 8; ++k) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && y >= 0 && x < row && y < col && board[x][y] == 'M') ++count;
//        }
//        if (count != 0) {
//            board[i][j] = count + '0';
//            return;
//        }
//        else {
//            board[i][j] = 'B';
//            for (int k = 0; k < 8; ++k) {
//                int x = i + dx[k], y = j + dy[k];
//                if (x >= 0 && y >= 0 && x < row && y < col && board[x][y] == 'E') dfs(board, x, y);
//            }
//        }
//    }
//};











/****************************************** 机器人的运动范围（LeetCode）*********************************************/
/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19
请问该机器人能够到达多少个格子？
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int ret = 0;
//    int row = 0, col = 0;
//    int reference = 0;
//    int dx[4] = { 1, -1, 0, 0 };
//    int dy[4] = { 0, 0, 1, -1 };
//
//    int movingCount(int m, int n, int k)
//    {
//        row = m, col = n, reference = k;
//        vector<vector<bool>> pos(m, vector<bool>(n));
//        dfs(pos, 0, 0);
//        return ret;
//    }
//    void dfs(vector<vector<bool>>& pos, int i, int j)
//    {
//        pos[i][j] = true, ++ret;
//        for (int k = 0; k < 4; ++k) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && y >= 0 && x < row && y < col && !pos[x][y] && Handle(x, y)) dfs(pos, x, y);
//        }
//    }
//
//private:
//    bool Handle(int x, int y) {
//        vector<int> ret1 = decompose(x);
//        vector<int> ret2 = decompose(y);
//        int sum = 0;
//        for (auto& it : ret1) sum += it;
//        for (auto& it : ret2) sum += it;
//        return sum <= reference;
//    }
//    vector<int> decompose(int number) {
//        vector<int> ret;
//        while (number) {
//            ret.push_back(number % 10);
//            number /= 10;
//        }
//        return ret;
//    }
//};













/************************************************************************************************************************/
/*
斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给定 n ，请计算 F(n)
*/
//#include <iostream>
//#include <cstdlib>
//using namespace std;
//class Solution
//{
//public:
//    int memory[31];//备忘录
//
//    int fib(int n) {
//        memset(memory, -1, sizeof memory);
//        return dfs(n);
//    }
//    int dfs(int number)
//    {
//        if (memory[number] != -1) return memory[number];
//
//        if (number == 0 || number == 1) {
//            memory[number] = number;
//            return number;
//        }
//        memory[number] = dfs(number - 1) + dfs(number - 2);
//        return memory[number];
//    }
//};











/************************************************ 不同路径（LeetCode）**************************************************/
/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）
问总共有多少条不同的路径？
*/
//记忆化搜索
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        vector<vector<int>> memory(m + 1, vector<int>(n + 1, -1));
//        return dfs(m, n, memory);
//    }
//    int dfs(int i, int j, vector<vector<int>>& memory)
//    {
//        if (memory[i][j] != -1) return memory[i][j];
//
//        if (i == 0 || j == 0) return 0;
//        if (i == 1 && j == 1) {
//            memory[i][j] = 1;
//            return memory[i][j];
//        }
//
//        memory[i][j] = dfs(i - 1, j, memory) + dfs(i, j - 1, memory);
//        return memory[i][j];
//    }
//};










/********************************************* 最长递增子序列（LeetCode）***********************************************/
/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        int size = nums.size();
//        vector<int> memory(size);
//
//        int ret = 0;
//        for (int i = 0; i < nums.size(); ++i)
//            ret = max(ret, dfs(i, nums, memory));
//        return ret;
//    }
//    int dfs(int index, vector<int>& nums, vector<int>& memory)
//    {
//        if (memory[index] != 0) return memory[index];
//
//        int ret = 1;
//        for (int i = index + 1; i < nums.size(); ++i)
//            if (nums[i] > nums[index]) ret = max(ret, dfs(i, nums, memory) + 1);
//        memory[index] = ret;
//        return memory[index];
//    }
//};










/************************************************ 猜数字大小 II（LeetCode）*********************************************/
/*
我们正在玩一个猜数游戏，游戏规则如下：

我从 1 到 n 之间选择一个数字
你来猜我选了哪个数字
如果你猜到正确的数字，就会赢得游戏
如果你猜错了，那么我会告诉你，我选的数字比你的更大或者更小 ，并且你需要继续猜数
每当你猜了数字x并且猜错了的时候，你需要支付金额为 x 的现金。如果你花光了钱，就会输掉游戏
给你一个特定的数字n ，返回能够确保你获胜的最小现金数，不管我选择那个数字
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int getMoneyAmount(int n) {
//        vector<vector<int>> memory(n + 1, vector<int>(n + 1, -1));
//        return dfs(1, n, memory);
//    }
//    int dfs(int start, int end, vector<vector<int>>& memory)
//    {
//        if (start >= end) return 0;
//        if (memory[start][end] != -1) return memory[start][end];
//
//        int ret = INT_MAX;
//        for (int i = start; i <= end; ++i)
//        {
//            int left = dfs(start, i - 1, memory);
//            int right = dfs(i + 1, end, memory);
//            ret = min(ret, i + max(left, right));
//        }
//        memory[start][end] = ret;
//        return ret;
//    }
//};










/****************************************** 矩阵中的最长递增路径（LeetCode）********************************************/
/*
给定一个m x n整数矩阵matrix，找出其中最长递增路径的长度
对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    /*因为是寻找递增序列, 所以不可能重复走*/
//    int row = 0, col = 0;
//    int longestIncreasingPath(vector<vector<int>>& matrix)
//    {
//        row = matrix.size(), col = matrix[0].size();
//        vector<vector<int>> memory(row, vector<int>(col, -1));
//
//        int ret = 1;
//        for (int i = 0; i < row; ++i)
//            for (int j = 0; j < col; ++j)
//                ret = max(ret, dfs(matrix, i, j, memory));
//        return ret;
//    }
//
//    int dx[4] = { 1, -1, 0, 0 };
//    int dy[4] = { 0, 0, 1, -1 };
//    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memory)
//    {
//        if (memory[i][j] != -1) return memory[i][j];
//
//        int ret = 1;
//        for (int k = 0; k < 4; ++k) {
//            int x = i + dx[k], y = j + dy[k];
//            if (x >= 0 && y >= 0 && x < row && y < col && matrix[i][j] < matrix[x][y])
//                ret = max(ret, 1 + dfs(matrix, x, y, memory));
//        }
//        memory[i][j] = ret;
//        return ret;
//    }
//};










/********************************************** 整数替换（LeetCode）*******************************************/
/*
给定一个正整数 n ，你可以做如下操作：
如果 n 是偶数，则用 n/2 替换n
如果 n 是奇数，则可以用 n+1 或 n-1 替换n
返回 n 变为 1 所需的最小替换次数
*/
//#include <iostream>
//#include <unordered_map>
//using namespace std;
// class Solution {
// public:
//     unordered_map<int, int> memory;//number : step
//     int integerReplacement(int n) {
//         return dfs(n);
//     }
//     int dfs(long long number)
//     {
//         if(number == 1) return 0;
//         if(memory.count(number)) return memory[number];
//
//         if(number % 2 == 0) return memory[number] = 1 + dfs(number / 2);
//         else return memory[number] = 1 + min(dfs(number + 1), dfs(number - 1));
//     }
// };











/****************************************** 打家劫舍 III（LeetCode）******************************************/
/*
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为root
除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警
给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额
*/
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//}; 
//class Solution {
//public:
//    //f(o) 表示选择 o 节点的情况下, o 节点的子树上被选择的节点的最大权值和
//    //g(o) 表示不选择 o 节点的情况下, o 节点的子树上被选择的节点的最大权值和
//    unordered_map <TreeNode*, int> f, g;
//    void dfs(TreeNode* node)
//    {
//        if (node == nullptr) return;
//        dfs(node->left);
//        dfs(node->right);
//        f[node] = node->val + g[node->left] + g[node->right];
//        g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
//    }
//    int rob(TreeNode* root)
//    {
//        dfs(root);
//        return max(f[root], g[root]);
//    }
//};










/************************************ 不同的二叉搜索树 II（LeetCode）*****************************************/
/*
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从1到n互不相同的不同二叉搜索树
可以按 任意顺序 返回答案
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//}; 
//class Solution {
//public:
//    vector<TreeNode*> generateTrees(int start, int end)
//    {
//        if (start > end) return { nullptr };
//        vector<TreeNode*> allTrees;
//        //枚举可行根结点
//        for (int i = start; i <= end; ++i)
//        {
//            //左子树集合
//            vector<TreeNode*> left = generateTrees(start, i - 1);
//            //右子树集合
//            vector<TreeNode*> right = generateTrees(i + 1, end);
//            //所有组合
//            for (int j = 0; j < left.size(); ++j)
//            {
//                for (int k = 0; k < right.size(); ++k)
//                {
//                    TreeNode* current = new TreeNode(i);
//                    current->left = left[j];
//                    current->right = right[k];
//                    allTrees.push_back(current);
//                }
//            }
//        }
//        return allTrees;
//    }
//    vector<TreeNode*> generateTrees(int n)
//    {
//        if (n == 0) return {};
//        return generateTrees(1, n);
//    }
//};









/*************************************** 二叉树中的最大路径和（LeetCode）**************************************/
/*
二叉树中的路径被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中至多出现一次
该路径 至少包含一个 节点，且不一定经过根节点
路径和 是路径中各节点值的总和
给你一个二叉树的根节点 root ，返回其 最大路径和
*/
//#include <iostream>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
//class Solution {
//public:
//    int ret = INT_MIN;
//    int maxGain(TreeNode* node)
//    {
//        if (node == nullptr) return 0;
//
//        int leftMaxGain = max(maxGain(node->left), 0);//左子树(左路)最大贡献值
//        int rightMaxGain = max(maxGain(node->right), 0);//右子树(右路)最大贡献值
//        //作为结果
//        int currentMaxGain = node->val + leftMaxGain + rightMaxGain;
//        ret = max(currentMaxGain, ret);
//        return node->val + max(leftMaxGain, rightMaxGain);//此时仅作为一路
//    }
//    int maxPathSum(TreeNode* root)
//    {
//        if (root == nullptr) return 0;
//        maxGain(root);
//        return ret;
//    }
//};









/******************************************* 分割回文串（LeetCode）********************************************/
/*
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案
回文串 是正着读和反着读都一样的字符串
*/
//回溯+动态规划预处理
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<vector<string>> ret;
//    vector<string> path;
//    //dp[i,j] : s[i, j]是否为回文串
//    vector<vector<bool>> dp;
//    int size = 0;
//    void dfs(const string& str, int i, vector<vector<bool>>& dp)
//    {
//        if (i == size) {
//            ret.push_back(path);
//            return;
//        }
//        for (int j = i; j < size; ++j)
//        {
//            if (dp[i][j])
//            {
//                path.push_back(str.substr(i, j - i + 1));
//                dfs(str, j + 1, dp);
//                path.pop_back();
//            }
//        }
//    }
//    vector<vector<string>> partition(string s)
//    {
//        size = s.size();
//        dp = vector<vector<bool>>(size, vector<bool>(size, true));
//
//        for (int i = size - 1; i >= 0; --i) {
//            for (int j = i + 1; j < size; ++j) {
//                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
//            }
//        }
//
//        dfs(s, 0, dp);
//        return ret;
//    }
//};









/******************************************* 戳气球（LeetCode）*********************************************/
/*
有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中
现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币
这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号
如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球
求所能获得硬币的最大数量
*/
//记忆化搜索
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int dfs(vector<vector<int>>& memory, vector<int>& newNums, int left, int right)
//    {
//        if (left >= right - 1) return 0;
//        if (memory[left][right] != -1) return memory[left][right];
//
//        for (int i = left + 1; i < right; ++i)
//        {
//            int tmp = newNums[left] * newNums[i] * newNums[right];
//            tmp += dfs(memory, newNums, left, i) + dfs(memory, newNums, i, right);
//            memory[left][right] = max(memory[left][right], tmp);
//        }
//        return memory[left][right];
//    }
//    int maxCoins(vector<int>& nums)
//    {
//        int size = nums.size();
//        vector<int> newNums(size + 2, 1);
//        for (int i = 1; i <= size; ++i) newNums[i] = nums[i - 1];
//
//        vector<vector<int>> memory(size + 2, vector<int>(size + 2, -1));
//        return dfs(memory, newNums, 0, size + 1);
//    }
//};