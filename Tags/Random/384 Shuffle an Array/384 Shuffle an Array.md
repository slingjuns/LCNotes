# 384. Shuffle an Array

Careful: No
Date: October 3, 2023
Difficulty: Medium
Elegant Code (Template): Random
Index: 384
Programming Language: C++
Tags: Random
Link: https://leetcode.com/problems/shuffle-an-array/

```cpp
class Solution {
private:
    vector<int> initial, curr;
    int n;
public:
    Solution(vector<int>& nums) {
        initial = nums;
        curr = nums;
        n = nums.size();
    }
    
    vector<int> reset() {
        return initial;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < n; ++i) {
            int randi = rand() % (n-i) + i; // random int [i, n]
            swap(curr[randi], curr[i]);
        }
        return curr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
```