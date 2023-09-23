// Date: September 23, 2023
class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        // 0-1 knapsack
        vector<int> dp(budget+1, 0);
        
        for(int i = 0; i < present.size(); ++i) {
            for(int j = budget; j >= present[i]; --j) {
                auto profit = future[i]-present[i];
                dp[j] = max(dp[j], dp[j-present[i]]+profit);
            }
        }
        
        return dp.back();
    }
};
