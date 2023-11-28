# 787. Cheapest Flights Within K Stops

Careful: Yes
Date: November 28, 2023
Difficulty: Medium
Elegant Code (Template): Dijkstra, Priority Queue
Index: 787
Programming Language: C++
Skills: 1. 理解visited 为什么是2D vector： 举个例子，假设最多允许转机5次，一种方案是你转机3次花费10到达A地（非终点），另一种方案是转机4次花费8到达A，对于后续的影响而言孰优孰劣我们是无法判断的。所以我们必须将它们都加入BFS的队列之中。当然
Tags: Dijkstra, Priority Queue
Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/

```cpp
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
```

```java
class Solution {
  public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
    List<Pair<Integer, Integer>>[] graph = new List[n];
    // (d, u, stops)
    Queue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
    int[][] dist = new int[n][k + 2];
    Arrays.stream(dist).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] f : flights) {
      final int u = f[0];
      final int v = f[1];
      final int w = f[2];
      graph[u].add(new Pair<>(v, w));
    }

    minHeap.offer(new int[] {0, src, k + 1}); // Start with node src with d == 0
    dist[src][k + 1] = 0;

    while (!minHeap.isEmpty()) {
      final int d = minHeap.peek()[0];
      final int u = minHeap.peek()[1];
      final int stops = minHeap.poll()[2];
      if (u == dst)
        return d;
      if (stops > 0)
        for (Pair<Integer, Integer> pair : graph[u]) {
          final int v = pair.getKey();
          final int w = pair.getValue();
          final int newDist = d + w;
          if (newDist < dist[v][stops - 1]) {
            dist[v][stops - 1] = newDist;
            minHeap.offer(new int[] {d + w, v, stops - 1});
          }
        }
    }

    return -1;
  }
}
```