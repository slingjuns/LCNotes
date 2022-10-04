// Date: October 4, 2022
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (auto str: queries) {
            int left = 0; int right = 0;
            while (left < str.length() && right < pattern.length()) {
                char s_left = str[left], r_left = pattern[right];
                if (s_left == r_left) {
                    left++; 
                    right++;
                } else {
                    if (isupper(s_left)) break;
                    left++;
                }
            }
            if (right == pattern.length() && find_if(str.begin()+left, str.end(), [](const char s){
                return isupper(s);
            }) == str.end()) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};
