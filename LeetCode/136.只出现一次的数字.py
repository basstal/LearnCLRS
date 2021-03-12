#
# @lc app=leetcode.cn id=136 lang=python3
#
# [136] 只出现一次的数字
#

# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        l = len(nums)
        n = 0
        for i in range(0, l):
            n ^= nums[i]
        return n
# @lc code=end

