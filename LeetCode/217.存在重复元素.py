#
# @lc app=leetcode.cn id=217 lang=python3
#
# [217] 存在重复元素
#

# @lc code=start
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums_map = {}
        for i in range(0, len(nums)):
            if nums[i] in nums_map:
                return True
            nums_map[nums[i]] = True
        return False
# @lc code=end

