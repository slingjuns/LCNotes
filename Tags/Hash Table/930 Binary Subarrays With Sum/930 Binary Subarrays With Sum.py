// Date: April 11, 2023
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // prefix sum with count
        map<int, int> pref2count;
        pref2count[0] = 1;
        int res = 0;
        int cursum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            cursum += nums[i];
            int target = cursum - goal;
            res += pref2count[target];
            pref2count[cursum]++;
        }
        return res;
    }
};
