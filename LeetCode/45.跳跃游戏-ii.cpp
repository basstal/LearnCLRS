/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int s = nums.size();
        int checkAt = s - 1;
        nums[s - 1] = s - 1;
        int jumpCount = 0;
        while (checkAt > 0)
        {
            checkAt = CanJumpTo(nums, checkAt);
            ++jumpCount;
        }
        return jumpCount;
    }

    int CanJumpTo(vector<int> &nums, int checkAt)
    {
        int distance = checkAt;
        for (int i = 0; i < checkAt; ++i)
        {
            if (nums[i] - distance >= 0)
            {
                return i;
            }
            --distance;
        }
        return -1;
    }
};
// @lc code=end
