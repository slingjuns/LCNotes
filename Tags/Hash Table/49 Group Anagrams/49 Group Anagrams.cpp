// Date: September 29, 2022
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
