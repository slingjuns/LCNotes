// Date: February 1, 2024
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // cyclic sort
        for(int i = 0; i < nums.size(); ++i) {
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]) 
                swap(nums[i], nums[nums[i]-1]);
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] != i+1) res.push_back(nums[i]);
        return res;
    }
};
