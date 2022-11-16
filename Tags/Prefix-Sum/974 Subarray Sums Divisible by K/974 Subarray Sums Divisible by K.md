# 974. Subarray Sums Divisible by K

Careful: Yes
Date: November 16, 2022
Difficulty: Medium
Elegant Code (Template): Hash Table, Prefix-Sum
Index: 974
Programming Language: C++
Skills: 1. prefix sum 2. How to deal negative with mod — (sum % k + k) % k;
Tags: Hash Table, Prefix-Sum
Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

```go
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> mod2count; // store each mod to its first 
        int curr_sum = 0, res = 0;
        mod2count[0] = 1;
        for(int i = 0; i < nums.size(); ++i) {
            curr_sum += nums[i];
            int cur_mod = (curr_sum % k + k) % k; // pre[0-j] + pre[j-i] = pre[0-i] % k;
            res += mod2count[cur_mod];
            mod2count[cur_mod]++;
        }
        return res;
    }
};
```