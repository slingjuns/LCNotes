# 659. Split Array into Consecutive Subsequences

Careful: No
Date: October 2, 2022
Difficulty: Medium
Elegant Code (Template): Hash Table, Split-into-subsequences
Index: 659
Programming Language: C++
Skills: 1. sort the array 2. use hashmap to store the end index of each sequence 3. Greedy:  if can be added to the existing sequence, do it; otherwise start a new sequence that satifies the requirement
Tags: Greedy, Hash Table
Link: https://leetcode.com/problems/split-array-into-consecutive-subsequences/

## Explanation

[[C++/Python] Esay Understand Solution - LeetCode Discuss](https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/106514/C%2B%2BPython-Esay-Understand-Solution)

```cpp
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> seq;  // stores seq end number -> count
        unordered_map<int, int> count; // stores num -> num occurrences
        for (auto num: nums) count[num]++;
        
        for (auto num: nums) {
            if (count[num] == 0) continue;
            if (seq[num-1]) { // add to exist sequence
                seq[num-1]--;
                seq[num]++;
                count[num]--;
            } else { // start a new sequence
                for (int i = 0; i < 3; ++i) {
                    if (!count[num+i]) return false;
                    count[num+i]--;
                }
                seq[num+2]++;
            }
        }
        return true;
    }
};
```