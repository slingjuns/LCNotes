// Date: February 4, 2024
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // prefix sum
        int N = nums.size();
        nums.insert(nums.begin(), -1);
        vector<int> pre(N+1), res;
        for(int i = 1; i < nums.size(); ++i) {
            pre[i] = pre[i-1] + nums[i];
        }
        
        for(int i = 1; i < nums.size(); ++i) {
            int left_sum = i*nums[i] - pre[i];
            int right_sum = (pre[N]-pre[i]) - (N-i) * nums[i];
            res.push_back(left_sum + right_sum);
        }
        return res;
    }
};
