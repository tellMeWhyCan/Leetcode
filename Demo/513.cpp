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

int maxDepth = INT_MIN;
int res;
void dfs(TreeNode *node, int depth)
{
    // 找左下角的值，所以要求深度，最深深度下左侧优先
    if (node->left == nullptr && node->right == nullptr)
    {
        // 肯定是叶子节点
        if (depth > maxDepth)
        {
            maxDepth = depth;
            res = node->val;
        }
        return;
    }
    if (node->left)
    {
        depth++;
        dfs(node->left, depth);
        depth--;
    }

    if (node->right)
    {
        depth++;
        dfs(node->right, depth);
        depth--;
    }
    return;
}
int findBottomLeftValue(TreeNode *root)
{
    dfs(root, 0);
    return res;
}