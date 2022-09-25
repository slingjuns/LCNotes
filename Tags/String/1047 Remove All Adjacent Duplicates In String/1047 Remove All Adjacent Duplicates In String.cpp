// Date: September 25, 2022
class Solution {
public:
    string removeDuplicates(string s) {
        // stack
        string res = "";
        for(int i = 0; i < s.length(); ++i) {
            bool pop = false;
            while(!res.empty() && res.back() == s[i]) {
                res.pop_back();
                pop = true;
            }
            if(!pop) res.push_back(s[i]);
        }
        return res;
    }
};
