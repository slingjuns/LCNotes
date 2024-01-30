// Date: January 30, 2024
class Solution {
using LL = long long;
const LL mod = 1e9+7;
public:
    int maxSumMinProduct(vector<int>& nums) {
        // look for next smaller + prev smaller
        deque<int> dq;
        LL res = 0;
        vector<LL> preSum(nums.size()+1);
        for(int i = 1; i < preSum.size(); ++i) preSum[i] = preSum[i-1] + nums[i-1] % mod; 
        copy(preSum.begin(), preSum.end(), ostream_iterator<int>(cout, ";"));
        
        nums.push_back(INT_MIN);
        for(int i = 0; i < nums.size(); ++i) {
            while(!dq.empty() && nums[dq.back()] >= nums[i]) {
                // current element is dq.back();
                int cur_i = dq.back();
                // right boundary = i
                dq.pop_back();
                // left boundary 
                int r = i, l = dq.empty() ? -1 : dq.back();
                LL min_prod = (preSum[r]-preSum[l+1])* (LL)nums[cur_i];
                res = max(min_prod, res);
            }
            dq.push_back(i);
        }
        return res % mod;
    }
};
