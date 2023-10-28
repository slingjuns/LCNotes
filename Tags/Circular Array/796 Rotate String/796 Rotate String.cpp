// Date: October 28, 2023
class Solution {
public:
    bool rotateString(string s, string goal) {
        // "cedabcdeab"
        if(s.length() != goal.length()) return false;
        goal = goal + goal;
        for(int i = 0; i+s.length()-1 < goal.length(); ++i) {
            auto tmp = goal.substr(i, s.length());
            if(tmp == s) return true;
        }
        return false;
    }
};
