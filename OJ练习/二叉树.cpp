#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
/*******************************************************���ݶ����������ַ���****************************************************/
/*
����������ĸ��ڵ� root ���������ǰ������ķ�ʽ����������ת��Ϊһ�������ź�������ɵ��ַ��������ع�������ַ�����
�սڵ�ʹ��һ�Կ����Ŷ� "()" ��ʾ��ת������Ҫʡ�����в�Ӱ���ַ�����ԭʼ������֮���һ��һӳ���ϵ�Ŀ����Ŷ�
*/

/*
                        1
                    2       3
                4
1( tree2str(left) )( tree2str(right) )
1(2( tree2str(left) ))( tree2str(right) )
1(2(4))( tree2str(right) )
1(2(4))(3)
*/


//class Solution1 {//�ݹ�
//public:
//    string tree2str(TreeNode* root)
//    {
//        if (root == nullptr) return "";
//
//        if (root->left == nullptr && root->right == nullptr)
//            return to_string(root->val);
//        if (root->right == nullptr)
//            return to_string(root->val) + "(" + tree2str(root->left) + ")";
//        return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
//    }
//};
//class Solution2 {//����
//public:
//    string tree2str(TreeNode* root)
//    {
//        string ret;
//        stack<TreeNode*> sk;
//        sk.push(root);
//        unordered_set<TreeNode*> set;
//
//        while (!sk.empty())
//        {
//            TreeNode* node = sk.top();
//
//            if (set.count(node)) {
//                if (node != root) ret += ")";
//                sk.pop();
//            }
//            else
//            {
//                set.insert(node);
//                if (node != root) ret += "(";
//                ret += to_string(node->val);
//                if (node->left == nullptr && node->right != nullptr) ret += "()";
//                if (node->right != nullptr) sk.push(node->right);
//                if (node->left != nullptr) sk.push(node->left);
//            }
//        }
//        return ret;
//    }
//};
















/*******************************************************�������Ĳ������********************************************************/
/*
����������ĸ��ڵ� root ��������ڵ�ֵ�� ������� �� �������أ������ҷ������нڵ㣩
*/
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root)
//    {
//        vector<vector<int>> ret;
//        if (root == nullptr) return ret;
//
//        queue<TreeNode*> qe;
//        qe.push(root);
//        while (!qe.empty())
//        {
//            int levelSize = qe.size();//�����ĸ���
//            vector<int> tmp;
//            for (int i = 0; i < levelSize; ++i)
//            {
//                TreeNode* node = qe.front();
//                qe.pop();
//                tmp.push_back(node->val);
//                if (node->left != nullptr) qe.push(node->left);
//                if (node->right != nullptr) qe.push(node->right);
//            }
//            ret.push_back(tmp);
//        }
//        return ret;
//    }
//};














/*****************************************************�������������������******************************************************/
/*
����һ��������, �ҵ�����������ָ���ڵ������������ȡ�
�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T �������ڵ� p��q��
����������ȱ�ʾΪһ���ڵ� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�
*/

//class Solution1 {
//public:
//    bool Find(TreeNode* subTree, TreeNode* node)
//    {
//        if (subTree == nullptr) return false;
//        return subTree == node || Find(subTree->left, node) || Find(subTree->right, node);
//    }
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//    {
//        if (root == nullptr) return nullptr;
//        if (root == p || root == q) return root;
//
//        bool pInLeft, pInRight, qInLeft, qInRight;
//        pInLeft = Find(root->left, p);
//        pInRight = !pInLeft;
//        qInLeft = Find(root->left, q);
//        qInRight = !qInLeft;
//
//        if ((pInLeft && qInRight) || (pInRight && qInLeft)) return root;
//        else if (pInLeft && qInLeft) return lowestCommonAncestor(root->left, p, q);
//        else return lowestCommonAncestor(root->right, p, q);//pInRight && qInRight
//    }
//};













/***************************************************������������˫������ţ�ͣ�************************************************/
/*
����һ�ö��������������ö���������ת����һ�������˫������

1.Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ�򡣵�ת������Ժ����нڵ����ָ����Ҫָ��ǰ����
���нڵ����ָ����Ҫָ����
2.���������еĵ�һ���ڵ��ָ��
3.�������ص�TreeNode��������ָ�룬��ʵ���Կ���һ��˫����������ݽṹ
*/

//class Solution {
//public:
//	TreeNode* head = nullptr;
//	TreeNode* prev = nullptr;
//
//	TreeNode* Convert(TreeNode* pRootOfTree)
//	{
//		if (pRootOfTree == nullptr) return nullptr;
//
//		Convert(pRootOfTree->left);
//		if (prev == nullptr) {
//			head = pRootOfTree;
//			prev = pRootOfTree;
//		}
//		else {
//			prev->right = pRootOfTree;
//			pRootOfTree->left = prev;
//			prev = pRootOfTree;
//		}
//		Convert(pRootOfTree->right);
//		return head;
//	}
//};














/*************************************************��ǰ��������������й��������************************************************/
/*
���������������� preorder �� inorder ������ preorder �Ƕ���������������� 
inorder ��ͬһ����������������빹�����������������ڵ�
*/
//class Solution {
//public:
//    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prevIndex, int inBegin, int inEnd)
//    {
//        if (inBegin > inEnd) return nullptr;
//
//        TreeNode* node = new TreeNode(preorder[prevIndex++]);
//
//        int i = inBegin;
//        for (; i <= inEnd; ++i) {
//            if (inorder[i] == node->val) break;
//        }
//
//        node->left = _buildTree(preorder, inorder, prevIndex, inBegin, i - 1);
//        node->right = _buildTree(preorder, inorder, prevIndex, i + 1, inEnd);
//        return node;
//    }
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
//    {
//        int index = 0;
//        return _buildTree(preorder, inorder, index, 0, inorder.size() - 1);
//    }
//};














/***************************************************�����������������й��������***********************************************/
/*
���������������� inorder �� postorder ������ inorder �Ƕ���������������� 
postorder ��ͬһ�����ĺ�����������㹹�첢������� ������
*/
//class Solution {
//public:
//    TreeNode* _buildTree(vector<int>& postorder, vector<int>& inorder, int& postIndex, int inBegin, int inEnd)
//    {
//        if (inBegin > inEnd) return nullptr;
//
//        TreeNode* node = new TreeNode(postorder[postIndex--]);
//
//        int i = inBegin;
//        for (; i <= inEnd; ++i) {
//            if (inorder[i] == node->val) break;
//        }
//
//        node->right = _buildTree(postorder, inorder, postIndex, i + 1, inEnd);
//        node->left = _buildTree(postorder, inorder, postIndex, inBegin, i - 1);
//        return node;
//    }
//    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
//    {
//        int index = postorder.size() - 1;
//        return _buildTree(postorder, inorder, index, 0, inorder.size() - 1);
//    }
//};









/********************************************* ������������ͼ��LeetCode��**************************************************/
/*
����һ���������� ���ڵ� root�������Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ
*/
//class Solution {
//public:
//    vector<int> rightSideView(TreeNode* root)
//    {
//        if (root == nullptr) return {};
//        vector<int> ret;
//        bfs(ret, root);
//        return ret;
//    }
//    void bfs(vector<int>& ret, TreeNode* node)
//    {
//        queue<TreeNode*> qe;
//        qe.push(node);
//        while (!qe.empty())
//        {
//            vector<int> tmpRow;
//            int size = qe.size();
//            while (size--)
//            {
//                TreeNode* front = qe.front();
//                qe.pop();
//                tmpRow.push_back(front->val);
//                if (front->left) qe.push(front->left);
//                if (front->right) qe.push(front->right);
//            }
//            if (tmpRow.size()) ret.push_back(tmpRow.back());
//        }
//    }
//};










/******************************************** ������չ��Ϊ����LeetCode��*************************************************/
/*
����������ĸ���� root �����㽫��չ��Ϊһ��������
չ����ĵ�����Ӧ��ͬ��ʹ�� TreeNode ������ right ��ָ��ָ����������һ����㣬������ָ��ʼ��Ϊ null
չ����ĵ�����Ӧ��������� ������� ˳����ͬ
*/
//class Solution1 {
//public:
//    void flatten(TreeNode* root)
//    {
//        TreeNode* node = root;
//        while (node != nullptr)
//        {
//            //�ҵ������������ҽ��
//            TreeNode* current = node->left;
//            while (current != nullptr && current->right != nullptr) current = current->right;
//            //�任
//            if (current != nullptr)
//            {
//                current->right = node->right;
//                node->right = node->left;
//                node->left = nullptr;
//            }
//            node = node->right;
//        }
//    }
//};
//class Solution2 {
//public:
//    void flatten(TreeNode* root)
//    {
//        if (root == nullptr) return;
//        stack<TreeNode*> sk;
//        sk.push(root);
//        TreeNode* prev = nullptr;//��¼��һ�����
//        while (!sk.empty())
//        {
//            TreeNode* current = sk.top();
//            sk.pop();
//            if (prev != nullptr)
//            {
//                prev->left = nullptr;
//                prev->right = current;
//            }
//            TreeNode* left = current->left, * right = current->right;
//            if (right != nullptr) sk.push(right);
//            if (left != nullptr) sk.push(left);
//            prev = current;
//        }
//    }
//};










/******************************************* ����������ת��Ϊ������������LeetCode��**************************************/
/*
����һ����������nums������Ԫ���Ѿ����������У����㽫��ת��Ϊһ�ø߶�ƽ�����������
�߶�ƽ���������һ�����㡸ÿ���ڵ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ���Ķ�����
*/
//class Solution {
//public:
//    TreeNode* sortedArrayToBST(vector<int>& nums)
//    {
//        if (nums.size() == 0) return nullptr;
//        return dfs(nums, 0, nums.size() - 1);
//    }
//    TreeNode* dfs(vector<int>& nums, int left, int right)
//    {
//        if (left > right) return nullptr;
//        int mid = right - ((right - left) >> 1);
//        TreeNode* node = new TreeNode(nums[mid]);
//        node->left = dfs(nums, left, mid - 1);
//        node->right = dfs(nums, mid + 1, right);
//        return node;
//    }
//};










/*************************************************** ·���ܺ�III ��LeetCode��********************************************/
/*
����һ���������ĸ��ڵ�root����һ������targetSum ����ö�������ڵ�ֵ֮�͵���targetSum��·������Ŀ
·�� ����Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩
*/
////������ȱ���
//class Solution1 {
//public:
//    int pathSum(TreeNode* root, long long targetSum)
//    {
//        if (root == nullptr) return 0;
//        //�ݹ�,��ÿ�����Ϊ��㶼���м���
//        int ret = rootSum(root, targetSum);
//        ret += pathSum(root->left, targetSum);
//        ret += pathSum(root->right, targetSum);
//        return ret;
//    }
//    //node���Ϊ�������,�����ܺ�Ϊvalue��·����Ŀ
//    int rootSum(TreeNode* node, long long value)
//    {
//        if (node == nullptr) return 0;
//        int ret = 0;
//        if (node->val == value) ++ret;
//        ret += rootSum(node->left, value - (node->val));
//        ret += rootSum(node->right, value - (node->val));
//        return ret;
//    }
//};
////ǰ׺���Ż�
//class Solution2 {
//public:
//    //ǰ׺ : ����㵽��ǰ����·�������нڵ�ĺ� 
//    unordered_map<long long, int> prefix;//��:·������
//    int dfs(TreeNode* root, long long current, int targetSum)
//    {
//        if (root == nullptr) return 0;
//        int ret = 0;
//        current += root->val;// �Ӹ��ڵ㵽��ǰ�ڵ��ǰ׺��Ϊcurrent
//        if (prefix.count(current - targetSum)) {//�Ӹ��ڵ㵽��ǰ����ǰ׺��Ϊcurrent-targetSum�Ľ��
//            ret = prefix[current - targetSum];
//        }
//        //���µݹ�
//        ++prefix[current];
//        ret += dfs(root->left, current, targetSum);
//        ret += dfs(root->right, current, targetSum);
//        --prefix[current];
//        return ret;
//    }
//    int pathSum(TreeNode* root, int targetSum) {
//        prefix[0] = 1;
//        return dfs(root, 0, targetSum);
//    }
//};











/*******************************************************��������ǰ�����(�ǵݹ�)*************************************************/
class Solution1{
public:
    vector<int> preorderTraversal(TreeNode * root)
    {
        vector<int> ret;
        if (root == nullptr) return ret;

        stack<TreeNode*> sk;
        sk.push(root);
        while (!sk.empty())
        {
            TreeNode* node = sk.top();
            sk.pop();
            ret.push_back(node->val);
            if (node->right != nullptr) sk.push(node->right);
            if (node->left != nullptr) sk.push(node->left);
        }
        return ret;
    }
};








/******************************************************������������������ǵݹ飩************************************************/
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        if (root == nullptr) return ret;

        stack<TreeNode*> sk;
        TreeNode* current = root;
        while (current != nullptr || !sk.empty())
        {
            //��·���ȫ����ջ
            while (current != nullptr) {
                sk.push(current);
                current = current->left;
            }

            TreeNode* node = sk.top();
            ret.push_back(node->val);
            sk.pop();

            current = node->right;//�����⣬����������
        }
        return ret;
    }
};









/*********************************************************�������ĺ������(�ǵݹ�)**********************************************/
/*
���������
��Ҫ����һ����㣬��һ�����ʵĽ���Ȼ�������ӽ�㣨�������ӽ�㣩
*/
class Solution3 {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        if (root == nullptr) return ret;

        stack<TreeNode*> sk;
        TreeNode* current = root;
        TreeNode* prev = nullptr;//��¼��һ�����ʵĽ��
        while (current != nullptr || !sk.empty())
        {
            //��·���ȫ����ջ
            while (current != nullptr) {
                sk.push(current);
                current = current->left;
            }

            TreeNode* node = sk.top();
            if (node->right == nullptr || node->right == prev)//������ || �����������
            {
                ret.push_back(node->val);
                prev = node;
                sk.pop();
            }
            else current = node->right;//�����⣬����������
        }
        return ret;
    }
};