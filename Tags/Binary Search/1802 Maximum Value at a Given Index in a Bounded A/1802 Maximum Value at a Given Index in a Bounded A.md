# 1802. Maximum Value at a Given Index in a Bounded Array

Careful: Yes
Date: November 3, 2023
Difficulty: Medium
Elegant Code (Template): Array, Binary Search
Index: 1802
Programming Language: C++
Skills: 1. 如何计算index的计算 是需要注意细节
Tags: Binary Search
Link: https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

```cpp
class Solution {
public:
    bool test(long h, long n, long index, int maxSum)
    {
        long sum = 0;
        // i prev to index
        if (h > index)
        {
            sum += (h-index + h)*(index+1)/2;
        }
        else
        {
            sum += (1+h)*h/2;
            sum += index+1-h;
        }
        // i after index
        if (index + h - 1 < n)
        {
            sum += (h + 1)*h/2;
            sum += (n - (index+h));
        }
        else
        {
            sum += (h + (h-(n-1-index))) * (n-index) / 2;
        }
        return (sum-h) <= maxSum;
    }
    
    int maxValue(int n, int index, int maxSum) {
        // [1,1,1,1,1,1] => binary search
        // [2,3,2,1,1,1]
        int l = 1, r = maxSum;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if(test(mid, n, index, maxSum)) l = mid;
            else r = mid-1;
        }
        return l;
    }
};
```