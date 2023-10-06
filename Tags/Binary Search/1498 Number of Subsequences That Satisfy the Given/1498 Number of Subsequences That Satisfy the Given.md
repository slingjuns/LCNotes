# 1498. Number of Subsequences That Satisfy the Given Sum Condition

Careful: Yes
Date: October 6, 2023
Difficulty: Medium
Index: 1498
Programming Language: C++
Tags: Binary Search, Two Pointers
Link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

```cpp
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        long mod = 1e9+7;
        sort(nums.begin(), nums.end());
        long long res = 0;
        vector<int> pows(nums.size(), 1);
        for (int i = 1 ; i < nums.size() ; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        for(int i = 0; i < nums.size(); ++i) {
            // a + nums[i] <= target -> a <= target - nums[i]
            auto it = upper_bound(nums.begin()+i, nums.end(), target-nums[i]);
            auto index = it-nums.begin()-1;
            if(index < i) continue; // no a satisfied the equation
            long long count = pows[index-i];
            res = res + count % mod;
        }
        return res % mod;
    }
};
```