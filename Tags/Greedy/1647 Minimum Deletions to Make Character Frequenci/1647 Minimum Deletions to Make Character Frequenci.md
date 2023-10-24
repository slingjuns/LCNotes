# 1647. Minimum Deletions to Make Character Frequencies Unique

Careful: Yes
Date: October 24, 2023
Difficulty: Medium
Elegant Code (Template): Greedy, Hash Table
Index: 1647
Programming Language: C++
Skills: 1. 这是一种常用处理unique的方法, 注意如何分析worst case 时间复杂度
Tags: Greedy, Hash Table
Link: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

## Complexity Analysis

- Here,  *N* is the length of the given string, and *K* is the maximum possible number of distinct characters in *S*.
- Time complexity: *O*(*N* + *K^*2)

## Worst Case:

- **When the frequencies for all the *K* characters are the same**. In that case, for the *i*th character, we would need to decrement the frequency to make it unique. Hence the total number of operations would be **0+1+2+...+K−1= O(N + K^2)**.

```cpp
class Solution {
using PII = pair<int,int>;
public:
    int minDeletions(string s) {
        // ceabaacb => 1,2,2,3 => greedy
        // aaabbbcc => 3,3,2 => 
        unordered_map<int,int> freq;
        for(char c: s) freq[c]++;
        
        unordered_set<int> unique;
        int res = 0;
        for(auto i = freq.begin(); i != freq.end(); ++i) {
            auto cur_freq = i->second;
            while(cur_freq && unique.count(cur_freq)) { // not unique
                cur_freq--;
                res++;
            }
            if(cur_freq != 0) unique.insert(cur_freq);
        }
        
        return res;
    }
};
```