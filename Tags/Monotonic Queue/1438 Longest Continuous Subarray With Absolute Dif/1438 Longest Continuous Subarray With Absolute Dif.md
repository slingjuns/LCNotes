# 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

Careful: Yes
Date: November 1, 2023
Difficulty: Medium
Elegant Code (Template): Monotonic Queue
Index: 1438
Programming Language: C++
Tags: Monotonic Queue
Link: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& A, int limit) {
        deque<int> max_q, min_q;
        int res = 1;
        int left = 0;
        for(int i = 0; i < A.size(); ++i) {
            while(!max_q.empty() && A[max_q.back()] < A[i]) max_q.pop_back();
            while(!min_q.empty() && A[min_q.back()] > A[i]) min_q.pop_back();
            max_q.push_back(i);
            min_q.push_back(i);
            while (A[max_q.front()] - A[min_q.front()] > limit) {
                if (max_q.front() == left) max_q.pop_front();
                if (min_q.front() == left) min_q.pop_front();
                ++left;
            }
            res = max(res, i-left+1);
        }
        return res;
    }
};
```

原文链接: 

[](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/discuss/609771/JavaC++Python-Deques-O(N))