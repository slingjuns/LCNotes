# 133. Clone Graph

Careful: No
Date: September 22, 2023
Difficulty: Medium
Index: 133
Programming Language: C++
Tags: BFS, DFS, Graph
Link: https://leetcode.com/problems/clone-graph/

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    map<Node*, Node*> m; // old ptr to new ptr
    set<Node *> visited;
public:
    void bfs(Node* root) {
        deque<Node*> q = {root};
        while(!q.empty()) {
            auto cur = q.front();
            q.pop_front();
            if(visited.count(cur)) continue;
            
            visited.insert(cur);
            if(!m.count(cur)) {
                m[cur] = new Node(cur->val);
            }
            for(auto nb: cur->neighbors) {
                if(!m.count(nb)) m[nb] = new Node(nb->val);
                m[cur]->neighbors.push_back(m[nb]);
                q.push_back(nb);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        bfs(node);
        return m[node];
    }
};
```