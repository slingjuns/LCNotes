# 5. Longest Palindromic Substring

Careful: Yes
Date: August 31, 2023
Difficulty: Medium
Elegant Code (Template): Dynamic Programming, LPS, 区间DP
Index: 5
Programming Language: C++
Skills: 1. 区间DP
Tags: Dynamic Programming, LPS, 区间DP
Link: https://leetcode.com/problems/longest-palindromic-substring/

```cpp
class Solution {
private: 
    bool check(string& s, int left, int right){
        while(left < right) {
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        int starting_index = 0;
        int max_len = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(s, i, j)){
                    if(j-i+1 > max_len){
                        max_len = j-i+1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index, max_len);
    }
};
```