# 935. Knight Dialer

Careful: No
Date: January 31, 2024
Difficulty: Medium
Index: 935
Programming Language: C++
Tags: Dynamic Programming
Link: https://leetcode.com/problems/knight-dialer/

```cpp
class Solution {
using LL = long long;
public:
    int knightDialer(int n) {
        const LL mod = 1e9+7;
        unordered_map<int, vector<int>> moves = {
            {1, {6, 8}},
            {2, {7, 9}},
            {3, {4, 8}},
            {4, {3, 9, 0}},
            {5, {}},
            {6, {1, 7, 0}},
            {7, {2, 6}},
            {8, {1, 3}},
            {9, {4, 2}},
            {0, {4, 6}}
        };
        LL res = 0;
        vector<vector<LL>> dp(n+1, vector<LL>(10));//moves with n length, ending in digit j
        for(int j = 0; j < dp[0].size(); ++j) dp[1][j] = 1;
        
        for(int i = 2; i < dp.size(); ++i) {
            for(int j = 0; j < dp[0].size(); ++j) {
                for(int move: moves[j]) {
                    dp[i][j] += dp[i-1][move]%mod;
                }
            }
        }
        
        // sum
        for(int j = 0; j < dp[0].size(); ++j) res += dp[n][j] % mod;
        
        return res % mod;
    }
};
```