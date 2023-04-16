# 954. Array of Doubled Pairs

Careful: Yes
Date: April 16, 2023
Difficulty: Medium
Elegant Code (Template): Pairs
Index: 954
Programming Language: C++
Skills: 1. 关键是搞清楚为什么需要sort
Tags: Count Pairs
Link: https://leetcode.com/problems/array-of-doubled-pairs/

## Sorting

### I**ntuition**

- If `x` is currently the array element with the least absolute value, it must pair with `2*x`, as there does not exist any other `x/2` to pair with it.

### 为什么需要Sort

- 遍历arr[i]时，**我们并不知道需要match arr[2i] 还是 arr[i / 2]**
- 需要sorting保证前后一致性

```cpp
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> c;
        for (int a : A) c[a]++;
        vector<int> keys;
        for (auto it : c)
            keys.push_back(it.first);
        sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        for (int x : keys) {
            if (c[x] > c[2 * x])
                return false;
            c[2 * x] -= c[x];
        }
        return true;
    }
};
```

## Non-sorting

[From O(n*log n) to O(n) - 3 approaches summarized (updated) - Array of Doubled Pairs - LeetCode](https://leetcode.com/problems/array-of-doubled-pairs/discuss/1397916/From-O(n*log-n)-to-O(n)-3-approaches-summarized-(updated))

### **Summary:**

We use sort in the first two approaches to deal with the confusion of matching even values, say `2*x` with `x` or `4*x`. E.g. if we encounter `2`, we don't know whether to match it with `1` or with `4`. Processing them in sorted order, we ensure that we always deal with smaller values first. So if we ever encounter `2`, we know `1` is already dealt with, so we always match with `4`.

However, we can deal with this without having to sort the input or the keys of the hashmap, if we process such numbers in groups. If we have `1`, `2`, `4` and `8` in our hashmap and we encounter `4`, we reduce it to `1` and then start matching `1` to `2`, then `2` to `4` and then `4` to `8`. We do need to deal with `0` separately though, which is trivial.

- `n = len(arr)` and `N = max(arr)`
- Time: `O(n * log N)` in theory but practically runs as fast as `O(n)`
- Space: `O(n)`

```cpp
def canReorderDoubled(self, arr: List[int]) -> bool:
        if sum(arr)%3 != 0: return False
        counter = Counter(arr)
        
        if 0 in counter:
            if counter[0]%2: return False
            counter.pop(0)
            
        for num in list(counter.keys()):
            if num not in counter: 
                continue
            while num % 2 == 0 and num//2 in counter: 
                num = num // 2
            while counter[num] > 0 and 2*num in counter:
                counter[2*num] -= counter[num]
                counter.pop(num)
                num = 2*num
            if counter[num] != 0: return False

        return True
```