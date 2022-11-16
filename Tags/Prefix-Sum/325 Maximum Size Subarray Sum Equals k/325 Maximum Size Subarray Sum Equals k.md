# 325. Maximum Size Subarray Sum Equals k

Careful: Yes
Date: November 16, 2022
Difficulty: Medium
Index: 325
Programming Language: C++
Tags: Prefix-Sum
Link: https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

```go
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        // [-2, -1, 2, 1] -> {-2:0, -3:1, -1:2, 0:3}
        map<int, int> prefix_map = {{0,-1}};  // prefix-sum -> occurrences
        long long cur_sum = 0;
        int max_arr = 0;
        // nums[0] + ... + nums[i] = cur_sum == (k + cur_sum - k)
        for (int i = 0; i < nums.size(); ++i) {
            cur_sum += nums[i];
            if (!prefix_map.count(cur_sum)) {
                prefix_map[cur_sum] = i;
            }
            long long target = cur_sum - k;
            if (prefix_map.count(target)) {
                max_arr = max(max_arr, i-prefix_map[target]);
            }
        }
        return max_arr;
    }
};
```