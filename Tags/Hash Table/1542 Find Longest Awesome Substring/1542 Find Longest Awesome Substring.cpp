// Date: November 15, 2022
class Solution {
public:
    int longestAwesome(string s) {
        // 9876543210 digits
        // 0000000000 -> only allows one digit to be 1 (2's power)
        // 0010101000 -> we need to make two of three digit ones be zero -> 0010000000 or 000010000 or 0000001000 or 0000000000
        // i.e. 24241 => 0000000010, prefix =>  0000001010
        
        unordered_map<int, int> m = {{0, -1}};
        int res = 0, xor_pre = 0;
        for(int i = 0; i < s.length(); ++i) {
            xor_pre ^= 1 << (s[i]-'0');
            for(int j = 0; j <= 9; ++j) {
                int target = xor_pre ^ (1 << j);
                if(m.count(target)) res = max(res, i-m[target]);
            }
            // make to 0000000000
            int target = xor_pre ^ 0;
            if(m.count(target)) res = max(res, i-m[target]);
            if(!m.count(xor_pre)) m[xor_pre] = i;
        }
        return res;
    }
};
