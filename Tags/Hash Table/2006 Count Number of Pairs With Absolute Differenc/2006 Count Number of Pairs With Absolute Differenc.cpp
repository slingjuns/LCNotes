// Date: April 13, 2023
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        // no sorting
        unordered_map<int, int> count;
        int res = 0;
        for(auto num: nums) count[num]++;
        
        for (int i = 0; i < nums.size(); ++i) {
            int target = nums[i] - k;
            if(target == nums[i]) res += count[target]-1;
            else res += count[target];
        }
        return res;
    }
};
