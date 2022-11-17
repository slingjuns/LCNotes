# 446. Arithmetic Slices II - Subsequence

Careful: Yes
Date: November 17, 2022
Difficulty: Hard
Elegant Code (Template): Dynamic Programming, Subsequence
Index: 446
Programming Language: C++
Skills: 1. Subsequence with DP
Tags: Dynamic Programming, Hash Table
Link: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

## **Idea**

- Let `dp[i][d]` denotes the number of subsequences (have at least 2 numbers) that **ends with `nums[i]` and its common difference is `d`**.
- For `i` in `[1..n-1]`
    - For `j` in `[0..i-1]`:
        - `diff = nums[i] - nums[j]`
        - `dp[i][diff] += dp[j][diff] + 1`
        - `ans += dp[j][diff]` // We += dp[j][diff] because it's the number of valid subsequences (have >= 3 elements). But dp[i][diff] is the number of valid subsequences (have >= 2 elements).
    
    ![Untitled](Untitled%203.png)
    

```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size();
        int ans = 0;
        vector<unordered_map<long long, int>> dp(n); // dp[i][d]
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long) nums[i] - nums[j];
                int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff] += cnt + 1;
                ans += cnt;
            }
        }
        return ans;
    }
};
```