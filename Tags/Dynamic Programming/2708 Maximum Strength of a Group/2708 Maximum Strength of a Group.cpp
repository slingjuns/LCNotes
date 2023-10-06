// Date: October 6, 2023
using LL = long long;
class Solution {
public:
    LL maxStrength(vector<int>& nums) 
    {
        LL minP = nums[0], maxP = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            auto cur = nums[i];
            vector<LL> tmp = {cur, cur * minP, cur * maxP};
            minP = min(minP, *min_element(tmp.begin(), tmp.end()));
            maxP = max(maxP, *max_element(tmp.begin(), tmp.end()));
        }
        return maxP;
    }
};
