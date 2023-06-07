// Date: June 7, 2023
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // dp[i] 到ith 元素为止的max sum
        vector<int> dp(arr.size()+1, 0);
        arr.insert(arr.begin(), 0);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j <= k; j++) { // j个元素跟ith 元素一组
                int prev = i-j;
                if (prev < 0) break;
                int max_v = *max_element(arr.begin()+i-j+1, arr.begin()+i+1);
                dp[i] = max(dp[prev]+max_v * j, dp[i]);
            }
        }
        return dp.back();
    }
};
