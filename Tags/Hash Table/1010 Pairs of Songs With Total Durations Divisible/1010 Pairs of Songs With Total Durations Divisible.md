# 1010. Pairs of Songs With Total Durations Divisible by 60

Careful: No
Date: February 4, 2024
Difficulty: Medium
Index: 1010
Programming Language: C++
Skills: 1. hash table stores element % mod
Tags: Hash Table
Link: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

```cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> m;
        int res = 0;
        for(int i = 0; i < time.size(); ++i) {
            int cur = time[i];
            res += m[(60 - cur % 60) % 60];
            m[cur % 60]++;
        }
        return res;
    }
};
```