// Date: April 14, 2023
class Solution {
public:
    int atMostK(vector<int> &nums, int k) { // subarrays with at most K diff
        int l = 0, res = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]]++;
            while(count.size() > k) {
                count[nums[l]]--;
                if(count[nums[l]] == 0) count.erase(nums[l]);
                l++;
            }
            res += i-l+1;
        }
        return res;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k-1);
    }
};
