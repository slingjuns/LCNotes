# 1244. Design A Leaderboard

Careful: Yes
Date: October 4, 2023
Difficulty: Medium
Elegant Code (Template): Design
Index: 1244
Programming Language: C++
Skills: 1. No need for map + reverse_map, only need to store pairs
Tags: Design
Link: https://leetcode.com/problems/design-a-leaderboard/

1. Map + set of {map_value, map_key}

```cpp
class Leaderboard {
public:
    
    map<int,int> M;
    set<pair<int,int>> S;
      
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        S.erase({M[playerId],playerId});
        M[playerId] += score;
        S.insert({M[playerId],playerId});
    }
    
    int top(int K) {
        int res = 0;
        int c = 0;
        for(auto it = S.rbegin(); it!=S.rend() && c < K; it++) {
            res+=(it->first);
            c++;
        }
        return res;
    }
    
    void reset(int playerId) {
        S.erase({M[playerId],playerId});
        M[playerId] = 0;
    }
};
```