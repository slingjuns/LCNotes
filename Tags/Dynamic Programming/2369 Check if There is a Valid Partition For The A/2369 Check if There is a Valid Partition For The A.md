# 2369. Check if There is a Valid Partition For The Array

Careful: Yes
Date: October 26, 2023
Difficulty: Medium
Index: 2369
Programming Language: C++
Skills: 1. 不是区间dp, 因为数组大小固定长度
Tags: Dynamic Programming, 基本型II
Link: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

```cpp
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        // not 区间dp
        int n = nums.size();
        vector<bool> dp(n+1); // 
        dp[0] = true;
        
        for(int i = 1; i < dp.size(); ++i) {
            auto index = i-1;
			if(index-1 >= 0)
		            dp[i] = nums[index-1]==nums[index] && dp[i-2];
            if(index-2 >= 0) { // subarrays with 3 elements
                dp[i] = dp[i] || (nums[index-2]==nums[index-1] && nums[index-1]==nums[index] && dp[i-3]);
                dp[i] = dp[i] || (nums[index-2]+1==nums[index-1] && nums[index-1]==nums[index]-1 && dp[i-3]);
            }
        }
        return dp[n];
    }
};
```