// Date: September 16, 2022
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // sort based on earliest end time
        if (intervals.size()==0) return true;
        sort(intervals.begin(), intervals.end(), [](auto &a1, auto& a2){
            return a1[1] < a2[1];
        });
        auto *prev = &intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if ((*prev)[1] > intervals[i][0]) return false;
            prev = &intervals[i];
        }
        return true;
    }
};
