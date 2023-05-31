# 2361. Minimum Costs Using the Train Line

Careful: No
Date: May 31, 2023
Difficulty: Hard
Index: 2361
Programming Language: C++
Tags: Dynamic Programming, 基本型I
Link: https://leetcode.com/problems/minimum-costs-using-the-train-line/

```cpp
class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        long long dp[100001][2];
        regular.insert(regular.begin(), 0);
        express.insert(express.begin(), 0);
        dp[0][0] = 0;
        dp[0][1] = expressCost;
        
        vector<long long>rets;        
        
        for (int i=1; i<regular.size(); i++)
        {
            dp[i][0] = min(dp[i-1][0] + regular[i], dp[i-1][1] + regular[i]);
            dp[i][1] = min(dp[i-1][1] + express[i], dp[i-1][0] + expressCost + express[i]);
                        
            rets.push_back(min(dp[i][0], dp[i][1]));                
        }
        
        return rets;
    }
};
```