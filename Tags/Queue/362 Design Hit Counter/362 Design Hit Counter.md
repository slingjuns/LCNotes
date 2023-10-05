# 362. Design Hit Counter

Careful: No
Date: October 5, 2023
Difficulty: Medium
Elegant Code (Template): Two Pointers
Index: 362
Programming Language: C++
Skills: 1. Deque 维护k size window
Tags: Deque, Design, Queue
Link: https://leetcode.com/problems/design-hit-counter/

```cpp
class HitCounter {
using PII = pair<int,int>;
deque<PII> storage;
int windowSize = 0;
public:
    HitCounter() {
        // binary search or deque with pairs
    }
    
    void hit(int timestamp) {
        if(!storage.empty() && storage.back().first == timestamp) {
            storage.back().second += 1;
        } else {
            storage.push_back({timestamp, 1});
        }
        windowSize++;
    }
    
    int getHits(int timestamp) {
        // always maintain a window of 300 - O(1)
        while(!storage.empty() && storage.front().first + 300 <= timestamp) {
            int count = storage.front().second;
            storage.pop_front();
            windowSize -= count;
        }
        return windowSize;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
```