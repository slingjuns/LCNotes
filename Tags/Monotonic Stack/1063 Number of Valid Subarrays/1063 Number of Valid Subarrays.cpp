// Date: October 16, 2023
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        // for each ith element, find its next smaller
        nums.push_back(-1);
        deque<int> st;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            while(!st.empty() && nums[st.back()] > nums[i]) { // next smaller
                res += i-st.back();
                st.pop_back();
            }
            st.push_back(i);
        }
        return res;
    }
};
