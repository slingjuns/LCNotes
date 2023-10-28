# 516. Longest Palindromic Subsequence

Careful: Yes
Date: October 28, 2023
Difficulty: Medium
Elegant Code (Template): Dynamic Programming, 区间DP
Index: 516
Programming Language: C++
Tags: Dynamic Programming, 区间DP
Link: https://leetcode.com/problems/longest-palindromic-subsequence/

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int N = s.size();
        s = "#" + s;
        auto dp = vector<vector<int>>(N+1,vector<int>(N+1,0));
        
        for (int i=1; i<=N; i++)
            dp[i][i] = 1;
        
        for (int len=2; len<=N; len++)
            for (int i=1; i+len-1<=N; i++)
            {                
                int j = i+len-1;
                if (s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        return dp[1][N];
    }
};
```