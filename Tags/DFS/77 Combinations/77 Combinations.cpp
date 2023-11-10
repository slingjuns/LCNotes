// Date: November 10, 2023
class Solution {
vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        dfs(1, path, n, k);
        return res;
    }
    
    void dfs(int cur, vector<int>& path, int n, int k) {
        if(path.size() == k) {res.push_back(path);return;}
        for(int i = cur; i <= n; ++i) {
            path.push_back(i);
            dfs(i+1, path, n, k);
            path.pop_back();
        }
    }
};
