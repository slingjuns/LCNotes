// Date: September 29, 2022
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        // 0: 3
        // 3: [1, 5]
        // 5: [10]
        unordered_map<int, vector<int>> graph; // graph
        for (int i = 0; i < ppid.size(); ++i) {
            auto pp = ppid[i];
            graph[pp].push_back(pid[i]);
        }
        // no need to traverse all nodes: (we already know the target pid, so we can start from there)
        vector<int> res;
        dfs(kill, res, graph);
        return res;
    }
    
    void dfs(int root, vector<int> &res, unordered_map<int, vector<int>> &graph){
        res.push_back(root);
        if (!graph.count(root)) return;
        for (auto child: graph[root]) {
            dfs(child, res, graph);
        }
    }
};
