# 135. Candy

Careful: Yes
Date: February 4, 2024
Difficulty: Hard
Elegant Code (Template): Greedy
Index: 135
Programming Language: C++
Skills: 1. Two pass distribution
Tags: Greedy
Link: https://leetcode.com/problems/candy/

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        vector<int>rets(n, 1);
        for (int i=1; i<n; i++)
        {
            if (ratings[i]>ratings[i-1])
                rets[i] = max(rets[i], rets[i-1]+1);
        }
        for (int i=n-2; i>=0; i--)
        {
            if (ratings[i]>ratings[i+1])
                rets[i] = max(rets[i], rets[i+1]+1);
        }
        int sum = accumulate(rets.begin(), rets.end(), 0);
        return sum;
    }
};
```

```
这在leetcode上是一道困难的题目，其难点就在于贪心的策略，如果在考虑局部的时候想两边兼顾，就会顾此失彼。

那么本题我采用了两次贪心的策略：

一次是从左到右遍历，只比较右边孩子评分比左边大的情况。
一次是从右到左遍历，只比较左边孩子评分比右边大的情况。
这样从局部最优推出了全局最优，即：相邻的孩子中，评分高的孩子获得更多的糖果
```