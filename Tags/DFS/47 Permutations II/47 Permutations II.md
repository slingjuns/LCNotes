# 47. Permutations II

Careful: Yes
Date: November 10, 2023
Difficulty: Medium
Elegant Code (Template): DFS
Index: 47
Programming Language: C++
Skills: 1. 有重复时候 应该先sort, 然后把相同元素剪枝
Tags: DFS
Link: https://leetcode.com/problems/permutations-ii/

```cpp
class Solution {
vector<vector<int>> res;
vector<bool> used;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(nums.size());
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(nums, path);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<int>& path) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, path);
            path.pop_back();
            used[i] = false;
            while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
    }
};
```