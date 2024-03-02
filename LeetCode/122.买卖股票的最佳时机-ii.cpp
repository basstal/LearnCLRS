/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int s = prices.size();
        std::vector<int> dp(s - 1, 0);
        for (int i = 0; i < s - 1; ++i)
        {
            dp[i] = prices[i + 1] - prices[i];
        }

        int globalMax = 0;
        for (int i = 0; i < s - 1; ++i)
        {
            globalMax = dp[i] > 0 ? globalMax + dp[i] : globalMax;
        }
        return globalMax;
    }
};
// @lc code=end
