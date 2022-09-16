# 870. Advantage Shuffle

Careful: No
Date: September 16, 2022
Difficulty: Medium
Elegant Code (Template): Greedy, Multiset
Index: 870
Programming Language: C++
Skills: 1. multiset  2.  sort (HorseRacing)
Tags: Greedy
Link: https://leetcode.com/problems/advantage-shuffle/

```cpp
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s(begin(A), end(A));
        for (int i = 0; i < B.size(); ++i) {
            auto it = *s.rbegin() > B[i] ? s.upper_bound(B[i]) : s.begin();
            A[i] = *it;
            s.erase(it);
        }
        return A;
    }
};
```