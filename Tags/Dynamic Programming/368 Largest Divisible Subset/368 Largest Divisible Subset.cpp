// Date: June 7, 2023
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size(), 0); // 截止到i元素为止，含有ith 元素的最大divisible subset
        vector<int> prev(nums.size(), -2);
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        prev[0] = -1;
        for(int i = 1; i < nums.size(); ++i) {
            for(int j = i; j >= 0; --j) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        prev[i] = j;
                    }
                } 
            }
        }
        int index = max_element(dp.begin(), dp.end()) - dp.begin();
        int count = *max_element(dp.begin(), dp.end());
        vector<int> res;
        while(count > 0) {
            res.push_back(nums[index]);
            index = prev[index];
            count--;
        }
        return res;
    }
};
