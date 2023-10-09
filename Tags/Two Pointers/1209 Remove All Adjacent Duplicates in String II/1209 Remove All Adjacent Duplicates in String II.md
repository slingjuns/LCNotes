# 1209. Remove All Adjacent Duplicates in String II

Careful: Yes
Date: October 9, 2023
Difficulty: Medium
Elegant Code (Template): Stack
Index: 1209
Programming Language: C++
Skills: 1. stack with pair <char, int>
Tags: Stack, Two Pointers
Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

## Stack

```cpp
class Solution {
using PCI = pair<char,int>; // storing char -> count
private:
    deque<PCI> st;
public:
    string removeDuplicates(string s, int k) {
		    stack<int> counts;
		    for (int i = 0; i < s.size(); ++i) {
		        if (i == 0 || s[i] != s[i - 1]) {
		            counts.push(1);
		        } else if (++counts.top() == k) {
		            counts.pop();
		            s.erase(i - k + 1, k);
		            i = i - k;
		        }
		    }
		    return s;
		}
};
```

## Two Pointers

```cpp
string removeDuplicates(string s, int k) {
        int i = 0, n = s.length();
        vector<int> count(n);
        for (int j = 0; j < n; ++j, ++i) {
            s[i] = s[j];
            count[i] = i > 0 && s[i - 1] == s[j] ? count[i - 1] + 1 : 1;
            if (count[i] == k) i -= k;
        }
        return s.substr(0, i);
    }
```