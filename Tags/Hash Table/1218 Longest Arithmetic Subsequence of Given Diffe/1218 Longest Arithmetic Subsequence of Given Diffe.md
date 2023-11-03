# 1218. Longest Arithmetic Subsequence of Given Difference

Careful: No
Date: November 3, 2023
Difficulty: Medium
Elegant Code (Template): Dynamic Programming, Hash Table, 基本型II
Index: 1218
Programming Language: C++
Skills: 1. hash table 记录index位置 + 基本型dp
Tags: Dynamic Programming, Hash Table, 基本型II
Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> m;
        vector<int> dp(arr.size(), 1);
        int res = 1;
        for(int i = 0; i < dp.size(); ++i) {
            if(m.count(arr[i]-diff)) dp[i] = max(dp[m[arr[i]-diff]]+1, dp[i]);
            m[arr[i]] = i;
            res = max(res, dp[i]);
        }
        return res;
    }
};
```