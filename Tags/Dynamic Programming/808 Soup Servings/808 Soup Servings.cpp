// Date: October 6, 2023
class Solution {
    map<pair<int,int>, double> dp;
public:
    double memo(int A, int B) {
        if(A <= 0 && B > 0) return 1;
        if(A <= 0 && B <= 0) return 0.5;
        if(A > 0 && B <= 0) return 0;
        if(dp.count({A,B})) return dp[{A,B}];
        dp[{A,B}] = 0.25 *  (memo(A-100, B) + memo(A-75, B-25) + memo(A-50, B-50) + memo(A-25, B-75));
        return dp[{A,B}];
    }
    
    double soupServings(int n) {
        if (n>5000) return 1;
        return memo(n, n);
    }
};
