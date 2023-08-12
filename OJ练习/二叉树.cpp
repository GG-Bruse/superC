#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_set>
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
