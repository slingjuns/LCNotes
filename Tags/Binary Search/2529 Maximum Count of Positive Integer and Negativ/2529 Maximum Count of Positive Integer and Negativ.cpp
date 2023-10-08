// Date: October 8, 2023
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // binary search
        auto g_zero = upper_bound(nums.begin(), nums.end(), 0);
        auto e_zero = lower_bound(nums.begin(), nums.end(), 0);
        int neg_count = e_zero-nums.begin(), pos_count = nums.end()-g_zero;
        return max(neg_count, pos_count);
    }
};
