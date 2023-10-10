# 140. Word Break II

Careful: No
Date: October 10, 2023
Difficulty: Hard
Index: 140
Programming Language: C++
Skills: 1. DP table 支持的operator 可以generalize为所有支持aggregation 操作的operator
Tags: Dynamic Programming, 基本型II
Link: https://leetcode.com/problems/word-break-ii/

```cpp
class Solution {
private:

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> dp(s.length()+1, vector<string>(0));
        set<string> m(wordDict.begin(), wordDict.end());
        
        dp[0] = {""};
        for(int i = 1; i <= s.length(); ++i) {
            auto index = i-1;
            for(auto word: m) {
                int size = word.length();
                if(i-size >= 0 && s.substr(i-size, size) == word) {
                    for(int j = 0; j < dp[i-size].size(); ++j) {
                        dp[i].push_back(dp[i-size][j]+word+" ");
                    }
                }
            }
        }
        for(auto& s: dp[s.length()]) s.pop_back();
        return dp[s.length()];
    }
};
```