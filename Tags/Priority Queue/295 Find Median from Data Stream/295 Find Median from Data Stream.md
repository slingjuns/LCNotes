# 295. Find Median from Data Stream

Careful: Yes
Date: January 30, 2024
Difficulty: Hard
Elegant Code (Template): Priority Queue
Index: 295
Programming Language: C++
Tags: Priority Queue
Link: https://leetcode.com/problems/find-median-from-data-stream/

### 难点: 如何保证实时排序

- When adding a new number `num` into our `MedianFinder`:
    - Firstly, add `num` to the `maxHeap`, now `maxHeap` may contain the big element (which should belong to `minHeap`). So we need to balance, by removing the highest element from `maxHeap`, and offer it to `minHeap`.
    - Now, the `minHeap` might hold more elements than `maxHeap`, in that case, we need to balance the size, by removing the lowest element from `minHeap` and offer it back to `maxHeap`.
- When doing `findMedian()`:
    - If `maxHeap.size > minHeap.size` return top of the `maxHeap`, which is the highest number amongs low numbers.
    - Else if `maxHeap.size == minHeap` return the `(maxHeap.top() + minHeap.top()) / 2`.

![https://assets.leetcode.com/users/images/0eb8feba-cbfa-4f73-8d26-9aad226bdbc5_1626016093.9717174.png](https://assets.leetcode.com/users/images/0eb8feba-cbfa-4f73-8d26-9aad226bdbc5_1626016093.9717174.png)

```cpp
class MedianFinder {
priority_queue<int> lower; // max heap, should store lower half
priority_queue<int, vector<int>, greater<int>> upper; // min heap, should store upper half
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lower.push(num);
        upper.push(lower.top());
        lower.pop();
        if(upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if(lower.size() > upper.size()) return lower.top();
        else return (lower.top() + upper.top()) / 2.0;
    }
};
```

原文链接:

[LeetCode - The World's Leading Online Programming Learning Platform](https://leetcode.com/problems/find-median-from-data-stream/discuss/1330646/C++JavaPython-MinHeap-MaxHeap-Solution-Picture-explain-Clean-and-Concise)