# 343. Integer Break

Careful: Yes
Date: October 8, 2023
Difficulty: Medium
Index: 343
Programming Language: C++
Tags: Dynamic Programming, 基本型II
Link: https://leetcode.com/problems/integer-break/

```cpp
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max((i-j)*j, dp[i-j]*j));
            }
        }
        return dp[n];
    }
};
```