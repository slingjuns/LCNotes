// Date: October 18, 2023
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(101, 0.0);
        dp[1] = (double)poured;
        // START FROM INDEX 1
        // 1
        // 1,2
        // 1,2,3
        for(int i = 1; i <= query_row; i++) {
            for(int j = i+1; j > 0; j--) {
                dp[j] = max((dp[j]-1)/2.0, 0.0) + max((dp[j-1]-1)/2.0, 0.0); 
            }
        }
        
        return dp[query_glass+1] > 1 ? 1 : dp[query_glass+1];
    }
};
