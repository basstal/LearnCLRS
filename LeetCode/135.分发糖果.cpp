/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        bool isDescend = false;
        bool isAscend = false;
        bool isStick = false;
        bool lastEqual = false;
        int s = ratings.size();
        int accumulate = s;
        if (s == 1)
        {
            return accumulate;
        }
        int a = ratings[0];
        int b = ratings[1];
        if (s == 2)
        {
            return a != b ? accumulate + 1 : accumulate;
        }
        int index = findFirstNotEqual(ratings, a);
        if (index == -1)
        {
            return accumulate;
        }
        b = ratings[index];
        isDescend = a > b;
        isAscend = a < b;
        int accumulatedLastSlope = 1;
        while (index < s)
        {
            int slope = 1;
            while (isAscend && index < s)
            {
                if (a != b)
                {
                    accumulate += slope;
                    slope++;
                }
                else
                {
                    slope = 1;
                }
                getNextAB(ratings, index, a, b);
                isDescend = a > b;
                isAscend = a <= b;
                isStick = isDescend && !lastEqual;
                lastEqual = a == b;
            }
            accumulatedLastSlope = slope - 1;
            slope = 1;
            int maxDescendSlope = slope - 1;
            while (isDescend && index < s)
            {
                if (a != b)
                {
                    accumulate += slope;
                    maxDescendSlope = std::max(maxDescendSlope, slope);
                    slope++;
                }
                else
                {
                    slope = 1;
                }
                getNextAB(ratings, index, a, b);
                isDescend = a >= b;
                isAscend = a < b;
            }

            if (isStick) // 如果是尖峰，需要将顶部算重了的减掉
            {
                accumulate -= ::min(accumulatedLastSlope, maxDescendSlope);
            }
            // 如果是平峰则不用减
        }
        return accumulate;
    }

    void getNextAB(vector<int> &ratings, int &index, int &a, int &b)
    {
        ++index;
        if (index < ratings.size())
        {
            a = b;
            b = ratings[index];
        }
    }

    int findFirstNotEqual(vector<int> &ratings, int a)
    {
        for (int i = 0; i < ratings.size(); ++i)
        {
            if (ratings[i] != a)
            {
                return i;
            }
        }
        return -1;
    }
    // int candy(vector<int> &ratings)
    // {
    //     int s = ratings.size();
    //     vector<int> result(s, 1);
    //     vector<int> minIndexes = findAllMin(ratings);
    //     for (auto minIndex : minIndexes)
    //     {
    //         int usingIndex = minIndex;
    //         while (usingIndex > 0)
    //             forward(ratings, result, usingIndex);
    //         usingIndex = minIndex;
    //         while (usingIndex < s - 1)
    //             backward(ratings, result, usingIndex);
    //     }
    //     return std::accumulate(result.begin(), result.end(), 0);
    // }

    // void forward(vector<int> &ratings, vector<int> &result, int &forwardIndex)
    // {
    //     // if (ratings[forwardIndex - 1] <= ratings[forwardIndex])
    //     // {
    //     //     forwardIndex--;
    //     // }
    //     if (ratings[forwardIndex - 1] > ratings[forwardIndex])
    //     {
    //         if (result[forwardIndex - 1] <= result[forwardIndex])
    //         {
    //             result[forwardIndex - 1] = result[forwardIndex] + 1;
    //         }
    //     }
    //     forwardIndex--;
    // }

    // void backward(vector<int> &ratings, vector<int> &result, int &forwardIndex)
    // {
    //     // if (ratings[forwardIndex + 1] <= ratings[forwardIndex])
    //     // {
    //     //     forwardIndex++;
    //     // }
    //     if (ratings[forwardIndex + 1] > ratings[forwardIndex])
    //     {
    //         if (result[forwardIndex + 1] <= result[forwardIndex])
    //         {
    //             result[forwardIndex + 1] = result[forwardIndex] + 1;
    //         }
    //     }
    //     forwardIndex++;
    // }

    // vector<int> findAllMin(vector<int> &ratings)
    // {
    //     int min = ratings[0];
    //     for (int i = 1; i < ratings.size(); ++i)
    //     {
    //         if (min > ratings[i])
    //         {
    //             min = ratings[i];
    //         }
    //     }
    //     vector<int> result;
    //     for (int i = 0; i < ratings.size(); ++i)
    //     {
    //         if (ratings[i] == min)
    //         {
    //             result.push_back(i);
    //         }
    //     }
    //     return result;
    // }
};
// @lc code=end

// 19 + 1 + 2 + 3 + 1 + 2 + 3 + 4 - 3 + 1 + 1 + 2 + 3 - 1 + 1 + 1 + 2 - 1(0) + 1 + 2 + 3