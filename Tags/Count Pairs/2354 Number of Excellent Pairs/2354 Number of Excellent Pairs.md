# 2354. Number of Excellent Pairs

Careful: No
Date: April 16, 2023
Difficulty: Hard
Index: 2354
Programming Language: C++
Tags: Binary Search, Count Pairs
Link: https://leetcode.com/problems/number-of-excellent-pairs/

因为涉及的都是位操作，我们不妨枚举一下对于单个bit位上可能出现的情况：

`a   b   a&b + a|b
1   1    1  + 1  = 2
1   0    0  + 1  = 1
0   1    0  + 1  = 1
0   0    0  + 0  = 0`

我们不难发现，无论a是0还是1，与b配对后，能得到的bit 1的数目的增量，完全取决于b本身是0还是1. 我们将这个结论从单个bit扩展到整数时依然成立，就是无论整数A是如何，与整数B配对后，bit 1的总数目的增量，就是B含有的bit 1的数目。

## Conclusion

- 任意两个整数A与B配对后，**a AND b + a OR b == 他们各自set bits的数量之和**

```cpp
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<int> arr;
        unordered_set<int>Set(nums.begin(), nums.end());
        unordered_map<int, int> sb2count; // # set bits to count
        // remove duplicate
        long long res = 0;
        for (auto x: Set)
        {
            sb2count[__builtin_popcount(x)]++;
            arr.push_back(__builtin_popcount(x));        
        }
        
        sort(arr.begin(), arr.end());
        set<int> self_pairs;
        // num1 or num2 + num1 and num2 <==> arr[i] + arr[j] >= k
        for (int i = 0; i < arr.size(); ++i) {
            auto low = lower_bound(arr.begin(), arr.end(), k-arr[i]);
            res += arr.end() - low;
        }
        return res;
    }
};
```