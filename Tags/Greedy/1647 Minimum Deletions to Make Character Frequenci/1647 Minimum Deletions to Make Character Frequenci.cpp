// Date: October 24, 2023
class Solution {
using PII = pair<int,int>;
public:
    int minDeletions(string s) {
        // ceabaacb => 1,2,2,3 => greedy
        // aaabbbcc => 3,3,2 => 
        unordered_map<int,int> freq;
        for(char c: s) freq[c]++;
        
        unordered_set<int> unique;
        int res = 0;
        for(auto i = freq.begin(); i != freq.end(); ++i) {
            auto cur_freq = i->second;
            while(cur_freq && unique.count(cur_freq)) { // not unique
                cur_freq--;
                res++;
            }
            if(cur_freq != 0) unique.insert(cur_freq);
        }
        
        return res;
    }
};
