// Date: April 14, 2023
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int, int> cache;
        long long res = 0;
        long long total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int target = nums[i] - i;
            res += cache[target];
            cache[target]++;
            total += nums.size()-1-i;
        }
        
        return total - res;
    }
};
