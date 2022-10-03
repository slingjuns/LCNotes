// Date: October 3, 2022
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> zero_index;
        int left = 0, right = 0;
        int res = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) zero_index.push(right);
            if (zero_index.size() > k) {
                int jumpto = zero_index.front();
                left = jumpto+1;
                zero_index.pop();
            }
            res = max(res, right-left+1);
            right++;
        }
        return res;
    }
};
