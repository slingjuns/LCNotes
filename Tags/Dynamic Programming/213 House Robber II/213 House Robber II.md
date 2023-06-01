# 213. House Robber II

Careful: No
Date: June 1, 2023
Difficulty: Medium
Index: 213
Programming Language: C++
Tags: Dynamic Programming, 基本型I
Link: https://leetcode.com/problems/house-robber-ii/

```cpp
class Solution {
public:
    int rob_helper(vector<int>& nums, int begin, int end) {
        vector<vector<int>> dp(end-begin, vector<int>(2, 0));
        dp[0][1] = nums[begin];
        dp[0][0] = 0;
        for(int i = 1; i < end-begin; ++i) {
            dp[i][1] = dp[i-1][0] + nums[i+begin];
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
        }
        return max(dp[end-begin-1][0], dp[end-begin-1][1]);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(rob_helper(nums, 1, nums.size()), rob_helper(nums, 0, nums.size()-1));
    }
    
    
};
```