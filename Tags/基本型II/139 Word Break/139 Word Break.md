# 139. Word Break

Careful: Yes
Date: October 1, 2023
Difficulty: Medium
Index: 139
Programming Language: C++
Tags: Dynamic Programming, 基本型II
Link: https://leetcode.com/problems/word-break/

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1);
        sort(wordDict.begin(), wordDict.end(), [](auto s1, auto s2){
            return s1.length() < s2.length();
        });
        dp[0] = true;
        
        for(int i = 1; i < dp.size(); ++i) {
            for(int j = 0; j < wordDict.size(); ++j) {
                auto cur_word = wordDict[j];
                auto length = cur_word.length();
                // need i-cur_word.length
                if(length > i) break;
                dp[i] = dp[i] || (dp[i-length] && s.substr(i-length, length) == cur_word);
            }
        }
        
        // copy(dp.begin(), dp.end(), ostream_iterator<bool>(cout, ";"));
        return dp.back();
    }
};
```