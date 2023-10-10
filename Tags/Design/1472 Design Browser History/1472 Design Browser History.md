# 1472. Design Browser History

Careful: No
Date: October 10, 2023
Difficulty: Medium
Elegant Code (Template): Design
Index: 1472
Programming Language: C++
Tags: Design
Link: https://leetcode.com/problems/design-browser-history/

## Naive Version

1. Visit - O(1)
2. back - O(1)
3. forward - O(1)

```cpp
class BrowserHistory {
private:
    int current, top;
    list<string> urls;
    vector<decltype(urls)::iterator> records; 
public:
    BrowserHistory(string homepage) {
        urls.push_back(homepage);
        records.resize(5005);
        records[0] = urls.begin();
        current = top = 0;
    }
    
    void visit(string url) {
        // visit url
        // clear all forward history
        auto it = records[current];
        if(next(it) != urls.end()) urls.erase(next(it), urls.end());
        urls.push_back(url);
        current++;
        top = current;
        records[top] = --urls.end();
    }
    
    string back(int steps) {
        current = max(current-steps, 0);
        return *records[current];
    }
    
    string forward(int steps) {
        current = min(current+steps, top);
        return *records[current];
    }
};
```

## Dynamic Array

```cpp
class BrowserHistory {
public:
    string stack[5005];
    int p, t;	// current pointer, stack's top
    
    BrowserHistory(string homepage) {
        stack[p = t = 0] = homepage;
    }
    
    void visit(string url) {
        stack[t = ++p] = url;
    }
    
    string back(int steps) {
        return stack[p = max(0, p-steps)];
    }
    
    string forward(int steps) {
        return stack[p = min(t, p+steps)];
    }
};
```