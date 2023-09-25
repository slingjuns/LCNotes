// Date: September 25, 2023
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, 0));
        
        for(int i = 1; i < dp.size(); ++i) {
            for(int j = 1; j < dp[0].size(); ++j) {
                char t1 = text1[i-1], t2 = text2[j-1];
                if(t1 == t2) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                else dp[i][j] = max(dp[i][j], max(dp[i][j-1], dp[i-1][j]));
            }
        }
        
        return dp.back().back();
    }
};
