// Date: October 4, 2022
class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        string prev = countAndSay(n-1);
        int left = 0; 
        string res = "";
        while (left < prev.length()) {
            int count = 1; 
            char ch = prev[left];
            left++;
            while (left > 0 && left < prev.length() && ch == prev[left]) {
                count++;
                left++;
            }
            res += to_string(count) + ch;
        }
        return res;
    }
    
};
