# 1679. Max Number of K-Sum Pairs

Careful: No
Date: April 11, 2023
Difficulty: Medium
Index: 1679
Programming Language: C++
Tags: Count Pairs, Hash Table
Link: https://leetcode.com/problems/max-number-of-k-sum-pairs/

```cpp
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> cache;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int target = k - nums[i];
            if (cache[target]) {
                ans++;
                cache[target]--;
            }
            else cache[nums[i]]++;
        }
        return ans;
    }
};
```