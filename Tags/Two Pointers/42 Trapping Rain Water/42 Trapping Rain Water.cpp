// Date: October 2, 2023
class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0, r = h.size()-1, res = 0;
        int max_l = h[l], max_r = h[r];

        while (l < r) {
            if(max_l > max_r) {
                res += max_r-h[r--];
                max_r = max(max_r, h[r]);
            } else {
                res += max_l-h[l++];
                max_l = max(max_l, h[l]);
            }
        }
        return res;
    }
};
