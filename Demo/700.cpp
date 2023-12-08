#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->val == val)
    {
        return root;
    }
    searchBST(root->left, val);
    searchBST(root->right, val);
    return NULL;
}

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL || root->val == val)
        return root;
    TreeNode *result = NULL;
    if (root->val > val)
        result = searchBST(root->left, val);
    if (root->val < val)
        result = searchBST(root->right, val);
    return result;
}