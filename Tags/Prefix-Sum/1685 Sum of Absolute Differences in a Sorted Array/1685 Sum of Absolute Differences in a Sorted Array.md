# 1685. Sum of Absolute Differences in a Sorted Array

Careful: No
Date: February 4, 2024
Difficulty: Medium
Index: 1685
Programming Language: C++
Tags: Prefix-Sum
Link: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

```cpp
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // prefix sum
        int N = nums.size();
        nums.insert(nums.begin(), -1);
        vector<int> pre(N+1), res;
        for(int i = 1; i < nums.size(); ++i) {
            pre[i] = pre[i-1] + nums[i];
        }
        
        for(int i = 1; i < nums.size(); ++i) {
            int left_sum = i*nums[i] - pre[i];
            int right_sum = (pre[N]-pre[i]) - (N-i) * nums[i];
            res.push_back(left_sum + right_sum);
        }
        return res;
    }
};
```