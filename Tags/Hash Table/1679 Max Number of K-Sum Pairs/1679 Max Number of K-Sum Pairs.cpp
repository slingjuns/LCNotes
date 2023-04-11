// Date: April 11, 2023
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> cache;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int target = k - nums[i];
            if (cache[target]) {
                ans++;
                cache[target]--;
            }
            else cache[nums[i]]++;
        }
        return ans;
    }
};
