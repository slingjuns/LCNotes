// Date: November 12, 2023
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
