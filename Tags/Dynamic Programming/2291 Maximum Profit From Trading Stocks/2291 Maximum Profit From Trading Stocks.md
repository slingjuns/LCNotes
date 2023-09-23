# 2291. Maximum Profit From Trading Stocks

Careful: No
Date: September 23, 2023
Difficulty: Medium
Index: 2291
Programming Language: C++
Tags: Dynamic Programming, 背包
Link: https://leetcode.com/problems/maximum-profit-from-trading-stocks/

```cpp
class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        // 0-1 knapsack
        vector<int> dp(budget+1, 0);
        
        for(int i = 0; i < present.size(); ++i) {
            for(int j = budget; j >= present[i]; --j) {
                auto profit = future[i]-present[i];
                dp[j] = max(dp[j], dp[j-present[i]]+profit);
            }
        }
        
        return dp.back();
    }
};
```