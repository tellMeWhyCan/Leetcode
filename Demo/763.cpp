#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::vector<int> partitionLabels1(std::string s)
{
    std::vector<int> res;
    // 用数组（hash表来记录元素最后一次出现的位置）
    int a[26] = {};
    for (int i = 0; i < s.size(); i++)
    {
        a[s[i] - 'a'] = i;
    }

    int end = 0;
    // 感觉最外层循环多余了，一会改一下，改不了
    for (int i = 0; i < s.size() && end < s.size(); i++)
    {
        end = a[s[i] - 'a']; // 找到当前元素最后一次出现的位置
        // 直接取出最大值，其实不用，可以慢慢更新
        for (int j = i + 1; j < end; j++)
        {
            if (a[s[j] - 'a'] > end)
            {
                end = a[s[j] - 'a'];
            }
        }
        // if(i==end) 可以这样改进
        int temp = end - i + 1;
        i = end;
        res.push_back(temp);
    }
    return res;
}

// 一个for循环解决
std::vector<int> partitionLabels(std::string s)
{
    std::vector<int> res;
    // 用数组（hash表来记录元素最后一次出现的位置）
    int a[26] = {};
    for (int i = 0; i < s.size(); i++)
    {
        a[s[i] - 'a'] = i;
    }

    int end = 0;
    int start = 0;
    // 确实多余了两个for循环
    for (int i = 0; i < s.size(); i++)
    {
        end = std::max(end, a[s[i] - 'a']); // 找到当前元素最后一次出现的位置
        if (i == end)
        {
            res.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return res;
}

int main()
{
    std::string a = "ababcbacadefegdehijhklij";
    std::vector<int> res = partitionLabels(a);
    return 0;
}