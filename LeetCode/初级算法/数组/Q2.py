# https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2zsx1/

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
