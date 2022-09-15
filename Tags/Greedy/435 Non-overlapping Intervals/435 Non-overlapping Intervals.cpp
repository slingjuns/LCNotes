// Date: September 15, 2022
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort
        sort(intervals.begin(), intervals.end(), [](auto &a1, auto& a2){
            return a1[1] < a2[1];
        });
        // choose smallest end interval first
        int count = 0;
        vector<int> kept{intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            auto &el = intervals[i];
            if (kept[1] > el[0]) {
                // copy(el.begin(), el.end(), ostream_iterator<int>(cout, ", "));
                // copy(kept.back().begin(), kept.back().end(), ostream_iterator<int>(cout, ", "));
                count++;
            } else {
                kept = el;
            }
        }
        return count;
    }
};
