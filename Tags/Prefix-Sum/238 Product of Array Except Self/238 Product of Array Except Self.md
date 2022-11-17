# 238. Product of Array Except Self

Careful: No
Date: November 17, 2022
Difficulty: Medium
Index: 238
Programming Language: C++
Skills: 1. Prefix-sum and suffix-sum can be used together
Tags: Prefix-Sum, Suffix-Sum
Link: https://leetcode.com/problems/product-of-array-except-self/

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums), suf(nums), ans(size(nums));
        
        // prefix product
        int prod = 1;
        for (int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            pre[i] = prod;
        }
        // suffix product
        prod = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            prod *= nums[i];
            suf[i] = prod;
        }
        
        for(int i = 0; i < size(nums); i++)
            ans[i] = (i ? pre[i-1] : 1) * (i+1 < size(nums) ? suf[i+1] : 1);
        return ans;
    }
};
```