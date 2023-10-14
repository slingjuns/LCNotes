// Date: October 14, 2023
class Solution {
public:
    long long beautifulSubarrays(const vector<int>& A) {
        unordered_map<int, vector<int>> dp{{0, {-1}}};
        long long res = 0, pre = 0;
        for (int i = 0; i < A.size(); ++i) {
            int a = A[i];
            pre ^= a;
            auto it = dp[pre].end();
            // 0, 2, 4  i = 5, so we look for 0, 2 
            res += it-dp[pre].begin();
            dp[pre].push_back(i);
        }
        return res;
}
};
