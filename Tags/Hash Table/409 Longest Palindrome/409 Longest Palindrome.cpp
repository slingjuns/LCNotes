// Date: October 2, 2022
class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        map<char, int> cache;
        for (auto ch: s) {
            cache[ch]++;
        }
        int flag = 0;
        for (auto [k, v]: cache){
            if (v % 2 == 0) res += v;
            else {
                res += v-1;
                flag = 1;
            }
        }
        return res+flag;
    }
};
