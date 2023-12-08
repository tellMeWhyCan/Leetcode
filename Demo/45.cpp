#include <iostream>
#include <vector>

int jump(std::vector<int> &nums)
{
    // 每一步尽可能的走，走到不能走了为止
    int curcover = 0;
    int nextcover = 0;
    int res = 0;
    if (nums.size() == 1)
        return 0;
    for (int i = 0; i < nums.size(); i++)
    {
        nextcover = std::max(nextcover, i + nums[i]);
        if (i == curcover)
        {
            // 到达当前覆盖范围的终点
            res++;
            curcover = nextcover;
            if (nextcover >= nums.size() - 1)
            {
                break;
            }
        }
    }
    return res;
}