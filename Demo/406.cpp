#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

class MyCompare
{
    // public:
    //     bool operator()(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b)
    //     {
    //         // 写不出来怎么排序
    //         return
    //     }
public:
    // 参数写错了，比的是中间的元素
    bool operator()(const std::vector<int> &a, const std::vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }
        else
        {
            return a[0] > b[0];
        }
    }
};

std::vector<std::vector<int>> reconstructQueue1(std::vector<std::vector<int>> &people)
{
    // 先考虑一个维度，按身高从高到低排序
    std::vector<std::vector<int>> queue;
    std::sort(people.begin(), people.end(), MyCompare());

    for (int i = 0; i < people.size(); i++)
    {
        // 从身高高的开始插入，将身高低的插入到其中，不会影响后序身高更低的
        int position = people[i][1];
        queue.insert(queue.begin() + position, people[i]);
    }
    return queue;
}

// vector的插入复杂度太高，换为list
std::vector<std::vector<int>> reconstructQueue2(std::vector<std::vector<int>> &people)
{
    // 先考虑一个维度，按身高从高到低排序
    std::list<std::vector<int>> queue;
    std::sort(people.begin(), people.end(), MyCompare());

    for (int i = 0; i < people.size(); i++)
    {
        // 从身高高的开始插入，将身高低的插入到其中，不会影响后序身高更低的
        int position = people[i][1];
        std::list<std::vector<int>>::iterator it = queue.begin();
        while (position--)
        {
            // 寻找插入位置
            it++;
        }
        queue.insert(it, people[i]);
    }
    return std::vector<std::vector<int>>(queue.begin(), queue.end());
}