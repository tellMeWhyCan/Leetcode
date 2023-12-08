#include <iostream>
#include <vector>

bool lemonadeChange(std::vector<int> &bills)
{
    int fiveCount = 0;
    int tenCount = 0;
    for (const auto &elm : bills)
    {
        if (elm == 5)
        {
            fiveCount++;
        }
        else if (elm == 10)
        {
            tenCount++;
            fiveCount--;
        }
        else
        {
            if (tenCount != 0)
            {
                tenCount--;
                fiveCount--;
            }
            else
            {
                fiveCount -= 3;
            }
        }

        if (fiveCount < 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::vector<int> bills{5, 5, 5, 10, 20};

    bool res = lemonadeChange(bills);
    std::cout << res << '\n';
    return 0;
}