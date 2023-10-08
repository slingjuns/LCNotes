# 2529. Maximum Count of Positive Integer and Negative Integer

Careful: No
Date: October 8, 2023
Difficulty: Easy
Index: 2529
Programming Language: C++
Tags: Binary Search
Link: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

```cpp
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // binary search
        auto g_zero = upper_bound(nums.begin(), nums.end(), 0);
        auto e_zero = lower_bound(nums.begin(), nums.end(), 0);
        int neg_count = e_zero-nums.begin(), pos_count = nums.end()-g_zero;
        return max(neg_count, pos_count);
    }
};
```