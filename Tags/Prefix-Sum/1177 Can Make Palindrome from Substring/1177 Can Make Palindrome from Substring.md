# 1177. Can Make Palindrome from Substring

Careful: Yes
Date: November 16, 2022
Difficulty: Medium
Elegant Code (Template): Bitmask, Prefix-Sum
Index: 1177
Programming Language: C++
Skills: 1. XOR operation to represent odd-even logics 2. Use bitset to count ones in binary form
Tags: Bit-Manipulation, Prefix-Sum
Link: https://leetcode.com/problems/can-make-palindrome-from-substring/

```go
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int cur = 0;
        map<int, int> prefix{{-1, 0}};
        
        //  construct prefix palindrome
        for (int i = 0; i < s.length(); ++i) {
            cur ^= 1 << (s[i]-'a');
            prefix[i] = cur;
        }
        vector<bool> res;
        // parse queries
        for (auto query: queries) {
            int start = query[0] - 1, end = query[1], changes = query[2];
            int n = prefix[end] ^ prefix[start]; 
            // naive approach
            // int count = 0;
            // while(n!=0){
            //   n = n&(n-1);
            //   count++;
            // }
            int count = bitset<26>(n).count();
            res.push_back(count / 2 <= changes);
        }
        
        return res;
    }
};
```