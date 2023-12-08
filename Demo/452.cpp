#include <iostream>
#include <vector>
#include <algorithm>

class MyCompare
{
public:
    bool operator()(const std::vector<int> a, const std::vector<int> b) const
    {
        return a[0] < b[0];
    }
};

int findMinArrowShots(std::vector<std::vector<int>> &points)
{

    if (points.size() == 0)
    {
        return 0;
    }
    // 局部最优：找到重合的最多数量的气球，遇到不重合的就要+1
    // 首先按第一维度排序
    std::sort(points.begin(), points.end(), MyCompare());

    int res = 1;
    // 判断是否有重叠
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] > points[i - 1][1])
        {
            // 没有重叠，说明前面的气球需要一个射箭
            res++;
        }
        else
        {
            // 有重叠，更新右边的最小重叠边界
            points[i][1] = std::min(points[i - 1][1], points[i][1]);
        }
    }
    return res;
}