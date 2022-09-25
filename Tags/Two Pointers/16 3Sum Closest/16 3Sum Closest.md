# 16. 3Sum Closest

Careful: Yes
Date: September 25, 2022
Difficulty: Medium
Index: 16
Programming Language: C++
Skills: 1. Be careful about setting best sum will cause overflow; can store best difference instead;
Tags: Left-Right-Pointers, Two Pointers
Link: https://leetcode.com/problems/3sum-closest/

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // [-4, -1, 1, 2] -> sorted
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (i>0 && nums[i-1] == nums[i]) continue; // skip for duplicates
            int left = i+1, right = nums.size()-1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    left++;
                    if (abs(target-sum) < abs(diff)) diff = target-sum;
                } else if (sum > target) {
                    right--;
                    if (abs(target-sum) < abs(diff)) diff = target-sum;
                } else return sum;
            }
        }
        return target-diff;
    }
};
```