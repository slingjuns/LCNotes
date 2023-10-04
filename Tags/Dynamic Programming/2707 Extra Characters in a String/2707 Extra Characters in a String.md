# 2707. Extra Characters in a String

Careful: No
Date: October 4, 2023
Difficulty: Medium
Index: 2707
Programming Language: C++
Tags: Dynamic Programming, 基本型II
Link: https://leetcode.com/problems/extra-characters-in-a-string/

```cpp
class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        vector<int> dp(s.size()+1, 0); // longest word break until ith element
        unordered_set<string> ss(dict.begin(), dict.end());
        for(int i = 1; i < dp.size(); ++i) {
            auto cur_i = i-1;
            for(int j = 1; j-1 <= cur_i; ++j) {
                auto cur_j = j-1;
                auto str = s.substr(cur_j, cur_i-cur_j+1);
                if(ss.count(str)) dp[i] = max(dp[i], dp[j-1] + cur_i-cur_j+1);
                else dp[i] = max(dp[i], dp[j-1]);
            }
        }
        
        return s.length()-dp.back();
    }
};
```