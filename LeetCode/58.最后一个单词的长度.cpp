/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        const char *l = s.c_str();
        int sl = s.length() - 1;
        while (*(l + sl) == ' ')
        {
            --sl;
        }
        int result = 0;
        while (sl >= 0 && *(l + sl) != ' ')
        {
            --sl;
            ++result;
        }
        return result;
    }
};
// @lc code=end
