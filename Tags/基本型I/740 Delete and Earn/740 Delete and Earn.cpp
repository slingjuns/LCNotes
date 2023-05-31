// Date: May 31, 2023
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> gain(1e4+1, 0);
        for (int x:nums)  gain[x]+=x;
        vector<vector<int>> dp(gain.size(), vector<int>(2, 0)); // 0 for not-delete, 1 for delete
        dp[0][0] = 0;
        dp[0][1] = gain[0];
        for(int i = 1; i < gain.size(); ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + gain[i];
        }
        
        return max(dp[gain.size()-1][0], dp[gain.size()-1][1]);
    }
};740. Delete and Earn
