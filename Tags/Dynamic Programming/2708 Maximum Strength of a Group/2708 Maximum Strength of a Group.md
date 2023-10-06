# 2708. Maximum Strength of a Group

Careful: Yes
Date: October 6, 2023
Difficulty: Medium
Index: 2708
Programming Language: C++
Skills: 1. Similar to Max Product Array, but is subsequence instead of subarray
Tags: Dynamic Programming
Link: https://leetcode.com/problems/maximum-strength-of-a-group/

```cpp
using LL = long long;
class Solution {
public:
    LL maxStrength(vector<int>& nums) 
    {
        LL minP = nums[0], maxP = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            auto cur = nums[i];
            vector<LL> tmp = {cur, cur * minP, cur * maxP};
            minP = min(minP, *min_element(tmp.begin(), tmp.end()));
            maxP = max(maxP, *max_element(tmp.begin(), tmp.end()));
        }
        return maxP;
    }
};
```