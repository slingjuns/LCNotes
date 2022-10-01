// Date: October 1, 2022
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix sum
        map<int, int> cache{{0,1}}; // prefix sum -> count
        vector<int> prefix(nums.size());
        int res = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i] += sum + nums[i];
            sum = prefix[i];
            int target = sum-k;
            res += cache[target];
            cache[prefix[i]]++;
        }
        return res;
    }
};
