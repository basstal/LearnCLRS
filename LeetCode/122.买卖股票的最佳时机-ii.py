#
# @lc app=leetcode.cn id=122 lang=python3
#
# [122] 买卖股票的最佳时机 II
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        i = 0
        sum = 0
        while i + 1 < n:
            if prices[i+1] - prices[i] > 0:
                sum += prices[i+1] - prices[i]
            i += 1
        return sum
# @lc code=end

