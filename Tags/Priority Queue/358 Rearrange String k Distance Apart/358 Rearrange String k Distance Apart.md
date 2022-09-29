# 358. Rearrange String k Distance Apart

Careful: Yes
Date: September 29, 2022
Difficulty: Hard
Elegant Code (Template): Greedy, Priority Queue
Index: 358
Programming Language: C++
Skills: 1. Be careful about k = 0
Tags: Greedy, Priority Queue
Link: https://leetcode.com/problems/rearrange-string-k-distance-apart/

```cpp
class Solution {
public:
    string rearrangeString(string s, int k) {
        // create hashmap for keeping a pair of <frequency, char>
        map<char, int> m;
        for (auto ch: s) {
            m[ch]++;
        }
        
        // prioirty queue for storing pair of <freq, char> (we should use the character with highest frequency)
        priority_queue<pair<int, char>> q;
        for (auto [ch, freq]: m){
            q.push({freq, ch});
        }
        string res = "";
        // every time, we pop two different char
        while (!q.empty()) {
            int size = min(max(k, 1), (int)q.size());
            vector<pair<int, char>> tmp; // used for storing two popped pair
            for (int i = 0; i < size; i++) { // !use for loop !
                auto [freq, ch] = q.top();
                q.pop();
                freq--;
                res+=ch;
                if (freq > 0) tmp.push_back({freq, ch});
            }
            if (size < k && tmp.size() != 0) return "";
            for (auto t: tmp) q.push(t);
        }
        return res;
    }
    
    
};
```