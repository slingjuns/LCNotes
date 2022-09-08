// Date: September 8, 2022
class Solution {
public:
    bool canJump(vector<int>& nums) {
        size_t max_reach = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i > max_reach) return false;
            max_reach = max(max_reach, nums[i]+i);
            if (max_reach >= nums.size()-1) return true;
        }
        return true;
    }
};
