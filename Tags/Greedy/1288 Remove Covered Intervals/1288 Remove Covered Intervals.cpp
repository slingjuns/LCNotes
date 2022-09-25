// Date: September 25, 2022
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end(), [](auto &v1, auto &v2) {
            if (v1[0] == v2[0]) return v1[1] > v2[1];
            return v1[0] < v2[0];
        });
        auto cur = intervals[0];
        int count = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            auto next = intervals[i];
            bool covered = next[1] <= cur[1];  // covered == overlap && next[1] < cur[1]
            if (covered) count++;
            else cur = next;
        }
        return intervals.size() - count;
    }
};
