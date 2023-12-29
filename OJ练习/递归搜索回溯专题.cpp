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










/******************************************************* ��������֦��LeetCode��******************************************************/
/*
����������ĸ����root����������ÿ������ֵҪô��0��Ҫô��1
�����Ƴ������в����� 1 ��������ԭ������
�ڵ�node������Ϊnode�����������node�ĺ��
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











/***************************************************** ��֤������������LeetCode��****************************************************/
/*
����һ���������ĸ��ڵ�root ���ж����Ƿ���һ����Ч�Ķ���������
��Ч �����������������£�
�ڵ��������ֻ���� С�� ��ǰ�ڵ����
�ڵ��������ֻ���� ���� ��ǰ�ڵ����
�������������������������Ҳ�Ƕ���������
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
//    long prev = LONG_MIN;//��¼ǰһ��ֵ,�ڶ�����������,��������������,ǰһ�����رȺ�һ����С
//    bool isValidBST(TreeNode* root)
//    {
//        if (root == nullptr) return true;
//
//        bool left = isValidBST(root->left);
//        if (!left) return false;//��֦
//
//        bool current = false;
//        if (root->val > prev) current = true;
//        if (!current) return false;//��֦
//        prev = root->val;
//
//        bool right = isValidBST(root->right);
//
//        return left && right && current;
//    }
//};










/************************************************** �����������е�KС��Ԫ�أ�LeetCode��*********************************************/
/*
����һ�������������ĸ��ڵ�root����һ������k���������һ���㷨�������е�k����СԪ�أ���1��ʼ������
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











/******************************************************** ������������·����LeetCode��***********************************************************/
/*
����һ���������ĸ��ڵ� root ��������˳�� ���������дӸ��ڵ㵽Ҷ�ӽڵ��·��
Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ�
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
//    void dfs(TreeNode* root, string str)//���������ǹؼ�
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









/********************************************************** ȫ���У�LeetCode��*******************************************************/
/*
����һ�������ظ����ֵ�����nums �����������п��ܵ�ȫ���� ������԰�����˳�� ���ش�
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










/******************************************************* �Ӽ���LeetCode��************************************************************/
/*
����һ����������nums �������е�Ԫ�ػ�����ͬ �����ظ��������п��ܵ��Ӽ����ݼ���
�⼯���ܰ����ظ����Ӽ�������԰�����˳�򷵻ؽ⼯
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











/************************************************ �ҳ������Ӽ�������ܺ�����ͣ�LeetCode��*******************************************/
/*
һ�����������ܺͶ���Ϊ����������Ԫ�ذ�λXOR�Ľ�����������Ϊ�գ�������ܺ�Ϊ0
���磬����[2,5,6]������ܺ�Ϊ2 XOR 5 XOR 6 = 1
����һ������nums���������nums��ÿ���Ӽ�������ܺͣ����㲢������Щֵ���֮��

ע�⣺�ڱ����У�Ԫ����ͬ�Ĳ�ͬ�Ӽ�Ӧ��μ���
����a������b��һ���Ӽ���ǰ�������ǣ���bɾ��������Ҳ���ܲ�ɾ����Ԫ���ܹ��õ�a
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










/******************************************************* ȫ���� II��LeetCode��*******************************************************/
/*
����һ���ɰ����ظ����ֵ�����nums��������˳�򷵻����в��ظ���ȫ����
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    bool check[9];//��־nums�и��±��Ƿ�ʹ�ù�
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
//            if (check[i] == false && (i == 0 || nums[i - 1] != nums[i] || check[i - 1] == true)) //��֦
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









/**************************************************** �绰�������ĸ��ϣ�LeetCode��*********************************************/
/*
����һ������������2-9���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰�����˳�򷵻�
�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע��1����Ӧ�κ���ĸ
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









/******************************************************** �������ɣ�LeetCode��****************************************************/
/*
����n�����������ŵĶ������������һ�������������ܹ��������п��ܵĲ�����Ч���������
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
//    ���������� = ���������� = ���Ŷ���
//    ��ͷ��ʼ������һ���Ӵ�, �����ŵ����� >= �����ŵ�����
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










/****************************************************** ��ϣ�LeetCode��*********************************************************/
/*
������������n��k�����ط�Χ[1, n]�����п��ܵ�k���������
����԰� �κ�˳�� ���ش�
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










/******************************************************** Ŀ��ͣ�LeetCode��*********************************************************/
/*
����һ���Ǹ���������nums��һ������target
�������е�ÿ������ǰ���'+'��'-'��Ȼ�������������������Թ���һ�����ʽ��
���磬nums = [2, 1] ��������2֮ǰ���'+'����1֮ǰ���'-'��Ȼ���������õ����ʽ"+2-1"
���ؿ���ͨ��������������ġ�����������target�Ĳ�ͬ���ʽ����Ŀ
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









/**************************************************** ����ܺͣ�LeetCode��**********************************************************/
/*
����һ�����ظ�Ԫ�ص���������candidates��һ��Ŀ������target���ҳ�candidates�п���ʹ���ֺ�ΪĿ����target�����в�ͬ��ϣ�
�����б���ʽ���ء�����԰�����˳�򷵻���Щ���
candidates�е�ͬһ�����ֿ����������ظ���ѡȡ ���������һ�����ֵı�ѡ������ͬ������������ǲ�ͬ��
���ڸ��������룬��֤��Ϊtarget�Ĳ�ͬ���������150��
*/
///*ÿ�ο���ÿ��λ�÷�ʲô��*/
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
///*ÿ�ο���ÿ����ʹ���˼���*/
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











/**************************************************** ��ĸ��Сдȫ���У�LeetCode��***************************************************/
/*
����һ���ַ���s��ͨ�����ַ���s�е�ÿ����ĸת���Сд�����ǿ��Ի��һ���µ��ַ���
���� ���п��ܵõ����ַ������� ���� ����˳�� �������
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
//        //���ı�
//        path.push_back(str[pos]);
//        dfs(str, pos + 1);
//        path.pop_back();
//        //�ı�
//        if (isalpha(str[pos]))
//        {
//            if (str[pos] <= 'Z' && str[pos] >= 'A') path.push_back(tolower(str[pos]));
//            else path.push_back(toupper(str[pos]));
//            dfs(str, pos + 1);
//            path.pop_back();
//        }
//    }
//};










/********************************************************** ���������У�LeetCode��***************************************************/
/*
�����д�1��n��n������������Щ��������һ������perm���±��1��ʼ����ֻҪ������������֮һ�����������һ�����������У�
perm[i]�ܹ���i����
i�ܹ���perm[i]����
����һ������n�����ؿ��Թ�����������е�����
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










/**************************************************** N �ʺ�LeetCode��************************************************/
/*
���չ�������Ĺ��򣬻ʺ���Թ�����֮����ͬһ�л�ͬһ�л�ͬһб���ϵ�����
n�ʺ������о�������ν�n���ʺ������n��n�������ϣ�����ʹ�ʺ�˴�֮�䲻���໥����
����һ������n���������в�ͬ��n�ʺ�����Ľ������
ÿһ�ֽⷨ����һ����ͬ��n�ʺ���������ӷ��÷������÷�����'Q'��'.'�ֱ�����˻ʺ�Ϳ�λ
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
//    checkCol��¼ÿһ���Ƿ���λ�ñ�ʹ��
//
//    checkDig1��¼ÿ�����Խ����Ƿ�ʹ��
//    y = x + b �� y - x = b, ����ͨ�����Խ��ߵĵ�ĺ����� - ������ = �̶�ֵ
//    ȫ��+n, ����Խ��(���ָ���)
//
//    checkDig2��¼ÿ�����Խ����Ƿ�ʹ��
//    y = -x + b �� y - x = b, ����ͨ�����Խ��ߵĵ�ĺ����� + ������ = �̶�ֵ
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











/************************************************* ��������LeetCode��************************************************/
/*
��дһ������ͨ�����ո��������������
�����Ľⷨ�� ��ѭ���¹���
���� 1-9 ��ÿһ��ֻ�ܳ���һ��
���� 1-9 ��ÿһ��ֻ�ܳ���һ��
���� 1-9 ��ÿһ���Դ�ʵ�߷ָ��� 3x3 ����ֻ�ܳ���һ�Ρ�����ο�ʾ��ͼ��
�������ֿո��������������֣��հ׸��� '.' ��ʾ
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    bool checkRow[9][9];//����i - 1��j���Ƿ���ֹ� 
//    bool checkCol[9][9];//����i - 1��j���Ƿ���ֹ�
//    bool checkArea[3][3][9];//i��j�е������Ƿ���ֹ�����k - 1
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
//                if (board[row][col] == '.') //����
//                {
//                    for (int num = 1; num <= 9; ++num)//ö��ÿ�����������
//                    {
//                        if (!checkRow[num - 1][row] && !checkCol[num - 1][col] && !checkArea[row / 3][col / 3][num - 1])//����Ҫ��
//                        {
//                            checkRow[num - 1][row] = checkCol[num - 1][col] = checkArea[row / 3][col / 3][num - 1] = true;
//                            board[row][col] = num + '0';
//                            if (dfs(board))  return true;
//                            board[row][col] = '.';
//                            checkRow[num - 1][row] = checkCol[num - 1][col] = checkArea[row / 3][col / 3][num - 1] = false;
//                        }
//                    }
//                    return false;//��������������Ҫ��,֮ǰ���ֵ��������
//                }
//            }
//        }
//        return true;
//    }
//};











/************************************************ ����������LeetCode��***********************************************/
/*
����һ��mxn��ά�ַ�����board��һ���ַ������� word
���word�����������У�����true�����򣬷���false
���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��
ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ��
*/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    bool pos[6][6];//i��j�е�ֵ�Ƿ�ѡ��
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
//    bool dfs(vector<vector<char>>& board, int i, int j, int k)//i��j��ʾ�����λ��,k��ʾ���ַ����е�λ��
//    {
//        if (k == word.size()) return true;
//
//        for (int p = 0; p < 4; ++p) //�����ĸ�λ��
//        {
//            int x = i + dx[p], y = j + dy[p];
//            if (x >= 0 && y >= 0 && x < row && y < col && !pos[x][y] && board[x][y] == word[k])//�Ϸ�
//            {
//                pos[x][y] = true;
//                if (dfs(board, x, y, k + 1)) return true;
//                pos[x][y] = false;
//            }
//        }
//        return false;
//    }
//};











/************************************************* �ƽ�󹤣�LeetCode��**********************************************/
/*
��Ҫ����һ����󣬵��ʿ���ѧ���Ѿ�̽������������е���Դ�ֲ������ô�СΪ m * n ������ grid �����˱�ע
ÿ����Ԫ���е������ͱ�ʾ��һ��Ԫ���еĻƽ�����������õ�Ԫ���ǿյģ���ô���� 0

Ϊ��ʹ������󻯣�����Ҫ�����¹��������ɻƽ�

ÿ���󹤽���һ����Ԫ���ͻ��ռ��õ�Ԫ���е����лƽ�
��ÿ�ο��Դӵ�ǰλ�������������ĸ������ߡ�
ÿ����Ԫ��ֻ�ܱ����ɣ����룩һ�Ρ�
���ÿ��ɣ����룩�ƽ���ĿΪ 0 �ĵ�Ԫ��
�󹤿��Դ������� ����һ�� �лƽ�ĵ�Ԫ�����������ֹͣ
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    bool pos[15][15] = {false};//i��j�����λ���Ƿ񱻿��ɹ�
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












/************************************************** ��ͬ·�� III��LeetCode��*****************************************/
/*
�ڶ�ά���� grid �ϣ��� 4 �����͵ķ���
1 ��ʾ��ʼ������ֻ��һ����ʼ����
2 ��ʾ����������ֻ��һ����������
0 ��ʾ���ǿ����߹��Ŀշ���
-1 ��ʾ�����޷���Խ���ϰ�
�������ĸ������ϡ��¡����ң�������ʱ������ʼ���񵽽�������Ĳ�ͬ·������Ŀ
ÿһ�����ϰ�����Ҫͨ��һ�Σ�����һ��·���в����ظ�ͨ��ͬһ������
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    bool pos[20][20] = { false };//��λ���Ƿ��߹�
//    int row = 0, col = 0;
//    int ret = 0;
//    int uniquePathsIII(vector<vector<int>>& grid)
//    {
//        row = grid.size(), col = grid[0].size();
//        int x = 0, y = 0;
//        //��ʼ��
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










/**************************************************** ͼ����Ⱦ��LeetCode��**********************************************/
/*
��һ���� m x n �Ķ�ά���������ʾ��ͼ�� image ������image[i][j]��ʾ��ͼ��������ֵ��С
��Ҳ��������������sr ,sc ��newColor����Ӧ�ô�����image[sr][sc]��ʼ��ͼ����� ��ɫ���
Ϊ�������ɫ���� ���ӳ�ʼ���ؿ�ʼ����¼��ʼ��������������ĸ�����������ֵ���ʼ������ͬ���������ص㣬
�����ټ�¼���ĸ������Ϸ������������ص������Ƕ�Ӧ �ĸ������� ����ֵ���ʼ������ͬ���������ص㣬������
�ظ��ù��̡��������м�¼�����ص����ɫֵ��ΪnewColor
��󷵻� ������ɫ��Ⱦ���ͼ��
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











/************************************************* ����������LeetCode��*************************************************/
/*
����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е��������
�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γ�
���⣬����Լ��������������߾���ˮ��Χ
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









/********************************************* �������������LeetCode��********************************************/
/*
����һ����СΪm x n�Ķ����ƾ���grid
���� ����һЩ���ڵ� 1 (��������) ���ɵ���ϣ�����ġ����ڡ�Ҫ������ 1 ������ ˮƽ������ֱ���ĸ������� ����
����Լ��� grid ���ĸ���Ե���� 0������ˮ����Χ��
���������ǵ���ֵΪ 1 �ĵ�Ԫ�����Ŀ
���㲢����grid �����ĵ�����������û�е��죬�򷵻����Ϊ
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









/********************************************** ��Χ�Ƶ�����LeetCode��*********************************************/
/*
����һ�� m x n �ľ��� board ���������ַ� 'X' �� 'O' ���ҵ����б� 'X' Χ�Ƶ�����
������Щ���������е� 'O' �� 'X' ���
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
//        //�����ڱ߽��ϵ�O���ڵ���ͨ�鶼�޸�Ϊ@
//        for (int i = 0; i < row; ++i) {
//            if (board[i][0] == 'O') dfs(board, i, 0);
//            if (board[i][col - 1] == 'O') dfs(board, i, col - 1);
//        }
//        for (int j = 0; j < col; ++j) {
//            if (board[0][j] == 'O') dfs(board, 0, j);
//            if (board[row - 1][j] == 'O') dfs(board, row - 1, j);
//        }
//        //������O��ΪX, ����@��ΪO
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










/****************************************** ̫ƽ�������ˮ�����⣨LeetCode��*****************************************/
/*
��һ�� m �� n �ľ��ε��죬�� ̫ƽ�� �� ������ ���ڡ� ��̫ƽ�� ���ڴ�½����߽���ϱ߽磬
�� �������� ���ڴ�½���ұ߽���±߽�
��������ָ��һ�������ɷ��ε�Ԫ����ɵ����񡣸���һ�� m x n ���������� heights ��
heights[r][c] ��ʾ���� (r, c) �ϵ�Ԫ����ں�ƽ��ĸ߶�
������ˮ�϶࣬������ڵ�Ԫ��ĸ߶� С�ڻ���� ��ǰ��Ԫ��ĸ߶ȣ���ˮ����ֱ���򱱡��ϡ��������������ڵ�Ԫ��
ˮ���ԴӺ��󸽽����κε�Ԫ�����뺣��
������������result��2D�б� ������result[i]=[ri, ci]��ʾ��ˮ�ӵ�Ԫ��(ri, ci)�����ȿ�����̫ƽ��Ҳ�����������
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
//        //������п�������̫ƽ��ĵ�λ��
//        for (int i = 0; i < row; ++i) dfs(heights, i, 0, posPac);
//        for (int j = 0; j < col; ++j) dfs(heights, 0, j, posPac);
//        //������п������������ĵ�λ��
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










/*********************************************** ɨ����Ϸ��LeetCode��***********************************************/
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











/****************************************** �����˵��˶���Χ��LeetCode��*********************************************/
/*
������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ���
��ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ���
���磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18���������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19
���ʸû������ܹ�������ٸ����ӣ�
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
쳲������� ��ͨ���� F(n) ��ʾ���γɵ����г�Ϊ 쳲��������� ���������� 0 �� 1 ��ʼ�������ÿһ�����ֶ���ǰ���������ֵĺ͡�Ҳ���ǣ�

F(0) = 0��F(1) = 1
F(n) = F(n - 1) + F(n - 2)������ n > 1
���� n ������� F(n)
*/
//#include <iostream>
//#include <cstdlib>
//using namespace std;
//class Solution
//{
//public:
//    int memory[31];//����¼
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











/************************************************ ��ͬ·����LeetCode��**************************************************/
/*
һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ��
������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish�� ��
���ܹ��ж�������ͬ��·����
*/
//���仯����
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










/********************************************* ����������У�LeetCode��***********************************************/
/*
����һ���������� nums ���ҵ�������ϸ���������еĳ���
������ ���������������������У�ɾ������ɾ���������е�Ԫ�ض����ı�����Ԫ�ص�˳��
���磬[3,6,2,7] ������ [0,3,1,6,2,2,7] ��������
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










/************************************************ �����ִ�С II��LeetCode��*********************************************/
/*
����������һ��������Ϸ����Ϸ�������£�

�Ҵ� 1 �� n ֮��ѡ��һ������
��������ѡ���ĸ�����
�����µ���ȷ�����֣��ͻ�Ӯ����Ϸ
�����´��ˣ���ô�һ�����㣬��ѡ�����ֱ���ĸ�����߸�С ����������Ҫ��������
ÿ�����������x���Ҳ´��˵�ʱ������Ҫ֧�����Ϊ x ���ֽ�����㻨����Ǯ���ͻ������Ϸ
����һ���ض�������n �������ܹ�ȷ�����ʤ����С�ֽ�����������ѡ���Ǹ�����
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










/****************************************** �����е������·����LeetCode��********************************************/
/*
����һ��m x n��������matrix���ҳ����������·���ĳ���
����ÿ����Ԫ����������ϣ��£������ĸ������ƶ��� �㲻���ڶԽ��߷������ƶ����ƶ����߽��⣨���������ƣ�
*/
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    /*��Ϊ��Ѱ�ҵ�������, ���Բ������ظ���*/
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










/********************************************** �����滻��LeetCode��*******************************************/
/*
����һ�������� n ������������²�����
��� n ��ż�������� n/2 �滻n
��� n ��������������� n+1 �� n-1 �滻n
���� n ��Ϊ 1 �������С�滻����
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











/****************************************** ��ҽ��� III��LeetCode��******************************************/
/*
С͵�ַ�����һ���µĿ����Եĵ������������ֻ��һ����ڣ����ǳ�֮Ϊroot
���� root ֮�⣬ÿ����������ֻ��һ��������������֮������һ�����֮�󣬴�����С͵��ʶ��������ط������з��ݵ�����������һ�ö��������� ��� ����ֱ�������ķ�����ͬһ�����ϱ���� �����ݽ��Զ�����
������������ root ������ �ڲ���������������� ��С͵�ܹ���ȡ����߽��
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
//    //f(o) ��ʾѡ�� o �ڵ�������, o �ڵ�������ϱ�ѡ��Ľڵ�����Ȩֵ��
//    //g(o) ��ʾ��ѡ�� o �ڵ�������, o �ڵ�������ϱ�ѡ��Ľڵ�����Ȩֵ��
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










/************************************ ��ͬ�Ķ��������� II��LeetCode��*****************************************/
/*
����һ������ n ���������ɲ����������� n ���ڵ�����ҽڵ�ֵ��1��n������ͬ�Ĳ�ͬ����������
���԰� ����˳�� ���ش�
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
//        //ö�ٿ��и����
//        for (int i = start; i <= end; ++i)
//        {
//            //����������
//            vector<TreeNode*> left = generateTrees(start, i - 1);
//            //����������
//            vector<TreeNode*> right = generateTrees(i + 1, end);
//            //�������
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









/*************************************** �������е����·���ͣ�LeetCode��**************************************/
/*
�������е�·��������Ϊһ���ڵ����У�������ÿ�����ڽڵ�֮�䶼����һ���ߡ�ͬһ���ڵ���һ��·���������������һ��
��·�� ���ٰ���һ�� �ڵ㣬�Ҳ�һ���������ڵ�
·���� ��·���и��ڵ�ֵ���ܺ�
����һ���������ĸ��ڵ� root �������� ���·����
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
//        int leftMaxGain = max(maxGain(node->left), 0);//������(��·)�����ֵ
//        int rightMaxGain = max(maxGain(node->right), 0);//������(��·)�����ֵ
//        //��Ϊ���
//        int currentMaxGain = node->val + leftMaxGain + rightMaxGain;
//        ret = max(currentMaxGain, ret);
//        return node->val + max(leftMaxGain, rightMaxGain);//��ʱ����Ϊһ·
//    }
//    int maxPathSum(TreeNode* root)
//    {
//        if (root == nullptr) return 0;
//        maxGain(root);
//        return ret;
//    }
//};









/******************************************* �ָ���Ĵ���LeetCode��********************************************/
/*
����һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����� ���Ĵ� ������ s ���п��ܵķָ��
���Ĵ� �����Ŷ��ͷ��Ŷ���һ�����ַ���
*/
//����+��̬�滮Ԥ����
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<vector<string>> ret;
//    vector<string> path;
//    //dp[i,j] : s[i, j]�Ƿ�Ϊ���Ĵ�
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









/******************************************* ������LeetCode��*********************************************/
/*
�� n �����򣬱��Ϊ0 �� n - 1��ÿ�������϶�����һ�����֣���Щ���ִ������� nums ��
����Ҫ����������е����򡣴��Ƶ� i ����������Ի�� nums[i - 1] * nums[i] * nums[i + 1] öӲ��
����� i - 1 �� i + 1 ����� i ���ڵ�������������
��� i - 1�� i + 1 ����������ı߽磬��ô�͵�����һ������Ϊ 1 ������
�����ܻ��Ӳ�ҵ��������
*/
//���仯����
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