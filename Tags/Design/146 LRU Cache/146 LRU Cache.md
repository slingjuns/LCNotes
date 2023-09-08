# 146. LRU Cache

Careful: Yes
Date: September 8, 2023
Difficulty: Medium
Elegant Code (Template): Design
Index: 146
Programming Language: C++
Tags: Design
Link: https://leetcode.com/problems/lru-cache/

```cpp
class LRUCache {
private:
    list<pair<int, int>> ll;
    unordered_map<int, list<pair<int, int>>::iterator> m; // key -> (iterator to value)
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!m.count(key)) return -1;
        ll.splice(ll.begin(), ll, m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if(m.count(key)) { // update
            m[key]->second = value;
            ll.splice(ll.begin(), ll, m[key]);
            return;
        }
        if(capacity == 0) {
            m.erase(ll.back().first);
            ll.pop_back();
        } else {
            capacity--;
        }
        ll.push_front({key, value});
        m[key] = ll.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```