/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        int accumulate = 0;
        const char *start = s.c_str();
        while (*start != '\0')
        {
            accumulate += switchCase(start);
            ++start;
        }
        return accumulate;
    }

    int switchCase(const char *&c)
    {
        switch (*c)
        {
        case 'I':
        {
            char next = *(c + 1);
            if (next != '\0')
            {
                if (next == 'V')
                {
                    c++;
                    return 4;
                }
                if (next == 'X')
                {
                    c++;
                    return 9;
                }
            }
            return 1;
        }
        case 'V':
            return 5;
        case 'X':
        {

            char next = *(c + 1);
            if (next != '\0')
            {
                if (next == 'L')
                {
                    c++;
                    return 40;
                }
                if (next == 'C')
                {
                    c++;
                    return 90;
                }
            }
            return 10;
        }
        case 'L':
            return 50;
        case 'C':
        {

            char next = *(c + 1);
            if (next != '\0')
            {
                if (next == 'D')
                {
                    c++;
                    return 400;
                }
                if (next == 'M')
                {
                    c++;
                    return 900;
                }
            }
            return 100;
        }
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        throw std::runtime_error("??");
    }
};
// @lc code=end
