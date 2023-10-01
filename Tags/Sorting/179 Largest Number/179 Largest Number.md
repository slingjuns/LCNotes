# 179. Largest Number

Careful: Yes
Date: October 1, 2023
Difficulty: Medium
Index: 179
Programming Language: C++
Tags: Sorting
Link: https://leetcode.com/problems/largest-number/

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ss;
        for(auto num: nums) ss.push_back(to_string(num));
        sort(ss.begin(), ss.end(), [](const string& s1, const string& s2) {
            return s1 + s2 > s2 + s1;
        });
        
        string res;
        for(auto s: ss) res += s;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return res;
    }
};
```