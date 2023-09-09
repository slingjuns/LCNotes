# 239. Sliding Window Maximum

Careful: Yes
Date: September 9, 2023
Difficulty: Hard
Elegant Code (Template): Monotonic Queue
Index: 239
Programming Language: C++, Java
Tags: Monotonic Queue
Link: https://leetcode.com/problems/sliding-window-maximum/

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {        
        vector<int>results;
        deque<int>q;
        for (int i=0; i<nums.size(); i++)
        {
            while (q.size()>0 && nums[q.back()]<nums[i])
                q.pop_back();
            q.push_back(i);

            if (q.front()<=i-k)
                q.pop_front();

            if (i>=k-1)
                results.push_back(nums[q.front()]);
        }
        return results;
    }
};
```

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new ArrayDeque<>(); // stores index
        int[] res = new int[nums.length+1-k];
        for(int i = 0; i < nums.length; ++i) {
            while(!dq.isEmpty() && nums[dq.peekLast()] <= nums[i]) dq.pollLast();
            if(!dq.isEmpty() && dq.peekFirst() <= i-k) dq.pollFirst();
            dq.offerLast(i);
            if(i+1-k >= 0) res[i+1-k] = nums[dq.peekFirst()];
        }
        return res;
    }
}
```