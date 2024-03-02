/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int cmp = 0;

        for (int i = 0; i < haystack.length(); ++i)
        {
            if (haystack[i] == needle[0])
            {
                while (cmp < needle.length())
                {
                    if (haystack[i + cmp] != needle[cmp])
                    {
                        break;
                    }
                    cmp++;
                }
                if (cmp == needle.length())
                {
                    return i;
                }
                cmp = 0;
            }
        }
        return -1;
    }
};
// @lc code=end
