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

bool isValidBST(TreeNode *root)
{
    if (root->left && root->right)
    {
        if (root->val <= root->left->val || root->val >= root->right->val)
        {
            return false;
        }
        return true;
    }
    else if (root->left && !root->right)
    {
        if (root->val <= root->left->val)
        {
            return false;
        }
        return true;
    }
    else if (!root->left && root->right)
    {
        if (root->val >= root->right->val)
        {
            return false;
        }
        return true;
    }
    else
    {
        return true;
    }

    return isValidBST(root->left) && isValidBST(root->right);
}