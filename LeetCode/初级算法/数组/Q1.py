# https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2gy9m/

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