// Date: October 8, 2023
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max((i-j)*j, dp[i-j]*j));
            }
        }
        return dp[n];
    }
};
