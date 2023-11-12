# 78. Subsets

Careful: No
Date: November 12, 2023
Difficulty: Medium
Index: 78
Programming Language: C++
Tags: DFS
Link: https://leetcode.com/problems/subsets/

```cpp
class Solution {
private:
    vector<vector<int>> res;
public:
    void dfs(vector<int>& nums, vector<int>& path, int i) {
        if(i > nums.size()) return;
        res.push_back(path);
        for(int k = i; k < nums.size(); ++k) {
            path.push_back(nums[k]);
            dfs(nums, path, k+1);
            path.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        dfs(nums, path, 0);
        return res;
    }
};
```