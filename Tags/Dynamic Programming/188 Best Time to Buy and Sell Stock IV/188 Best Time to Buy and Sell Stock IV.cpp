// Date: September 25, 2022
class Solution {
private:
    int res = 0;
public:
    int maxProfit(int k, vector<int>& prices) {
        int max_k = k;
        // dp[i][Transactions][2] -- 
        vector<vector<vector<int>>> dp(prices.size(), 
                                      vector<vector<int>>(max_k+1, 
                                      vector<int>(2)));  
        
        for(int i = 0; i < dp.size(); ++i) { // O(n*2)
            auto price = prices[i];
            for(int j = 1; j < max_k+1; ++j) {
                if(i == 0) { // base case
                    dp[i][j][0] = 0;
                    dp[i][j][1] -= price;
                } else {
                    // not holding the stock until ith day
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+price);
                    // holding the stock until ith day
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-price);
                    res = max(res, max(dp[i][j][0], dp[i][j][1]));
                }
            }
        }
        
        return res;
    }
    
};
