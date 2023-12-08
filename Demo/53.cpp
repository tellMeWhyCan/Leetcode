#include <iostream>
#include <vector>

int maxSubArray(std::vector<int> &nums)
{
    // 贪心算法
    int res = INT_MIN;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        res = res > sum ? res : sum;
        if (sum < 0)
        {
            sum = 0;
            continue;
        }
    }

    return res;
}

int maxSubArray2(std::vector<int> &nums)
{
    // 动态规划
    int res = INT_MIN;
    std::vector<int> dp(nums.size(), 0);
    dp[0] = *(nums.begin());

    for (int i = 1; i < nums.size(); i++)
    {
        dp[i] = std::max(dp[i - 1] + nums[i], dp[i]);
        res = res > dp[i] ? res : dp[i];
    }
    return res;
}

int main()
{
    std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res = maxSubArray(nums);
    return res;
}