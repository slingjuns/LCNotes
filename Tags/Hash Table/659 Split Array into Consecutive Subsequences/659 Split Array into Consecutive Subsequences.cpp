// Date: October 2, 2022
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> seq;  // stores seq end number -> count
        unordered_map<int, int> count; // stores num -> num occurrences
        for (auto num: nums) count[num]++;
        
        for (auto num: nums) {
            if (count[num] == 0) continue;
            if (seq[num-1]) { // add to exist sequence
                seq[num-1]--;
                seq[num]++;
                count[num]--;
            } else { // start a new sequence
                for (int i = 0; i < 3; ++i) {
                    if (!count[num+i]) return false;
                    count[num+i]--;
                }
                seq[num+2]++;
            }
        }
        return true;
    }
};
