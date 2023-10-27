# 1027. Longest Arithmetic Subsequence

Careful: No
Date: October 27, 2023
Difficulty: Medium
Index: 1027
Programming Language: C++
Skills: 1. dp初始值设置为1， 代表以ith element结尾任何diff的arithmetic subsequence 长度至少为1
Tags: Dynamic Programming, 基本型II
Link: https://leetcode.com/problems/longest-arithmetic-subsequence/

```cpp
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // dp[i][1001] // 最大差值500， +- -500，-499, -498...0
        
        vector<vector<int>> dp(nums.size()+1, vector<int>(1001, 1));

        int res = 0;
        for(int i = 1; i < dp.size(); ++i) {
            for(int j = 1; j < i; ++j) {
                int diff = nums[i-1]-nums[j-1], diff_index = diff+500;
                // 以ith element 结尾的差值为diff的最长子序列
                dp[i][diff_index] = max(dp[i][diff_index], dp[j][diff_index]+1);
                res = max(res, dp[i][diff_index]);
            }
        }
        return res;
    }
};
```