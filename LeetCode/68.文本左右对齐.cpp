/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
class Solution
{
public:
    int *lineWordIndexes = nullptr;
    int lineWordSize = 0;
    int wordLineWidth = 0;
    std::vector<std::string> lines;

    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        lineWordIndexes = new int[words.size()];
        for (int i = 0; i < words.size(); ++i)
        {
            int wl = words[i].length();
            // 最后一个单词，最后一行需要不一样的结构
            bool isLastWord = i == words.size() - 1;
            if (wordLineWidth + wl + lineWordSize <= maxWidth) // lineWordSize 在这里代表最少需要的空格数
            {
                lineWordIndexes[lineWordSize++] = i;
                wordLineWidth += wl;
                if (isLastWord)
                {
                    PutLineLeftAlign(words, maxWidth);
                }
            }
            else // word 已经不能放到上一行，
            {
                PutLineLeftRightAlign(words, maxWidth);
                // 清理上一行残留数据，开始下一行，将 word 放到下一行开始，
                wordLineWidth = wl;
                lineWordIndexes[0] = i;
                lineWordSize = 1;
                if (isLastWord)
                {
                    PutLineLeftAlign(words, maxWidth);
                }
            }
        }
        return lines;
    }

    void PutLineLeftRightAlign(vector<string> &words, int maxWidth)
    {
        // 计算上一行的空格数并填充到结果中
        int totalSpace = maxWidth - wordLineWidth;
        // 不能均匀分配，以均匀分配为基础，剩下的分别分配给左侧的空格
        int eachSpace = lineWordSize > 1 ? totalSpace / (lineWordSize - 1) : totalSpace;
        int leftSpaces = lineWordSize > 1 ? totalSpace % (lineWordSize - 1) : 0;
        std::string content;
        for (int k = 0; k < lineWordSize; ++k)
        {
            std::string word = words[lineWordIndexes[k]];
            // 添加单词
            content.append(word);
            // 只有一个单词 或者 不是本行最后一个单词的情况下添加空格
            if (lineWordSize == 1 || k < lineWordSize - 1)
            {
                // 从左侧开始每个分配一个，直到没有余下的空格为止
                int addSpaceCount = leftSpaces > 0 ? eachSpace + 1 : eachSpace;
                leftSpaces -= 1;
                content.append(addSpaceCount, ' ');
            }
        }
        lines.push_back(content);
    }

    void PutLineLeftAlign(vector<string> &words, int maxWidth)
    {
        int addedWords = 0;
        std::string content;
        for (int k = 0; k < lineWordSize; ++k)
        {
            std::string word = words[lineWordIndexes[k]];
            // 添加单词
            content.append(word);
            addedWords += word.length();
            if (k < lineWordSize - 1) // 还有其他单词，添加单个空格
            {
                content.append(1, ' ');
                addedWords += 1;
            }
            else
            {
                content.append(maxWidth - addedWords, ' '); // 没有其他单词，后面全是空格
            }
        }
        lines.push_back(content);
    }
};
// @lc code=end
