# 347. Top K Frequent Elements

Careful: Yes
Date: October 2, 2022
Difficulty: Medium
Elegant Code (Template): Priority Queue
Index: 347
Programming Language: C++
Skills: 1. Only Maintain a priority queue of size k
Tags: Hash Table, Priority Queue
Link: https://leetcode.com/problems/top-k-frequent-elements/

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto num: nums){
            m[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> res;
        for (auto [key, v]: m) {  // keep only size k
            q.push({v, key});
            if (q.size() > k) q.pop();
        }
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
```