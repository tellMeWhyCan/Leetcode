#include <iostream>
#include <vector>
#include <numeric>

int candy(std::vector<int> &ratings)
{
    // 先从左到右遍历，给右边的小朋友得分高分糖
    std::vector<int> candyNum(ratings.size(), 1);
    for (int i = 0; i < ratings.size() - 1; i++)
    {
        if (ratings[i] < ratings[i + 1])
        {
            candyNum[i + 1] = candyNum[i] + 1; // 注意：不是一共加1，而是比左边的多1个
        }
    }
    // 看右边,从后向前遍历，因为要知道之前的结果
    for (int i = ratings.size() - 1; i > 0; i--)
    {
        if (ratings[i - 1] > ratings[i])
        {
            candyNum[i - 1] = std::max(candyNum[i - 1], candyNum[i] + 1);
        }
    }
    int res = std::accumulate(candyNum.begin(), candyNum.end(), 0);
    return res;
}