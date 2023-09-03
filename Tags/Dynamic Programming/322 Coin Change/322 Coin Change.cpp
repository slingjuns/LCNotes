// Date: September 2, 2023
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount + 1); 
        dp[0] = 0;
        
        for(int i = 0; i < coins.size(); ++i){
            for(int j = coins[i]; j <= amount; ++j){
                dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
        }

        return dp.back() > amount ? -1 : dp.back();
    }
};