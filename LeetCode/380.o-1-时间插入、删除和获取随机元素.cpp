/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet
{
public:
    int *container[200000];
    std::vector<int> hasValueContainer;
    bool zeroExist = false;
    RandomizedSet()
    {
        for (int i = 0; i < 200000; ++i)
        {
            container[i] = nullptr;
        }
        zeroExist = false;
        srand(static_cast<unsigned int>(time(0)));
    }

    bool insert(int val)
    {
        // 处理特殊值
        if (val == 0)
        {
            if (!zeroExist)
            {
                zeroExist = true;
                return true;
            }
            return false;
        }
        int key = std::abs(val) % 200000;
        // 元素肯定不存在，插入一个新的散列值
        if (container[key] == nullptr)
        {
            // 预分配冲突列表
            container[key] = new int[10]();
            container[key][0] = val;
            hasValueContainer.push_back(key);
            return true;
        }
        if (container[key][0] == 0)
        {
            hasValueContainer.push_back(key);
        }
        for (int i = 0; i < 10; ++i)
        {
            // 冲突列表中未找到元素，插入该元素
            if (container[key][i] == 0)
            {
                container[key][i] = val;
                return true;
            }
            // 元素已存在，返回 false
            if (container[key][i] == val)
            {
                return false;
            }
        }
        // 超出散列冲突处理能力
        throw std::runtime_error("??");
    }

    bool remove(int val)
    {
        // 处理特殊值
        if (val == 0)
        {
            if (zeroExist)
            {
                zeroExist = false;
                return true;
            }
            return false;
        }
        int key = std::abs(val) % 200000;
        // 元素肯定不存在，返回false
        if (container[key] == nullptr)
        {
            return false;
        }
        for (int i = 0; i < 10; ++i)
        {
            // 冲突列表中未找到元素返回 false
            if (container[key][i] == 0)
            {
                return false;
            }
            // 元素已存在，从集合中删除元素，返回 true
            if (container[key][i] == val)
            {
                container[key][i] = 0;
                swapWithLastValue(container[key], i);
                if (container[key][0] == 0)
                {
                    auto newEnd = std::remove(hasValueContainer.begin(), hasValueContainer.end(), key);
                    hasValueContainer.erase(newEnd, hasValueContainer.end());
                }
                return true;
            }
        }
        // 超出散列冲突处理能力
        throw std::runtime_error("??");
    }

    void swapWithLastValue(int *container, int swapIndex)
    {
        for (int i = 9; i > swapIndex; --i)
        {
            if (container[i] != 0)
            {
                int temp = container[i];
                container[i] = container[swapIndex];
                container[swapIndex] = temp;
            }
        }
    }
    int getRandom()
    {
        if (hasValueContainer.size() == 0)
        {
            return 0;
        }
        int randomIndex = rand() % hasValueContainer.size();
        int key = hasValueContainer[randomIndex];
        return container[key][0];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
