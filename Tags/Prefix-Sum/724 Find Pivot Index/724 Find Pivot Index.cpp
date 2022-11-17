// Date: November 17, 2022
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre(nums.size()), suf(nums.size());
        partial_sum(nums.begin(), nums.end(), pre.begin());
        partial_sum(nums.rbegin(), nums.rend(), suf.rbegin());

        for (int i = 0; i < nums.size(); ++i) {
            int left = i > 0 ? pre[i-1] : 0, right = i+1 < nums.size() ? suf[i+1] : 0;
            if (left == right) return i;
        }
        return -1;
    }
};
