// Date: February 1, 2024
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // cyclic sort
        for(int i = 0; i < nums.size(); ++i) {
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]) 
                swap(nums[i], nums[nums[i]-1]);
        }
        
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] != i+1) return nums[i];
        return -1;
    }
};
