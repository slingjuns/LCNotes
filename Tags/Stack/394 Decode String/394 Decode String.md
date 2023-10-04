# 394. Decode String

Careful: No
Date: October 4, 2023
Difficulty: Medium
Index: 394
Programming Language: C++
Tags: Stack
Link: https://leetcode.com/problems/decode-string/

```cpp
class Solution {
public:
    string decodeString(string s) {
        deque<int> num_st;
        deque<string> str_st;
        int i = 0;
        while(i < s.length()) {
            
            if(isdigit(s[i])) {
                auto num = 0, j = i;
                while(j < s.length() && isdigit(s[j])) j++;
                num = stoi(s.substr(i, j-i));
                i = j;
                num_st.push_back(num);
            } else if(s[i] == '[') {
                string cur;
                cur += s[i++];
                str_st.push_back(cur);
            } else if(s[i] == ']') {
                // popping stack
                string tmp;
                while(!str_st.empty() && str_st.back() != "[") {
                    auto top = str_st.back();
                    tmp = top + tmp;
                    str_st.pop_back();
                }
                str_st.pop_back(); // pop [
                string res;
                for(int j = 0; j < num_st.back(); ++j) {
                    res = tmp + res;
                }
                num_st.pop_back(); // pop number before [
                str_st.push_back(res);
                i++;
            } else {
                string cur;
                cur += s[i++];
                str_st.push_back(cur);
            }
        }
        
        string res;
        while(!str_st.empty()) {
            auto top = str_st.back();
            str_st.pop_back();
            res = top + res;
        }
        return res;
    }
};
```