#include <iostream>
#include <vector>
#include <algorithm>

class MyCompare
{
public:
    bool operator()(const std::vector<int> &a, const std::vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
};

int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals)
{
    std::sort(intervals.begin(), intervals.end(), MyCompare());
    int res = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] < intervals[i - 1][1])
        {
            // intervals[i][0] = intervals[i - 1][0];
            // intervals[i][1] = intervals[i - 1][1];
            intervals[i][1] = std::min(intervals[i - 1][1], intervals[i][1]);
            res++;
        }
    }
    return res;
}

class Solution
{
public:
    static bool cmp(const std::vector<int> &a, const std::vector<int> &b)
    {
        return a[1] < b[1];
    }

    static bool cmp1(const std::vector<int> &a, const std::vector<int> &b)
    {
        return a[0] < b[0];
    }

    int eraseOverlapIntervals1(std::vector<std::vector<int>> &intervals)
    {
        // 右排序
        // 统计非交叉的区间个数
        int res = 1;
        std::sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < end)
            {
                continue;
            }
            else
            {
                res++;
                end = intervals[i][1];
            }
        }
        return intervals.size() - res;
    }

    int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals)
    {
        // 左排序
        // 求重叠的区间
        int res = 1;
        std::sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > end)
            {
                // 无重叠
                end = intervals[i][1];
            }
            else
            {
                end = std::min(end, intervals[i][1]);
                res++;
            }
        }
        return res;
    }
};

int main()
{
    std::vector<std::vector<int>> intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    eraseOverlapIntervals(intervals);
    return 0;
}