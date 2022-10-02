# 128. Longest Consecutive Sequence

Careful: Yes
Date: October 2, 2022
Difficulty: Medium
Elegant Code (Template): Union-Find
Index: 128
Programming Language: C++
Tags: Hash Table, Union-Find
Link: https://leetcode.com/problems/longest-consecutive-sequence/

## Union Find

```cpp
class Solution {
private:
    class UF {
    public:
        vector<int> fa;
        UF(int n) {
            fa.resize(n);
            init(n);
        }

        void init(int n) {
            for(int i = 0; i < n; ++i) fa[i] = i;
        }

        int find(int x) { // 查询一个元素所属哪一个集合
            return fa[x] == x ? x : fa[x] = find(fa[x]); // 路径压缩, 防止链式结构
        }

        void Union(int x, int y) { // 将两个集合合并为一个集合
            fa[find(x)] = find(y);
        }
    };
public:
    int longestConsecutive(vector<int>& nums) {
        UF uf(nums.size());
        
        unordered_map<int,int> cache;
        for(int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            if(cache.count(cur)) continue;
            cache[cur] = i;
            if(cache.count(cur-1)) uf.Union(cache[cur-1], i);
            if(cache.count(cur+1)) uf.Union(cache[cur+1], i);
        }

        // find longest set
        unordered_map<int, int> m;
        int res = 0;
        for(int i = 0; i < uf.fa.size(); ++i) {
            m[uf.find(i)]++;
            res = max(res, m[uf.find(i)]);
        }
        return res;
    }
};
```

## Set

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cache;
        for (auto num: nums) {
            cache.insert(num);
        }
        int longest = 0;
        for (auto num: nums) {
            int seq = 1;
            int cur = num;
            while (cache.count(cur+1)) { // search backwards
                seq++;
                cur = cur+1;
                cache.erase(cur);
            }
            cur = num;
            while (cache.count(cur-1)) { // search forwards
                seq++;
                cur = cur-1;
                cache.erase(cur);
            }
            longest = max(seq, longest);
        }
        return longest;
    }
};
```