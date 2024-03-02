/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        const char *c = s.c_str();
        int lth = s.length() - 1;
        std::string output;
        const char *wordEnd;
        const char *wordStart;

        while (lth >= 0)
        {
            if (*(c + lth) == ' ')
            {
                --lth;
                continue;
            }
            wordEnd = wordStart = c + lth;
            --lth;
            while (lth >= 0)
            {
                if (*(c + lth) == ' ')
                {
                    break;
                }
                wordStart = c + lth--;
            }
            int length = wordEnd - wordStart + 1;
            output.append(wordStart, length);
            output.append(" ");
        }
        output.erase(output.length() - 1, 1);
        return output;
    }
};
// @lc code=end
