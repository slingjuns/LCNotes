// Date: September 25, 2022
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            while (left <= right && nums[left] % 2 == 0) left++;
            while (left <= right && nums[right] % 2 != 0) right--;
            if (left < right) swap(nums[left], nums[right]);
        }
        return nums;
    }
};
