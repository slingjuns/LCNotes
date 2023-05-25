// Date: May 25, 2023
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // valid为多状态  positive-negative or negative-positive
        // dp0[i] 到index i为止结尾为positive, dp1[i] 表示结尾为negative
        int dp0[nums.size()], dp1[nums.size()];
        dp0[0] = dp1[0] = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] - nums[i-1] > 0) { // positive
                dp0[i] = dp1[i-1] + 1;
                dp1[i] = dp1[i-1];
            } else if (nums[i] - nums[i-1] < 0){ // negative
                dp0[i] = dp0[i-1];
                dp1[i] = dp0[i-1] + 1;
            } else {
                dp0[i] = dp0[i-1];
                dp1[i] = dp1[i-1];
            }
        }
        return max(dp0[nums.size()-1], dp1[nums.size()-1]);
    }
};
