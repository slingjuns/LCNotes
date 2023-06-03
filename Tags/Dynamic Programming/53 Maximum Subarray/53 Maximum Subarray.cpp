// Date: June 3, 2023
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);  // 以nums[i]结尾的最大子数组之和为dp[i]
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1], 0) + nums[i];
        }
        
        // res
        return *max_element(dp.begin(), dp.end());
    }
};
