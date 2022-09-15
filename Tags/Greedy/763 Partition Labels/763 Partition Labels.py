// Date: September 15, 2022
class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, size_t> mem;
        vector<int> res;
        // first pass
        for (size_t i = 0; i < s.length(); ++i) {
            mem[s[i]] = i;
        }
        // second pass
        size_t prev = 0;
        size_t max_reach = 0;
        for (size_t i = 0; i < s.length(); i++) {
            if ((i == mem[s[i]] && max_reach <= mem[s[i]]) || i == s.length()-1) {
                res.push_back(int(i-prev+1));
                prev = i+1;
            }
            max_reach = max(max_reach, mem[s[i]]);
        }
        return res;
    }
};
