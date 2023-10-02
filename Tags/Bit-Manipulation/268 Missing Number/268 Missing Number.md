# 268. Missing Number

Careful: Yes
Date: October 2, 2023
Difficulty: Easy
Elegant Code (Template): Bit-Manipulation, XOR
Index: 268
Programming Language: C++
Skills: 1.a^a = 0, a^0 = a
Tags: Bit-Manipulation
Link: https://leetcode.com/problems/missing-number/

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            res ^= i+1;
            res ^= nums[i];
        }
        return res;
    }
};
```