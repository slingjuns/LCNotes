# 1061. Lexicographically Smallest Equivalent String

Careful: No
Date: November 2, 2023
Difficulty: Medium
Elegant Code (Template): Union-Find
Index: 1061
Programming Language: C++
Tags: Union-Find
Link: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

```cpp
class Solution {
    class UF {
    public:
        vector<int> fa;
        UF(int n) {
            fa.resize(n);
            for(int i = 0; i < n; ++i) fa[i] = i;
        }
        
        int find(int x) {
            return fa[x] == x ? x : fa[x] = find(fa[x]);
        }
        
        void Union(int x, int y) {
            int fa_x = find(x), fa_y = find(y);
            if(fa_x < fa_y) fa[fa_y] = fa_x;
            else fa[fa_x] = fa_y;
        }
    };
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UF uf(26);
        for(int i = 0; i < s1.length(); ++i) {
            uf.Union(s1[i]-'a', s2[i]-'a');
        }
        
        for(char &ch: baseStr) {
            ch = uf.find(ch-'a') + 'a';
        }
        return baseStr;
    }
};
```