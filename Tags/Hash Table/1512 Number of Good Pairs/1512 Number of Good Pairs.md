# 1512. Number of Good Pairs

Careful: No
Date: April 13, 2023
Difficulty: Easy
Index: 1512
Programming Language: C++
Tags: Count Pairs, Hash Table
Link: https://leetcode.com/problems/number-of-good-pairs/

```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> counter;
        int res = 0;
        for (auto num: nums){
            res += counter[num]++;
        }
        return res;
    }
};
```