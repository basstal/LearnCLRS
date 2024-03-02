/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        if (!canComplete(gas, cost))
        {
            return -1;
        }
        int s = gas.size();
        for (int i = 0; i < s; ++i)
        {
            if (gas[i] - cost[i] > 0)
            {
                if (tryStart(gas, cost, i))
                {
                    return i;
                }
            }
        }
        for (int i = 0; i < s; ++i)
        {
            if (gas[i] - cost[i] == 0)
            {
                if (tryStart(gas, cost, i))
                {
                    return i;
                }
            }
        }
        throw std::runtime_error("??");
    }

    bool tryStart(vector<int> &gas, vector<int> &cost, int start)
    {
        int currentGas = 0;
        int currentCost = 0;
        for (int s = 0; s < gas.size(); ++s)
        {
            int p = (start + s) % gas.size();
            currentGas += gas[p];
            currentCost += cost[p];
            if (currentCost > currentGas)
            {
                return false;
            }
        }
        return true;
    }

    bool canComplete(vector<int> &gas, vector<int> &cost)
    {
        int currentGas = 0;
        int currentCost = 0;
        for (int s = 0; s < gas.size(); ++s)
        {
            currentGas += gas[s];
            currentCost += cost[s];
        }
        if (currentCost > currentGas)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end
