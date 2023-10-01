// Date: October 1, 2023
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> m(26, 0);
        for(char c: s) m[c-'a']++;
        
        for(int i = 0; i < s.length(); ++i) {
            if(m[s[i]-'a'] == 1) return i;
        }
        
        return -1;
    }
};
