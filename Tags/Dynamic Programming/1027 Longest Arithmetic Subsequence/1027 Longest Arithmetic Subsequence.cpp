// Date: October 27, 2023
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
