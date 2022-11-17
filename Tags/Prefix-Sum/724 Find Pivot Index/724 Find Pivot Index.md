# 724. Find Pivot Index

Careful: No
Date: November 17, 2022
Difficulty: Easy
Elegant Code (Template): Prefix-Sum, Suffix-Sum
Index: 724
Programming Language: C++
Skills: 1. Use partial_sum to precompute the prefix/suffix sum
Tags: Prefix-Sum, Suffix-Sum
Link: https://leetcode.com/problems/find-pivot-index/

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre(nums.size()), suf(nums.size());
        partial_sum(nums.begin(), nums.end(), pre.begin());
        partial_sum(nums.rbegin(), nums.rend(), suf.rbegin());

        for (int i = 0; i < nums.size(); ++i) {
            int left = i > 0 ? pre[i-1] : 0, right = i+1 < nums.size() ? suf[i+1] : 0;
            if (left == right) return i;
        }
        return -1;
    }
};
```