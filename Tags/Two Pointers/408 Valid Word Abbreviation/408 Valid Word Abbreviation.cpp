// Date: September 25, 2022
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        stringstream ss(abbr);
        int l1 = 0, l2 = 0;
        int tmp = 0;
        while (l1 < word.length() && ss.rdbuf()->in_avail()) {
            char ch = word[l1], abbr_ch = ss.peek();
            if (!isdigit(abbr_ch) && ch != abbr_ch) return false;
            if (isdigit(abbr_ch)) {
                if (abbr_ch == '0') return false;
                ss >> tmp;
                l1 += tmp;
            } else {
                ss >> abbr_ch;
                l1++;
            }
        }
        return l1 == word.length() && !ss.rdbuf()->in_avail();
    }
};
