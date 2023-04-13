// Date: April 13, 2023
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> counter;
        int res = 0;
        for (auto num: nums){
            res += counter[num]++;
        }
        return res;
    }
};
