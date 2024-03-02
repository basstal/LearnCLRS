/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int s = nums.size();
        vector<int> result(s, 0);
        int pre = 1, suf = 1;
        for (int i = 0; i < s; ++i)
        {
            result[i] = pre;
            pre *= nums[i];
        }
        for (int k = s - 1; k >= 0; --k)
        {
            result[k] *= suf;
            suf *= nums[k];
        }

        return result;
    }
};
// @lc code=end
