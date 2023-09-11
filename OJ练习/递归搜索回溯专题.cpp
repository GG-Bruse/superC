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