// Date: October 4, 2023
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // 0 < c < a + b
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) continue;
            for(int j = i+1; j < nums.size(); ++j) {
                auto ab = nums[i] + nums[j];
                auto it = lower_bound(nums.begin()+j+1, nums.end(), ab);
                res += max(0, (int)distance(nums.begin()+j+1, it));
            }
        }
        return res;
    }
};
