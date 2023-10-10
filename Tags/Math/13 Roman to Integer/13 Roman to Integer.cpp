// Date: October 10, 2023
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int res = 0;
        for(int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if(i <= s.length()-1 && m[ch] < m[s[i+1]]) res -= m[ch];
            else res += m[ch];
        }
        return res;
    }
};
