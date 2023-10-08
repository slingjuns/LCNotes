# 1207. Unique Number of Occurrences

Careful: No
Date: October 8, 2023
Difficulty: Easy
Index: 1207
Programming Language: C++
Skills: 1. Hash + set 
2. counting sort
Tags: Hash Table, Sorting
Link: https://leetcode.com/problems/unique-number-of-occurrences/

### 1. Hash table + set

```cpp
bool uniqueOccurrences(vector<int>& arr) {
  unordered_map<int, int> m;
  unordered_set<int> s;
  for (auto n : arr) ++m[n];
  for (auto& p : m)
      if (!s.insert(p.second).second) return false;
  return true;
}
```

### 2. Counting Sort

- Since our values are limited to [-1000, 1000], we can use an array instead of hash set to count occurrences. Then, we can sort our array and check that no adjacent numbers are the same.

```cpp

bool uniqueOccurrences(vector<int>& arr) {
  short m[2001] = {};
  for (auto n : arr) ++m[n + 1000];
  sort(begin(m), end(m));
  for (auto i = 1; i < 2001; ++i)
      if (m[i] && m[i] == m[i - 1]) return false;
  return true;
}
```