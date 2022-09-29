# 455. Assign Cookies

Careful: No
Date: September 29, 2022
Difficulty: Easy
Index: 455
Programming Language: C++
Tags: Greedy
Link: https://leetcode.com/problems/assign-cookies/

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        multiset<int> cookies(s.begin(), s.end());
        int res = 0;
        for (auto gre: g) {
            auto it = cookies.lower_bound(gre);
            if(it != cookies.end()) {
                res++;
                cookies.erase(it);
            }
            else return res;
        }
        return res;
    }
};
```