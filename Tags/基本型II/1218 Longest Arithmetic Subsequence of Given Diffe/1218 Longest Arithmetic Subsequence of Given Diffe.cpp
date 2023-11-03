// Date: November 3, 2023
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> m;
        vector<int> dp(arr.size(), 1);
        int res = 1;
        for(int i = 0; i < dp.size(); ++i) {
            if(m.count(arr[i]-diff)) dp[i] = max(dp[m[arr[i]-diff]]+1, dp[i]);
            m[arr[i]] = i;
            res = max(res, dp[i]);
        }
        return res;
    }
};
