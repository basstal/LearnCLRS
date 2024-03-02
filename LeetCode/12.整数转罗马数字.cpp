/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution
{
public:
    string intToRoman(int num)
    {
        char c[100];
        int start = 0;
        int q = num / 1000;
        int b = num % 1000 / 100;
        int s = num % 100 / 10;
        int g = num % 10;
        switchCase(q, start, c, 'M', 'M', 'M');
        switchCase(b, start, c, 'C', 'D', 'M');
        switchCase(s, start, c, 'X', 'L', 'C');
        switchCase(g, start, c, 'I', 'V', 'X');
        c[start] = '\0';
        return std::string(c);
    }

    void switchCase(int inNum, int &charIndex, char *c, char one, char five, char ten)
    {
        switch (inNum).
        {
        case 1:
            c[charIndex++] = one;
            return;
        case 2:
            c[charIndex++] = one;
            c[charIndex++] = one;
            return;
        case 3:
            c[charIndex++] = one;
            c[charIndex++] = one;
            c[charIndex++] = one;
            return;
        case 4:
            c[charIndex++] = one;
            c[charIndex++] = five;
            return;
        case 5:
            c[charIndex++] = five;
            return;
        case 6:
            c[charIndex++] = five;
            c[charIndex++] = one;
            return;
        case 7:
            c[charIndex++] = five;
            c[charIndex++] = one;
            c[charIndex++] = one;
            return;
        case 8:
            c[charIndex++] = five;
            c[charIndex++] = one;
            c[charIndex++] = one;
            c[charIndex++] = one;
            return;
        case 9:
            c[charIndex++] = one;
            c[charIndex++] = ten;
            return;
        case 0:
            return;
        }
        throw std::runtime_error("?? " + std::to_string(inNum));
    }
};
// @lc code=end
