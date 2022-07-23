#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    char val;
};
struct TreeNode* CreateTree(char* arr,int* pi)
{
    if(arr[*pi] == '#')
    {
        ++(*pi);
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if(root == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    root->val = arr[*pi];
    ++(*pi);
    root->left = CreateTree(arr,pi);
    root->right = CreateTree(arr,pi);
    return root;
}
void inOrder(struct TreeNode* root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%c ",root->val);
    inOrder(root->right);
}
int main()
{
    char str[100] = {0};
    scanf("%s",str);
    int i = 0;
    struct TreeNode* root = CreateTree(str,&i);
    inOrder(root);
    return 0;
}




int maxDepth(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    int leftDepth= maxDepth(root->left);
    int rightDepth= maxDepth(root->right);
    return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
}
bool isBalanced(struct TreeNode* root)
{
    if(root == NULL)
        return true;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (abs(leftDepth - rightDepth) < 2) && isBalanced(root->left) && isBalanced(root->right);
}