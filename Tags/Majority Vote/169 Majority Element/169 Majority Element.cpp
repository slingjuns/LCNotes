// Date: May 23, 2023
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int group = nums[0], count = 1;
        for(int i = 1; i < nums.size(); ++i) {
            auto cur = nums[i];
            if(count == 0) {
                group = nums[i];
                count++;
                continue;
            }
            if(cur == group) count++;
            else count--;
        }
        return group;
    }
};
