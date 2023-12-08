#include <iostream>
#include <vector>
#include <algorithm>

class MyCompare
{
public:
    bool operator()(const std::vector<int> &a, const std::vector<int> &b)
    {
        return a[0] < b[0];
    }
};

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
{
    std::vector<std::vector<int>> res;
    std::sort(intervals.begin(), intervals.end(), MyCompare());

    int end = -1;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= intervals[i - 1][1])
        {
            intervals[i][0] = intervals[i - 1][0];
            intervals[i][1] = std::max(intervals[i][1], intervals[i - 1][1]);
        }
        else
        {
            res.push_back(intervals[i - 1]);
            end = i - 1;
        }
    }
    if (end != intervals.size() - 1)
    {
        res.push_back(intervals[intervals.size() - 1]);
    }
    return res;
}

int main()
{
    std::vector<std::vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::vector<std::vector<int>> res;
    res = merge(intervals);
    return 0;
}