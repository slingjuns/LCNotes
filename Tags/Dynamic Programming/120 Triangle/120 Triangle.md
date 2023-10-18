# 120. Triangle

Careful: No
Date: October 18, 2023
Difficulty: Medium
Elegant Code (Template): Dynamic Programming, Triangle
Index: 120
Programming Language: C++
Skills: 1. 数字三角形经典题
Tags: Dynamic Programming, 三角形DP
Link: https://leetcode.com/problems/triangle/

## DP — 1D

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back().size()+1, 1e4+1); // start from index 1
        dp[1] = triangle[0][0];
        for(int i = 1; i < triangle.size(); ++i) {
            for(int j = i+1; j > 0; --j) {
                dp[j] = min(dp[j], dp[j-1]) + triangle[i][j-1];
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};
```