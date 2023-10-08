// Date: October 8, 2023
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // LCS - longest common subsequence
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1));
        for(int i = 1; i < dp.size(); ++i) {
            for(int j = 1; j < dp[0].size(); ++j) {
                auto n1 = i-1, n2 = j-1;
                if(nums1[n1] == nums2[n2]) dp[i][j] = dp[i-1][j-1] + 1;
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp.back().back();
    }
};
