# 721. Accounts Merge

Careful: Yes
Date: November 3, 2023
Difficulty: Medium
Elegant Code (Template): Union-Find
Index: 721
Programming Language: C++
Tags: Union-Find
Link: https://leetcode.com/problems/accounts-merge/

```cpp
class Solution {
public:
    unordered_map<string, string> fa;
    unordered_map<string, string> owners;
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // initialize union find
        for(auto account: accounts) {
            for(int i = 1; i < account.size(); ++i) {
                auto cur = account[i];
                if(fa.count(cur)) { // appeared in other group
                    Union(account[1], find(cur));
                } else {
                    fa[cur] = cur;
                    if(i > 1) Union(cur, account[i-1]);
                }
                owners[cur] = account[0];
            }
        }
        vector<vector<string>> res; 
        unordered_map<string, vector<string>> res_map;
        for(auto it = fa.begin(); it != fa.end(); ++it) {
            res_map[find(it->first)].push_back(it->first);
        }                                                          
        for(auto it = res_map.begin(); it != res_map.end(); ++it) {
            auto tmp = it->second;
            sort(tmp.begin(), tmp.end());
            tmp.insert(tmp.begin(), owners[it->first]);
            res.push_back(tmp);
        }
        return res;
    }
    
    string find(const string& x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    
    void Union(const string& a, const string& b) {
        auto fa_a = find(a), fa_b = find(b);
        if(fa_a < fa_b) fa[fa_b] = fa_a;
        else fa[fa_a] = fa_b;
    }
};
```