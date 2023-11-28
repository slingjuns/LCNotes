// Date: November 28, 2023
class Solution {
private:
    vector<vector<int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};

public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        using State = tuple<int,int,int>; // {value, i, j}
        auto comp = [](const State& s1, const State& s2) { // max heap 
            return get<0>(s1) < get<0>(s2);
        };
        priority_queue<State, vector<State>, decltype(comp)> pq(comp);
        pq.push({grid[0][0], 0, 0});
        while(!pq.empty()) {
            auto [val, i, j] = pq.top();
            pq.pop();
            visited[i][j] = true;
            if(i == n-1 && j == m-1) return val;
            for(int k = 0; k < moves.size(); ++k) {
                int new_i = i+moves[k][0], new_j = j+moves[k][1];
                if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && !visited[new_i][new_j]) {
                    pq.push({min(val, grid[new_i][new_j]), new_i, new_j});
                }
            }
        }
        return -1;
    }
};
