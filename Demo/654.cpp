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

TreeNode *constructMaximumBinaryTree(std::vector<int> &nums)
{
    TreeNode *node = new TreeNode(0);
    if (nums.size() == 1)
    {
        node->val = nums[0];
        return node;
    }

    int maxNum = 0;
    int maxNumIndex = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > maxNum)
        {
            maxNum = nums[i];
            maxNumIndex = i;
        }
    }

    node->val = maxNum;

    // 左区间
    if (maxNumIndex > 0)
    {
        std::vector<int> left(nums.begin(), nums.begin() + maxNumIndex);
        node->left = constructMaximumBinaryTree(left);
    }

    // 右区间
    if (maxNumIndex < nums.size() - 1)
    {
        std::vector<int> right(nums.begin() + maxNumIndex + 1, nums.end());
        node->right = constructMaximumBinaryTree(right);
    }
    return node;
}

int main()
{
    std::vector<int> left{3, 2, 1, 6, 0, 5};
    TreeNode *node = constructMaximumBinaryTree(left);
    int a = node->val;

    return 0;
}