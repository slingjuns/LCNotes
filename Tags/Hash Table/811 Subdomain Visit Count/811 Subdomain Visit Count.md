# 811. Subdomain Visit Count

Careful: No
Date: October 1, 2022
Difficulty: Medium
Index: 811
Programming Language: C++
Skills: 1 Use string.find and string.substr to parse the text
Tags: Hash Table
Link: https://leetcode.com/problems/subdomain-visit-count/

```cpp
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, long> cache;
        for (auto cd: cpdomains){
            int i = cd.find(" ");
            int n = stoi(cd.substr (0, i));
            string domain = cd.substr(i+1);
            cache[domain] += n;
            while (domain.find(".") != string::npos) {
                domain = domain.substr(domain.find(".")+1);
                cache[domain] += n;
            }
        }
        vector<string> res;
        for (auto [k, v]: cache) {
            string s;
            s += to_string(v) + " " + k;
            res.push_back(s);
        }
        return res;
    }
    

};
```