// Date: November 10, 2023
class Solution {
vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size());
        vector<int> path;
        dfs(nums, used, path);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<bool> &used, vector<int>& path) {
        bool all_used = true;
        for(int i = 0; i < nums.size(); ++i) {
            if(used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, used, path);
            used[i] = false;
            all_used = false;
            path.pop_back();
        }
        if(all_used) res.push_back(path);
    }
};
