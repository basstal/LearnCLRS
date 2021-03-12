#
# @lc app=leetcode.cn id=189 lang=python3
#
# [189] 旋转数组
#

# @lc code=start
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = len(nums)
        k = k % l
        visited = list(range(1, l + 1))
        for i in range(0, l):
            if visited[i - 1] > 0:
                n = i
                cVal = nums[i]
                while ((n + k) % l) != i:
                    n = (n + k) % l
                    nVal = nums[n]
                    nums[n] = cVal
                    cVal = nVal
                    visited[n - 1] = 0
                nums[i] = cVal
# @lc code=end

