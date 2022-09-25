# 881. Boats to Save People

Careful: No
Date: September 25, 2022
Difficulty: Medium
Elegant Code (Template): Greedy, Two Pointers
Index: 881
Programming Language: C++
Skills: 1. Similar to 2Sum. (Greedy)
Tags: Greedy, Left-Right-Pointers, Two Pointers
Link: https://leetcode.com/problems/boats-to-save-people/

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size()-1;
        int boats = 0;
        while (left <= right) {
            int sum = people[left] + people[right];
            if (sum > limit) {
                right--;
            } else {
                right--;
                left++;
            }
            boats++;
            if (left == right) {
                return boats;
            }
        }
        return boats;
    }
};
```