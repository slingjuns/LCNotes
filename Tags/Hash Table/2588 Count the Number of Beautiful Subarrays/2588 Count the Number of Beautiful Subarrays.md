# 2588. Count the Number of Beautiful Subarrays

Careful: Yes
Date: October 14, 2023
Difficulty: Medium
Index: 2588
Programming Language: C++
Skills: 1. 此题可转换为number of sub arrays with xor = 0
Tags: Hash Table, Prefix-Sum
Link: https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/

```cpp
class Solution {
public:
    long long beautifulSubarrays(const vector<int>& A) {
        unordered_map<int, vector<int>> dp{{0, {-1}}};
        long long res = 0, pre = 0;
        for (int i = 0; i < A.size(); ++i) {
            int a = A[i];
            pre ^= a;
            auto it = dp[pre].end();
            // 0, 2, 4  i = 5, so we look for 0, 2 
            res += it-dp[pre].begin();
            dp[pre].push_back(i);
        }
        return res;
}
};
```