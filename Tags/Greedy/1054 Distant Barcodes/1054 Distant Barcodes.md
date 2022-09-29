# 1054. Distant Barcodes

Careful: No
Date: September 29, 2022
Difficulty: Medium
Index: 1054
Programming Language: C++
Tags: Greedy
Link: https://leetcode.com/problems/distant-barcodes/

```cpp
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        // create hashmap for keeping a pair of <frequency, char>
        unordered_map<int, int> m;
        for (auto bar: barcodes) {
            m[bar]++;
        }
        
        // prioirty queue for storing pair of <freq, char> (we should use the character with highest frequency)
        priority_queue<pair<int, int>> q;
        for (auto [num, freq]: m){
            q.push({freq, num});
        }
        vector<int> res;
        // every time, we pop two different char
        while (!q.empty()) {
            int k = min(2, (int)q.size());
            vector<pair<int, int>> tmp; // used for storing two popped pair
            for (int i = 0; i < k; i++) { // !use for loop !
                auto [freq, num] = q.top();
                q.pop();
                freq--;
                if (!res.empty() && num == res.back()) return {};
                res.push_back(num);
                if (freq > 0) tmp.push_back({freq, num});
            }
            for (auto t: tmp) q.push(t);
        }
        return res;
    }
};
```