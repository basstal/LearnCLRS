#
# @lc app=leetcode.cn id=26 lang=python3
#
# [26] 删除排序数组中的重复项
#

# @lc code=start
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) > 1:
            lastV = nums[0]
            newSize = 1
            vIndex = 1
            while(vIndex < len(nums)):
                v = nums[vIndex]
                if v > lastV:
                    lastV = v
                    nums[newSize] = v
                    newSize += 1
                else:
                    vIndex += 1
            return newSize
        else:
            return len(nums)
# @lc code=end

