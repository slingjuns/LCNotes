# 611. Valid Triangle Number

Careful: Yes
Date: October 4, 2023
Difficulty: Medium
Index: 611
Programming Language: C++
Tags: Binary Search, Two Pointers
Link: https://leetcode.com/problems/valid-triangle-number/

```cpp
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // 0 < c < a + b
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) continue;
            for(int j = i+1; j < nums.size(); ++j) {
                auto ab = nums[i] + nums[j];
                auto it = lower_bound(nums.begin()+j+1, nums.end(), ab);
                res += max(0, (int)distance(nums.begin()+j+1, it));
            }
        }
        return res;
    }
};
```