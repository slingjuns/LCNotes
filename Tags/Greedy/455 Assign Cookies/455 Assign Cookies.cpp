// Date: September 29, 2022
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        multiset<int> cookies(s.begin(), s.end());
        int res = 0;
        for (auto gre: g) {
            auto it = cookies.lower_bound(gre);
            if(it != cookies.end()) {
                res++;
                cookies.erase(it);
            }
            else return res;
        }
        return res;
    }
};
