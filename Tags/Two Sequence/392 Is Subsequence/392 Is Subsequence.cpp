// Date: October 3, 2022
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0, right = 0;
        
        // if (t.length() < s.length()) swap(s, t);  // left string is always shorter than right
        while (left < s.length() && right < t.length()) {
            if (s[left] == t[right]) {
                left++;
                right++;
            } else {
                right++;
            }
        }
        return left >= s.length();
    }
};
