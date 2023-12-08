#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class myCompare
{
public:
    bool operator()(const int a, const int b) const
    {
        return std::abs(a) > std::abs(b);
    }
};
int largestSumAfterKNegations1(std::vector<int> &nums, int k)
{
    // 局部最优：反转绝对值最大的负数
    // 负数反转完反转最小的正数
    int res = 0;
    std::sort(nums.begin(), nums.end(), myCompare());

    for (auto &temp : nums)
    {
        if (temp < 0 && k > 0)
        {
            temp *= -1;
            k--;
        }
    }

    // 跳出循环，意味着k没了或者全为正数
    if (k % 2 == 1)
    {
        nums[nums.size() - 1] *= -1;
    }

    res = std::accumulate(nums.begin(), nums.end(), 0);
    return res;
}

int largestSumAfterKNegations(std::vector<int> &nums, int k)
{
    // 局部最优：反转绝对值最大的负数
    // 负数反转完反转最小的正数
    int res = 0;
    std::sort(nums.begin(), nums.end());

    for (auto &temp : nums)
    {
        if (temp < 0 && k > 0)
        {
            temp *= -1;
            k--;
        }
    }

    sort(nums.begin(), nums.end());
    // 跳出循环，意味着k没了或者全为正数
    if (k % 2 == 1)
    {
        nums[0] *= -1;
    }

    res = std::accumulate(nums.begin(), nums.end(), 0);
    return res;
}

int main()
{
    std::vector<int> nums{2, -3, -1, 5, -4};
    int res = largestSumAfterKNegations(nums, 2);
    return 0;
}