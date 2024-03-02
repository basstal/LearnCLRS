/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int s = nums.size();
        int checkAt = s - 1;
        nums[s - 1] = s - 1;
        while (checkAt > 0)
        {
            checkAt = CanJumpTo(nums, checkAt);
        }
        return checkAt == 0;
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
