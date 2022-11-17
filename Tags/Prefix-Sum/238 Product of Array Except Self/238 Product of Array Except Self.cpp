// Date: November 17, 2022
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums), suf(nums), ans(size(nums));
        
        // prefix product
        int prod = 1;
        for (int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            pre[i] = prod;
        }
        // suffix product
        prod = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            prod *= nums[i];
            suf[i] = prod;
        }
        
        for(int i = 0; i < size(nums); i++)
            ans[i] = (i ? pre[i-1] : 1) * (i+1 < size(nums) ? suf[i+1] : 1);
        return ans;
    }
};
