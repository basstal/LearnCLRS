/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        const char *s[strs.size()];
        int i = 0;
        for (auto &str : strs)
        {
            s[i++] = str.c_str();
        }
        i = 0;
        while (commonPrefix(s, strs.size(), i))
        {
            i++;
        }
        char result[i + 1];
        int t = 0;
        for (; t < i; ++t)
        {
            result[t] = s[0][t];
        }
        result[t] = '\0';
        return std::string(result);
    }

    bool commonPrefix(const char **strs, int size, int i)
    {
        char c = strs[0][i];
        if (c == '\0')
        {
            return false;
        }
        for (int s = 0; s < size; ++s)
        {
            if (strs[s][i] != c)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
