# 1656. Design an Ordered Stream

Careful: No
Date: October 6, 2023
Difficulty: Easy
Index: 1656
Programming Language: C++
Tags: Design
Link: https://leetcode.com/problems/design-an-ordered-stream/

```cpp
class OrderedStream {
vector<string> v;
int ack;
public:
    OrderedStream(int n) {
        v.resize(n);
        ack = 0;
    }
    
    vector<string> insert(int idKey, string value) {
        // similar to TCP Reordering
        v[idKey-1] = value;
        while(ack < v.size() && v[ack] != "") ack++;
        if(ack < idKey-1) return {};
        return vector<string>(v.begin()+idKey-1, v.begin()+ack);
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
```