# 198. House Robber

Careful: No
Date: May 25, 2023
Difficulty: Medium
Index: 198
Programming Language: C++
Tags: Dynamic Programming, 基本型I
Link: https://leetcode.com/problems/house-robber/

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for(int i = 1; i < dp.size(); ++i) {
            if(i >= 2) dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
            else dp[i] = max(dp[i-1], nums[i]);
        }
        
        return dp.back();
    }
};
```