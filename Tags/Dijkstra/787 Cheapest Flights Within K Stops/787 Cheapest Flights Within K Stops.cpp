// Date: November 28, 2023
class Solution {
public:
    typedef tuple<int, int, int> State; // (costs, cur_city, remaining_k)
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> edges;
        map<pair<int, int>, int> costs;
        vector<vector<bool>> visited(n, vector<bool>(k+2, false));
        
        auto compare = [](const State& a, const State& b) {
            return get<0>(a) > get<0>(b);
        };
        // initialize
        edges.resize(n);
        for(auto& flight: flights) {
            edges[flight[0]].push_back(flight[1]);
            costs[{flight[0], flight[1]}] = flight[2];
        }
        
        priority_queue<State, vector<State>, decltype(compare)> pq(compare);
        pq.push({0, src, k+1});
        while(!pq.empty()) {
            auto [cost, city, rem_k] = pq.top();
            pq.pop();
            if (city == dst) return cost; // 到达终点
            if (visited[city][rem_k]) continue;
            visited[city][rem_k] = true;
            for (auto next_city : edges[city]) {
                if (rem_k > 0 && !visited[next_city][rem_k-1]) {
                    pq.push(make_tuple(cost + costs[{city, next_city}], next_city, rem_k-1));
                }
            }
        }
            
        return -1;
    }
};
