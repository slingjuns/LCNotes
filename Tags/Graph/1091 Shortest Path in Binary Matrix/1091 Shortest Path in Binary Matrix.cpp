// Date: October 7, 2023
using PII = pair<int,int>;
class Solution {
private:
    vector<pair<int,int>> moves = {{0,1},{0,-1},{1,0}, {-1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
    int bfs(vector<vector<int>>& grid, deque<PII>& q) {
        int levels = 1;
        while (!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop_front();
                if(cur.first == grid.size()-1 && cur.second == grid[0].size()-1) return levels;
                for (int m = 0; m < 8; ++m) {
                    int new_i = cur.first + moves[m].first, new_j = cur.second + moves[m].second;
                    if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && grid[new_i][new_j] == 0) {
                        grid[new_i][new_j] = -1;
                        q.push_back({new_i, new_j});
                    }
                }
            }
            levels++;
        }
        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        deque<PII> q = {{0,0}};
        if(grid[0][0] != 0) return -1;
        return bfs(grid, q);
    }
};
