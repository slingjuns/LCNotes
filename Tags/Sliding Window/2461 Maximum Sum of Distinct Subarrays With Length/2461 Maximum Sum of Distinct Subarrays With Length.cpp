// Date: October 30, 2023
class Solution {
using LL = long long;
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0;
        unordered_map<int, int> window;
        LL res = 0, win_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // push into the window
            win_sum += nums[i];
            window[nums[i]]++;
            if(i-l+1 > k) {
                win_sum -= nums[l];
                if(window[nums[l]] == 1) window.erase(nums[l]);
                else window[nums[l]]--;
                l++;
            }
           
            if(window.size() == k) res = max(win_sum, res);
        }
        return res;
    }
};
