# 91. Decode Ways

Careful: Yes
Date: September 23, 2023
Difficulty: Medium
Index: 91
Programming Language: C++
Tags: Dynamic Programming, 基本型II
Link: https://leetcode.com/problems/decode-ways/

## 此题的状态转移方程比较复杂

- 主要考虑当前为’0’的情况

```cpp
if (ch == '0') {
	if ('1' <= prev_char <= '2') dp[i] = dp[i-2];
	else dp[i] = 0;
} else {
	if (与前一位能凑出10~26) dp[i] = dp[i-1] + dp[i-2];
	else dp[i] = dp[i-1];
}
```

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1); // decoding ways until ith element
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        
        for(int i = 2; i < dp.size(); ++i) {
            char ch = s[i-1], prev_ch = s[i-2];
            int res = (prev_ch-'0')*10 + (ch-'0');
            if(res <= 26 && res >= 10) {
                if(ch == '0') dp[i] = dp[i-2];
                else dp[i] = dp[i-2] + dp[i-1];
            } else {
                if(ch == '0') dp[i] = 0;
                else dp[i] = dp[i-1];
            }
        }
        
        return dp.back();
    }
};
```