# 716. Max Stack

Careful: No
Date: September 14, 2023
Difficulty: Hard
Elegant Code (Template): Design
Index: 716
Programming Language: C++
Tags: Design
Link: https://leetcode.com/problems/max-stack/

```cpp
class MaxStack {
private:
    list<int> st;
    map<int, vector<list<int>::iterator>> m;   // value -> iterator
public:
    MaxStack() {
    }
    
    void push(int x) {
        st.push_back(x);
        m[x].push_back(--st.end());
    }
    
    int pop() {
        auto x = st.back();
        st.pop_back();
        if(m[x].size() == 1) m.erase(x);
        else m[x].pop_back();
        return x;
    }
    
    int top() {
        return st.back();
    }
    
    int peekMax() {
        return (--m.end())->first;
    }
    
    int popMax() {
        auto x = (--m.end())->first;
        list<int>::iterator target = m[x].back();
        if(m[x].size() == 1) m.erase(x);
        else m[x].pop_back();
        st.erase(target);
        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
```