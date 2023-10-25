// Date: October 25, 2023
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = n % 2 == 0 ? (nums[n/2-1]+nums[n/2]) / 2 : nums[n/2];
        
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            res += abs(nums[i] - median);
        }
        return res;
    }
};
