# 49. Group Anagrams

Careful: No
Date: September 29, 2022
Difficulty: Medium
Elegant Code (Template): Hash Table
Index: 49
Programming Language: C++, Java
Skills: 1. We can store vector as key in the hashmap
Tags: Hash Table
Link: https://leetcode.com/problems/group-anagrams/

C++:

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> cache;
        for (auto &s: strs) { // count sort
            vector<int> tmp(26);
            for (auto ch: s) {
                tmp[ch-'a']++;
            }
            cache[tmp].push_back(s);
        }
        vector<vector<string>> res;
        for (const auto &[k, v]: cache) res.push_back(v);
        return res;
    }
};
```

Java:

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for (String s : strs) {
            char[] ca = new char[26];
            for (char c : s.toCharArray()) ca[c - 'a']++;
            String keyStr = String.valueOf(ca);
            map.computeIfAbsent(keyStr, k -> new ArrayList<>());
            map.get(keyStr).add(s);
        }
        return new ArrayList<>(map.values());
    }
}
```