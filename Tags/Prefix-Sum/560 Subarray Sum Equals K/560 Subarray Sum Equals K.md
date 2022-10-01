# 560. Subarray Sum Equals K

Careful: Yes
Date: October 1, 2022
Difficulty: Medium
Elegant Code (Template): Hash Table, Prefix-Sum
Index: 560
Programming Language: C++
Skills: 1. Count of prefix sum
2. Using a hash table to store the number of a prefix sum occurs so far
Tags: Hash Table, Prefix-Sum
Link: https://leetcode.com/problems/subarray-sum-equals-k/

![Untitled](Untitled%204.png)

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix sum
        map<int, int> cache{{0,1}}; // prefix sum -> count
        vector<int> prefix(nums.size());
        int res = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i] += sum + nums[i];
            sum = prefix[i];
            int target = sum-k;
            res += cache[target];
            cache[prefix[i]]++;
        }
        return res;
    }
};
```