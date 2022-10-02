// Date: October 2, 2022
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
