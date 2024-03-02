/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int s = citations.size();
        std::vector<int> count(s + 1);
        for (int i = 0; i < s; ++i)
        {
            if (citations[i] >= count.size())
            {
                count[count.size() - 1]++;
            }
            else
            {
                count[citations[i]]++;
            }
        }
        int accumulate = 0;
        for (int i = count.size() - 1; i >= 0; --i)
        {
            accumulate += count[i];
            if (accumulate >= i)
            {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end
