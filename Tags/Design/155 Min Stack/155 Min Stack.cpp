// Date: September 14, 2023
class MinStack {
private:
    vector<int> st;
    vector<int> minst; // decreasing stack
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push_back(val);
        if(minst.empty() || val < minst.back()) minst.push_back(val);
    }
    
    void pop() {
        if(st.back() == minst.back()) minst.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minst.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
