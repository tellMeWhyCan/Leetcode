#include <iostream>
#include <vector>

int canCompleteCircuit1(std::vector<int> &gas, std::vector<int> &cost)
{
    int index = -1;
    for (int i = 0; i < gas.size(); i++)
    {
        // 剪枝
        if (i > 0 && gas[i] == gas[i - 1] && cost[i] == cost[i - 1])
        {
            continue;
        }
        int dif = gas[i] - cost[i];
        if (dif < 0)
            continue;
        index = i;
        for (int j = index + 1;; j++)
        {
            if (j % gas.size() == index)
            {
                return index;
            }
            int dif2 = gas[j % gas.size()] - cost[j % gas.size()];
            if (dif + dif2 < 0)
            {
                break;
            }
            dif += dif2;
        }
    }
    return -1;
}

int canCompleteCircuit2(std::vector<int> &gas, std::vector<int> &cost)
{
    int total = 0;
    int min_rest = INT_MAX;
    for (int i = 0; i < gas.size(); i++)
    {
        int cur_rest = gas[i] - cost[i];
        total += cur_rest;
        if (cur_rest < min_rest)
        {
            min_rest = cur_rest;
        }
    }

    if (total < 0)
    {
        return -1;
    }
    if (min_rest >= 0)
    {
        return 0;
    }

    for (int i = gas.size(); i >= 0; i--)
    {
        int rest = gas[i] - cost[i];
        min_rest += rest;
        if (min_rest >= 0)
        {
            return i;
        }
    }
}
int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
{
    int curSum = 0;
    int totalSum = 0;
    int start = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        curSum += gas[i] - cost[i];
        totalSum += gas[i] - cost[i];
        if (curSum < 0)
        {
            start = i + 1;
            curSum = 0;
        }
    }

    if (totalSum < 0)
        return -1;
    return start;
}
int main()
{
    std::vector<int> gas{3, 1, 1};
    std::vector<int> cost{1, 2, 2};
    int res = canCompleteCircuit(gas, cost);
    std::cout << res << '\n';
    return res;
}