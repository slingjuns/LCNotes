# 380. Insert Delete GetRandom O(1)

Careful: No
Date: October 8, 2023
Difficulty: Medium
Elegant Code (Template): Design
Index: 380
Programming Language: C++
Tags: Design, Linked List, Random
Link: https://leetcode.com/problems/insert-delete-getrandom-o1/

## Follow-up : How do you modify your code to allow duplicated number?

```cpp
class RandomizedSet {
list<int> l;
unordered_map<int, int> m; // val -> index
vector<decltype(l)::iterator> vals; // index -> pointer
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(m.count(val)) return false;
        l.push_back(val);
        vals.push_back(--l.end());
        m[val] = vals.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val)) return false;
        auto index = m[val];
        // O(1) delete in vector
        // swap with back
        swap(vals[index], vals[vals.size()-1]);
        m[*vals[index]] = index;
        l.erase(vals.back());
        m.erase(val);
        vals.pop_back();
        return true;
    }
    
    int getRandom() {
        int k = rand() % vals.size();
        return *vals[k];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```