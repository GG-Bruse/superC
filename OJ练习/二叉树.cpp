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
/*******************************************************根据二叉树创建字符串****************************************************/
/*
给你二叉树的根节点 root ，请你采用前序遍历的方式，将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串。
空节点使用一对空括号对 "()" 表示，转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对
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


//class Solution1 {//递归
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
//class Solution2 {//迭代
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
















/*******************************************************二叉树的层序遍历********************************************************/
/*
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）
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
//            int levelSize = qe.size();//这层结点的个数
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














/*****************************************************二叉树的最近公共祖先******************************************************/
/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，
最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）
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













/***************************************************二叉搜索树与双向链表（牛客）************************************************/
/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表

1.要求不能创建任何新的结点，只能调整树中结点指针的指向。当转化完成以后，树中节点的左指针需要指向前驱，
树中节点的右指针需要指向后继
2.返回链表中的第一个节点的指针
3.函数返回的TreeNode，有左右指针，其实可以看成一个双向链表的数据结构
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














/*************************************************从前序与中序遍历序列构造二叉树************************************************/
/*
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， 
inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点
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














/***************************************************从中序与后序遍历序列构造二叉树***********************************************/
/*
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， 
postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树
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









/********************************************* 二叉树的右视图（LeetCode）**************************************************/
/*
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值
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










/******************************************** 二叉树展开为链表（LeetCode）*************************************************/
/*
给你二叉树的根结点 root ，请你将它展开为一个单链表：
展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null
展开后的单链表应该与二叉树 先序遍历 顺序相同
*/
//class Solution1 {
//public:
//    void flatten(TreeNode* root)
//    {
//        TreeNode* node = root;
//        while (node != nullptr)
//        {
//            //找到左子树的最右结点
//            TreeNode* current = node->left;
//            while (current != nullptr && current->right != nullptr) current = current->right;
//            //变换
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
//        TreeNode* prev = nullptr;//记录上一个结点
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










/******************************************* 将有序数组转换为二叉搜索树（LeetCode）**************************************/
/*
给你一个整数数组nums，其中元素已经按升序排列，请你将其转换为一棵高度平衡二叉搜索树
高度平衡二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树
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










/*************************************************** 路径总和III （LeetCode）********************************************/
/*
给定一个二叉树的根节点root，和一个整数targetSum ，求该二叉树里节点值之和等于targetSum的路径的数目
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）
*/
////深度优先遍历
//class Solution1 {
//public:
//    int pathSum(TreeNode* root, long long targetSum)
//    {
//        if (root == nullptr) return 0;
//        //递归,以每个结点为起点都进行计算
//        int ret = rootSum(root, targetSum);
//        ret += pathSum(root->left, targetSum);
//        ret += pathSum(root->right, targetSum);
//        return ret;
//    }
//    //node结点为起点向下,满足总和为value的路径数目
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
////前缀和优化
//class Solution2 {
//public:
//    //前缀 : 根结点到当前结点的路径上所有节点的和 
//    unordered_map<long long, int> prefix;//和:路径个数
//    int dfs(TreeNode* root, long long current, int targetSum)
//    {
//        if (root == nullptr) return 0;
//        int ret = 0;
//        current += root->val;// 从根节点到当前节点的前缀和为current
//        if (prefix.count(current - targetSum)) {//从根节点到当前结点的前缀和为current-targetSum的结点
//            ret = prefix[current - targetSum];
//        }
//        //向下递归
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











/*******************************************************二叉树的前序遍历(非递归)*************************************************/
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








/******************************************************二叉树的中序遍历（非递归）************************************************/
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
            //左路结点全部入栈
            while (current != nullptr) {
                sk.push(current);
                current = current->left;
            }

            TreeNode* node = sk.top();
            ret.push_back(node->val);
            sk.pop();

            current = node->right;//子问题，访问右子树
        }
        return ret;
    }
};









/*********************************************************二叉树的后序遍历(非递归)**********************************************/
/*
后序遍历：
若要访问一个结点，上一个访问的结点必然是其右子结点（存在右子结点）
*/
class Solution3 {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        if (root == nullptr) return ret;

        stack<TreeNode*> sk;
        TreeNode* current = root;
        TreeNode* prev = nullptr;//记录上一个访问的结点
        while (current != nullptr || !sk.empty())
        {
            //左路结点全部入栈
            while (current != nullptr) {
                sk.push(current);
                current = current->left;
            }

            TreeNode* node = sk.top();
            if (node->right == nullptr || node->right == prev)//无右树 || 右树访问完成
            {
                ret.push_back(node->val);
                prev = node;
                sk.pop();
            }
            else current = node->right;//子问题，访问右子树
        }
        return ret;
    }
};