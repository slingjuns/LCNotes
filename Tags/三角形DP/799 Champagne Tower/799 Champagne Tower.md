# 799. Champagne Tower

Careful: No
Date: October 18, 2023
Difficulty: Medium
Elegant Code (Template): Dynamic Programming, Triangle
Index: 799
Programming Language: C++
Skills: 1. 数字三角形模型
Tags: Dynamic Programming, 三角形DP
Link: https://leetcode.com/problems/champagne-tower/

## DP - 1D

```cpp
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(101, 0.0);
        dp[1] = (double)poured;
        // START FROM INDEX 1
        // 1
        // 1,2
        // 1,2,3
        for(int i = 1; i <= query_row; i++) {
            for(int j = i+1; j > 0; j--) {
                dp[j] = max((dp[j]-1)/2.0, 0.0) + max((dp[j-1]-1)/2.0, 0.0); 
            }
        }
        
        return dp[query_glass+1] > 1 ? 1 : dp[query_glass+1];
    }
};
```