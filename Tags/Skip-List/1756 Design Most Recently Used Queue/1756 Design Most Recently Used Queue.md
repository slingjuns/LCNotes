# 1756. Design Most Recently Used Queue

Careful: Yes
Date: October 5, 2023
Difficulty: Medium
Elegant Code (Template): Design
Index: 1756
Programming Language: C++
Skills: 1. 像skip-list 一样给linkedlist添加索引
Tags: Design, Skip-List
Link: https://leetcode.com/problems/design-most-recently-used-queue/

## 重难点:

1. splice 当前iterator 移动到队尾之后, iterator→next 变为end()
2. **需要在移之前把当前index 的索引iterator 更新** 

```cpp
**if(k%step == 0 && next(target) != l.end()) 
	index[k/step] = next(target);**
```

```cpp
class MRUQueue {
// skip-list, creating index
list<int> l;
vector<decltype(l)::iterator> index;
int step;
public:
    MRUQueue(int n) {
        step = (int)sqrt(n);
        for(int i = 0; i < n; ++i) {
            l.push_back(i+1);
            if(i % step == 0) index.push_back(--l.end());
        }
    }
    
    int fetch(int k) {
        k = k-1;
        int bucket = k / step;
        decltype(l)::iterator target = index[bucket];
        for(int i = 0; i < k%step; ++i) target = next(target);
        if(k%step == 0 && next(target) != l.end()) index[k/step] = next(target);
        // move to the end
        l.splice(l.end(),l,target);
        // update all buckets after k/step+1 bucket
        for(int i = k/step+1; i < index.size(); ++i) {
            index[i] = next(index[i]);
        }
        return *target;
    }
};
```