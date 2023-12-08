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

int path = 0;
bool r = false;
bool dfs(TreeNode *node, int target)
{
    if (node == nullptr)
        return false;
    path += node->val;
    if (node->left == nullptr && node->right == nullptr)
    {
        if (path == target)
        {
            return true;
        }
        return false;
    }

    if (node->left)
    {
        dfs(node->left, target);
        path -= node->left->val;
    }

    if (node->right)
    {
        dfs(node->right, target);
        path -= node->right->val;
    }
    return r;
}
bool hasPathSum(TreeNode *root, int targetSum)
{
    return dfs(root, targetSum);
}