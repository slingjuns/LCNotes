# 187. Repeated DNA Sequences

Careful: Yes
Date: October 3, 2023
Difficulty: Medium
Elegant Code (Template): Rolling Hash, String
Index: 187
Programming Language: C++
Skills: 1. Rolling Hash 经典问题
Tags: Rolling Hash, String
Link: https://leetcode.com/problems/repeated-dna-sequences/

```cpp
class Solution {
using LL = long long;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        LL base = 26, mod = 1e9+7, hash = 0, pow_base_len=1;
        int L = 10;
        int left = 0;
        unordered_set<string> res;
        unordered_map<LL, set<string>> hash_map;
        for (int i=0; i<L; i++)
            pow_base_len = pow_base_len*base % mod;

        for(int i = 0; i < s.length(); ++i) {
            auto c = s[i];
            hash = (hash * base + s[i]-'A') % mod;
            if(i-left+1 > L) {
                hash = (hash - (s[left]-'A')*pow_base_len%mod + mod) % mod;
                left++;
            } 
            if(i-left+1 == L) {
                if(hash_map.count(hash)) {
                    if(hash_map[hash].count(s.substr(left, L))) {
                        res.insert(s.substr(left,L));
                        continue;
                    }
                }
                hash_map[hash].insert(s.substr(left, L));
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
```