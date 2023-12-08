#include <iostream>
#include <vector>

int maxProfit(std::vector<int> &prices)
{

    // std::vector<int> dif;
    int res = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        int temp = prices[i + 1] - prices[i];
        if (temp > 0)
        {
            res += temp;
        }
    }
    return res;
}

int maxProfit2(std::vector<int> &prices)
{
    // 动态规划
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));

    // 初始化
    dp[0][0] = -prices[0]; // 持有股票
    dp[0][1] = 0;          // 不持有股票

    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[prices.size() - 1][1];
}

int main()
{
    std::vector<int> a{7, 1, 5, 3, 6, 4};
    int res = maxProfit(a);
    std::cout << res << '\n';
    return res;
}