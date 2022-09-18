// Date: September 18, 2022
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](const auto &a1, const auto&a2){
            const auto d1 = pow(a1[0], 2) + pow(a1[1], 2);
            const auto d2 = pow(a2[0], 2) + pow(a2[1], 2);
            return d1 < d2;
        });
        vector<vector<int>> res(points.begin(), points.begin()+k);
        return res;
    }
};
