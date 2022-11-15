# 1371. Find the Longest Substring Containing Vowels in Even Counts

Careful: Yes
Date: November 15, 2022
Difficulty: Medium
Elegant Code (Template): Bit-Manipulation, Bitmask, Prefix-Sum
Index: 1371
Programming Language: C++
Skills: 1. frequency prefix 2. 5个bit组成的二进制数来编码，来代表preFreq[j]里五个字母频次的奇偶性。比如说我们遍历到j时，preFreq[j]对应的key=00100，就表示前j个元素里，字母i出现了奇数次而其他元音字母出现了偶数次
Tags: Bit-Manipulation, Hash Table, Prefix-Sum
Link: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

```cpp
int findTheLongestSubstring(string s) {
        unordered_map<int, int> m{{0, -1}};
        int res = 0, n = s.length(), cur = 0;
        for (int i = 0; i < n; i++) {
            cur ^= 1 << string("aeiou").find(s[i]) + 1 >> 1;
            if (!m.count(cur)) m[cur] = i;
            res = max(res, i - m[cur]);
        }
        return res;
    }
```