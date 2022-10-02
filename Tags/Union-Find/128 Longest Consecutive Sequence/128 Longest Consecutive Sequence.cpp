// Date: October 2, 2022
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cache;
        for (auto num: nums) {
            cache.insert(num);
        }
        int longest = 0;
        for (auto num: nums) {
            int seq = 1;
            int cur = num;
            while (cache.count(cur+1)) { // search backwards
                seq++;
                cur = cur+1;
                cache.erase(cur);
            }
            cur = num;
            while (cache.count(cur-1)) { // search forwards
                seq++;
                cur = cur-1;
                cache.erase(cur);
            }
            longest = max(seq, longest);
        }
        return longest;
    }
};
