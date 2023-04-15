// Date: April 15, 2023
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int low_target = lower-nums[i];
            int up_target = upper-nums[i];
            auto left = lower_bound(nums.begin(), nums.end(), low_target);
            auto right = upper_bound(nums.begin(), nums.end(), up_target);
            res += right - left;
            if(low_target <= nums[i] && nums[i] <= up_target) {
                res -= 1;
            }
        }
        return res / 2;
    }
};
