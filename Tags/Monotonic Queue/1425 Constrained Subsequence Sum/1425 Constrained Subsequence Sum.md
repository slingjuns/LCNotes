# 1425. Constrained Subsequence Sum

Careful: Yes
Date: October 31, 2023
Difficulty: Hard
Elegant Code (Template): Dynamic Programming, Monotonic Queue
Index: 1425
Programming Language: C++
Tags: Dynamic Programming, Monotonic Queue
Link: https://leetcode.com/problems/constrained-subsequence-sum/

```cpp
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // dp[i] 以ith element 结尾的元素最大subsequence sum
        // dp[i] = max(dp[i-1], dp[i-2],...dp[i-k]) + nums[i]
        vector<int> dp(nums.size(),0);
        deque<int> q; // store index
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            if(!q.empty() && i - q.front() > k) q.pop_front();
            dp[i] = nums[i];
            if (q.size()>0) dp[i] = max(dp[i], dp[q.front()] + nums[i]);       
            while(!q.empty() && dp[q.back()] <= dp[i]) q.pop_back();
            q.push_back(i);
            res = max(res, dp[i]);
        }
        
        return res;
    }
};
```