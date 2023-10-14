// Date: October 14, 2023
class Solution {
public:
using LL = long long;
    int sumSubarrayMins(vector<int>& arr) {
        // for ith element, find prev smaller index left, find next smaller index right,
        // then count = (i-left) * (right - i)
        // 1 , 4, 2, 3, 5 => for index 2(val = 2), left = 0, right = 5
        // total = [4,2], [2], [2,3], [2,3,5], [4,2,3] [4,2,3,5] = 6
        deque<int> st;
        arr.push_back(0);
        LL res = 0, mod = 1e9+7;
        for(int i = 0; i < arr.size(); ++i) {
            while(!st.empty() && arr[st.back()] >= arr[i]) {
                int cur_index = st.back();
                st.pop_back();
                int left = st.empty() ? -1 : st.back();
                LL tmp = (cur_index-left) * (i-cur_index);
                res += (tmp % mod * arr[cur_index] % mod) % mod;
            }
            st.push_back(i);
        }
        return res % mod;
    }
};
