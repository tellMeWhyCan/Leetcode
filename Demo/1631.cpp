#include <iostream>
#include <vector>

int minimumEffortPath(std::vector<std::vector<int>> &heights)
{
    int m = heights.size();
    int n = heights[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n));

    // 初始化第一行和第一列
    dp[0][0] = 0;
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = std::max(dp[i - 1][0], heights[i][0] - heights[i - 1][0]);
    }
    for (int j = 1; j < n; j++)
    {
        dp[0][j] = std::max(dp[0][j - 1], heights[0][j] - heights[0][j - 1]);
    }

    // 递推
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = std::min(std::max(dp[i][j - 1], std::abs(heights[i][j] - heights[i][j - 1])), std::max(dp[i - 1][j], std::abs(heights[i][j] - heights[i - 1][j])));
        }
    }
    std::cout << dp[m - 1][n - 1] << '\n';
    return dp[m - 1][n - 1];
}

int main()
{
    std::vector<std::vector<int>> dp{{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    minimumEffortPath(dp);
    return 0;
}