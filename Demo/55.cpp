#include <iostream>
#include <vector>

bool canJump(std::vector<int> &nums)
{
    int max_len = 0;
    if (nums.size() == 1)
        return true;
    if (nums[0] == 0)
        return false;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i; j <= i + nums[i] && j < nums.size() - 1; j++)
        {
            // 选出一个到达最远的地方
            if (max_len < j + nums[j])
            {
                max_len = j + nums[j];
                // i = j + nums[j];
            }
        }
        i = max_len;
        if (max_len >= nums.size() - 1)
        {
            return true;
        }
    }
    return false;
}
bool canJump2(std::vector<int> &nums)
{
    // 上面写的太复杂了，一个for循环就足够了

    int max_len = nums[0];
    if (nums.size() == 1)
        return true;
    for (int i = 0; i <= max_len; i++)
    {
        if (max_len < i + nums[i])
        {
            max_len = i + nums[i];
        }
        if (max_len >= nums.size() - 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::vector<int> nums{3, 2, 1, 0, 4};
    bool res = canJump(nums);
    std::cout << res << '\n';
    return res;
}