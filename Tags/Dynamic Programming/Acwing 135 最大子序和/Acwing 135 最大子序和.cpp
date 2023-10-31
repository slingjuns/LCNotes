// Date: October 31, 2023
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // dp[i] = prefix[i] - min(prefix[i-1], prefix[i-2],...prefix[i-k])
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
