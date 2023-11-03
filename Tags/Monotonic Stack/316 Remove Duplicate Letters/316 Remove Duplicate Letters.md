# 316. Remove Duplicate Letters

Careful: No
Date: November 3, 2023
Difficulty: Medium
Elegant Code (Template): Monotonic Stack
Index: 316
Programming Language: C++
Skills: 总体思想是贪心法，用stack做辅助。基本方法仍然是用手头的字符尽量维持一个递增字符序列，因为递增序列意味着字典序最小。
Tags: Monotonic Stack
Link: https://leetcode.com/problems/remove-duplicate-letters/

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        for(int i = 0; i < s.length(); ++i) freq[s[i]]++;
            
        string res;
        deque<int> st;
        unordered_set<char> inStack;
        for(int i = 0; i < s.length(); ++i) {
            freq[s[i]]--;
            if(inStack.count(s[i])) continue;
            while(!st.empty() && s[st.back()] >= s[i]) {
                char tmp = s[st.back()];
                if(freq[s[st.back()]] == 0) {
                    break;
                }
                st.pop_back();
                inStack.erase(tmp);
            }
            inStack.insert(s[i]);
            st.push_back(i);
            
        }
        while(!st.empty()) {
            char tmp = s[st.back()];
            st.pop_back();
            res = tmp + res;
        }
        return res;
    }
};
```