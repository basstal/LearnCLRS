/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int beginHeight = 1;
        // int maxHeight = Max(height);
        int accumulate = 0;
        int left = FindFirstOfHeight(height), right = FindLastOfHeight(height);
        if (left >= right)
        {
            return 0;
        }
        int heightOfLeft = height[left];
        int heightOfRight = height[right];
        int currentHeight = std::min(heightOfLeft, heightOfRight);
        if (heightOfLeft != heightOfRight)
        {
            if (heightOfLeft > heightOfRight)
            {
                left--;
            }
            else
            {
                right++;
            }
        }
        while (left < right)
        {
            heightOfLeft = height[++left];
            while (left < right && heightOfLeft <= currentHeight)
            {
                accumulate += currentHeight - heightOfLeft;
                heightOfLeft = height[++left];
            }
            heightOfRight = height[--right];
            while (left < right && heightOfRight <= currentHeight)
            {
                accumulate += currentHeight - heightOfRight;
                heightOfRight = height[--right];
            }
            if (left >= right)
            {
                break;
            }
            if (heightOfLeft != heightOfRight)
            {
                if (heightOfLeft > heightOfRight)
                {
                    left--;
                }
                else
                {
                    right++;
                }
            }
            currentHeight = std::min(heightOfLeft, heightOfRight);
        }
        // for (int currentHeight = beginHeight; currentHeight <= maxHeight; ++currentHeight)
        // {
        //     int begin = FindFirstOfHeight(height, currentHeight);
        //     int end = FindLastOfHeight(height, currentHeight);
        //     for (int i = begin + 1; i < end; ++i)
        //     {
        //         if (height[i] < currentHeight)
        //         {
        //             accumulate++;
        //         }
        //     }
        // }
        return accumulate;
    }

    int FindFirstOfHeight(vector<int> &heights)
    {
        for (int i = 0; i < heights.size(); ++i)
        {
            if (heights[i] > 0)
            {
                return i;
            }
        }
        return -1;
    }

    int FindLastOfHeight(vector<int> &heights)
    {
        for (int i = heights.size() - 1; i >= 0; --i)
        {
            if (heights[i] > 0)
            {
                return i;
            }
        }
        return -1;
    }

    int Max(vector<int> &heights)
    {
        int max = heights[0];
        for (int i = 1; i < heights.size(); ++i)
        {
            if (heights[i] > max)
            {
                max = heights[i];
            }
        }
        return max;
    }
};
// @lc code=end
