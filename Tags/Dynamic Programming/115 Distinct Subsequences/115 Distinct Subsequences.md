# 115. Distinct Subsequences

Careful: No
Date: September 25, 2023
Difficulty: Hard
Elegant Code (Template): Dynamic Programming, Two Sequence
Index: 115
Programming Language: C++
Tags: Dynamic Programming, Two Sequence
Link: https://leetcode.com/problems/distinct-subsequences/

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(s.length()+1, vector<long long>(t.length()+1));
        for(int i = 0; i < dp.size(); ++i) { // initialization
            dp[i][0] = 1;
        }
        
        for(int i = 1; i < dp.size(); ++i) {
            for(int j = 1; j < dp[0].size(); ++j) {
                char s_ch = s[i-1], t_ch = t[j-1];
                if(s_ch != t_ch) dp[i][j] = dp[i-1][j];
                else {
                    dp[i][j] = min(LLONG_MAX/2, dp[i-1][j] + dp[i-1][j-1]);
                }
            }
        }
        return dp.back().back();
    }
};115. Distinct Subsequences
```