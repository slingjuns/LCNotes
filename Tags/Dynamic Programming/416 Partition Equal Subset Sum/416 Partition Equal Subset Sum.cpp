// Date: September 23, 2023
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        vector<bool> dp(sum/2+1, false);
        dp[0] = true;
        
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = sum/2; j >= nums[i]; --j) {
                dp[j] = dp[j-nums[i]] || dp[j];
            }
        }
        
        return sum % 2 == 0 ? dp[sum/2] : false;
    }
};
