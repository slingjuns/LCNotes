// Date: October 4, 2023
class Solution {
public:
    int minSteps(string s, string t) {
        // equal length
        vector<int> h_s(26, 0), h_t(26, 0);
        for(int i = 0; i < s.length(); ++i) {
            h_s[s[i]-'a']++;
            h_t[t[i]-'a']++;
        }
        
        int res = 0;
        for(int i = 0; i < 26; ++i) {
            auto diff = h_t[i]-h_s[i];
            if(diff > 0) res += diff;
        }
        return res;
    }
    
    
};
