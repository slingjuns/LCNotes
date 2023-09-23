# 300. Longest Increasing Subsequence

Careful: Yes
Date: September 23, 2023
Difficulty: Medium
Elegant Code (Template): Dynamic Programming, LIS
Index: 300
Programming Language: C++
Tags: Dynamic Programming, LIS
Link: https://leetcode.com/problems/longest-increasing-subsequence/

```jsx
class Solution {
private:
    int res = 1;
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        
        for(int i = 0; i < dp.size(); ++i) {
            for(int j = i; j >= 0; j--) {
                if(nums[j] >= nums[i]) continue;
                dp[i] = max(dp[i], dp[j]+1);
                res = max(res, dp[i]);
            }
        }
        
        return res;
    }
};
```

[https://leetcode.com/problems/longest-increasing-subsequence/](https://leetcode.com/problems/longest-increasing-subsequence/)