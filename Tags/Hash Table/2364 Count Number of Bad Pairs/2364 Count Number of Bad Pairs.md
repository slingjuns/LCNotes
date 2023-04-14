# 2364. Count Number of Bad Pairs

Careful: No
Date: April 14, 2023
Difficulty: Medium
Index: 2364
Programming Language: C++
Tags: Count Pairs, Hash Table
Link: https://leetcode.com/problems/count-number-of-bad-pairs/

```cpp
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int, int> cache;
        long long res = 0;
        long long total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int target = nums[i] - i;
            res += cache[target];
            cache[target]++;
            total += nums.size()-1-i;
        }
        
        return total - res;
    }
};
```