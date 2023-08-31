# 70. Climbing Stairs

Careful: No
Date: August 31, 2023
Difficulty: Easy
Index: 70
Programming Language: C++
Tags: Dynamic Programming
Link: https://leetcode.com/problems/climbing-stairs/

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
         return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
         dp[i]=dp[i-1]+dp[i-2];
        
        return dp[n];
    }
};

```