// Date: April 11, 2023
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> prefix2index;
        int presum = 0;
        int res = 0;
        prefix2index[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            presum += (nums[i] ? 1 : -1);
            if(prefix2index.count(presum)) {
                res = max(i - prefix2index[presum], res);
            } else {
                prefix2index[presum] = i;
            }
        }
        return res;
    }
};
