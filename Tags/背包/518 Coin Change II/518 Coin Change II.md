# 518. Coin Change II

Careful: No
Date: September 3, 2023
Difficulty: Medium
Index: 518
Programming Language: C++
Tags: Dynamic Programming, 背包
Link: https://leetcode.com/problems/coin-change-ii/

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < coins.size(); ++i) {
            for(int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j-coins[i]];
            }
        }
        
        return dp.back();
    }
};
```