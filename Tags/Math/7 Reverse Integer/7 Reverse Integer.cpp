// Date: October 21, 2023
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        int tmp = abs(x);
        int res = 0;
        while (tmp){
            if(res > INT_MAX/10 ) return 0;
            res = res * 10 + tmp % 10;
            tmp /= 10;
        }
        if(x < 0) res *= -1;
        return res;
    }
};
