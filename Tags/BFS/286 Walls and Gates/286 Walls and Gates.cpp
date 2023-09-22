// Date: September 22, 2023
class Solution {
const int INF = 2147483647;
using PII = pair<int, int>;
int moves_x[4] = {1,-1,0,0};
int moves_y[4] = {0,0,-1,1};
public:
    void bfs(vector<vector<int>>& rooms, deque<PII>& q) {
        set<PII> visited(q.begin(), q.end());
        int levels = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop_front();
                for(int m = 0; m < 4; ++m) {
                    int dx = moves_x[m], dy = moves_y[m];
                    int new_i = cur.first + dx, new_j = cur.second + dy;
                    if(new_i >= 0 && new_i < rooms.size() && new_j >= 0 && new_j < rooms[0].size() 
                       && !visited.count({new_i, new_j}) && rooms[new_i][new_j] != -1) {
                        visited.insert({new_i, new_j});
                        q.push_back({new_i, new_j});
                        // in-place modify
                        rooms[new_i][new_j] = levels+1;
                    }
                }
            }
            levels++;
        }
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        deque<PII> q;
        for(int i = 0; i < rooms.size(); ++i) {
            for(int j = 0; j < rooms[0].size(); ++j) {
                if(rooms[i][j] == 0) q.push_back({i, j});
            }
        }
        
        bfs(rooms, q);
    }
};
