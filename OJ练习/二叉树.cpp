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