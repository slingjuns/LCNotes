// Date: September 23, 2023
class Solution {
public:
    int countOnes(const string& str) {
        int res = 0;
        for(auto ch: str) {
            if(ch == '1') res++;
        }
        return res;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        
        for(int i = 1; i < strs.size()+1; ++i) {
            string cur = strs[i-1];
            int ones = countOnes(cur), zeros = cur.length()-ones;
            for(int j = 0; j < m+1; j++) {
                for(int k = 0; k < n+1; k++) {
                    if(j >= zeros && k >= ones) dp[i][j][k] = max(dp[i-1][j-zeros][k-ones]+1, dp[i-1][j][k]);   
                    else dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
        
        return dp.back()[m][n];
    }
};
