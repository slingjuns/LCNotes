# 2370. Longest Ideal Subsequence

Careful: No
Date: September 24, 2023
Difficulty: Medium
Index: 2370
Programming Language: C++
Tags: Dynamic Programming, LIS
Link: https://leetcode.com/problems/longest-ideal-subsequence/

```cpp
class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(s.length(), 1);
        unordered_map<char, int> prev;
        int res = 1;
        prev[s[0]] = 0;
        for (int i = 1; i < dp.size(); ++i) {
            for(int j = 0; j <= k; ++j) {
                char p_ch = s[i]+j, n_ch = s[i]-j;
                if(prev.count(p_ch)) dp[i] = max(dp[i], dp[prev[p_ch]] + 1);
                if(prev.count(n_ch)) dp[i] = max(dp[i], dp[prev[n_ch]] + 1);
            }
            res = max(res, dp[i]);
            prev[s[i]] = i;
        }
        
        return res;
    }
};
```