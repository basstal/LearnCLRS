/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        // numrows + numRows - 2;
        // numrows - 1 + numRows - 2 - 1
        // numRows - 2 + numRows - 2 - 2
        // ...

        // from 1 to n (numRows - 2)

        // final row equal to 0

        if (numRows == 1)
        {
            return s;
        }
        int slength = s.length();
        int i = 0;
        const char *c = s.c_str();
        // 计算首行
        std::string output;
        while (i < slength)
        {
            output.append(1, c[i]);
            i += numRows + numRows - 2;
        }
        // 计算中间行
        if (numRows > 2)
        {
            for (int t = 1; t <= numRows - 2; ++t)
            {
                i = t;
                while (i < slength)
                {
                    output.append(1, c[i]);
                    int interval = i + numRows - t + numRows - 2 - t;
                    if (interval < slength)
                    {
                        output.append(1, c[interval]);
                    }
                    i += numRows + numRows - 2;
                }
            }
        }

        // 计算末行
        i = numRows - 1;
        while (i < slength)
        {
            output.append(1, c[i]);
            i += numRows + numRows - 2;
        }

        return output;
    }
};
// @lc code=end
