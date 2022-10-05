// Date: October 5, 2022
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast = 0;
        int count = 0;
        while (fast < nums.size()) {
            int prev = nums[fast];
            while(fast < nums.size() && nums[fast] == prev) fast++;
            nums[slow++] = prev;
        }
        return slow;
    }
};
