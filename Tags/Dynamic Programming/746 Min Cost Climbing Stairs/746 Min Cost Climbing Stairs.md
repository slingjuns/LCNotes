# 746. Min Cost Climbing Stairs

Careful: No
Date: August 30, 2023
Difficulty: Easy
Index: 746
Programming Language: C++
Tags: Dynamic Programming
Link: https://leetcode.com/problems/min-cost-climbing-stairs/

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        dp[0] = dp[1] = 0;
        for(int i = 2; i < dp.size(); ++i) {
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp.back();
    }
};
```