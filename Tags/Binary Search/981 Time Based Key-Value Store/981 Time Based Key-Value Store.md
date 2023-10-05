# 981. Time Based Key-Value Store

Careful: Yes
Date: October 5, 2023
Difficulty: Medium
Elegant Code (Template): Design
Index: 981
Programming Language: C++
Tags: Binary Search, TimeStamp
Link: https://leetcode.com/problems/time-based-key-value-store/

```cpp
class TimeMap {
unordered_map<string, map<int, string>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        if(it == m[key].begin()) return "";
        --it;
        return it->second;
    }
};
```