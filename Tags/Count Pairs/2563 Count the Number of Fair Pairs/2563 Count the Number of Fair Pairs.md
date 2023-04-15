# 2563. Count the Number of Fair Pairs

Careful: Yes
Date: April 15, 2023
Difficulty: Medium
Elegant Code (Template): Count Pairs
Index: 2563
Programming Language: C++
Tags: Count Pairs
Link: https://leetcode.com/problems/count-the-number-of-fair-pairs/

```cpp
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int low_target = lower-nums[i];
            int up_target = upper-nums[i];
            auto left = lower_bound(nums.begin(), nums.end(), low_target);
            auto right = upper_bound(nums.begin(), nums.end(), up_target);
            res += right - left;
            if(low_target <= nums[i] && nums[i] <= up_target) {
                res -= 1;
            }
        }
        return res / 2;
    }
};
```