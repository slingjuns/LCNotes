// Date: November 9, 2023
class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> tmp;
        dfs(nums, 0, tmp);
        return res;
    }
    
    void dfs(vector<int>& nums, int index, vector<int>& path) {
        if(index == nums.size()) {
            return;
        }
        unordered_set<int> visited;
        for(int i = index; i < nums.size(); ++i) {
            if(visited.count(nums[i])) continue;
            if(path.empty() || (!path.empty() && path.back() <= nums[i])) {
                path.push_back(nums[i]);
                if(path.size() >= 2) res.push_back(path);
                dfs(nums, i+1, path);
                path.pop_back();
            }
            visited.insert(nums[i]);
        }
    }
};
