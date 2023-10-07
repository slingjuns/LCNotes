// Date: October 7, 2023
class Solution {
private:
    vector<int> dp;
public:
    vector<int> countBits(int n) {
        dp.resize(n+1);
        for(int i = 1; i < dp.size(); ++i) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};
