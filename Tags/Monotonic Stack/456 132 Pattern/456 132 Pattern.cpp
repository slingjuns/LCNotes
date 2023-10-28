// Date: October 28, 2023
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // monotonic decreasing - find prev greater
        // [4,6,2,5,9,4] => [4,6,5], [2,9,4]
        // 对于2 找prev greater element
        
        deque<int> st;
        nums.push_back(INT_MAX);
        
        vector<int> prefix_min(nums.size());
        int cur_min = INT_MAX;
        // preprocess prefix min
        for(int i = 0; i < nums.size(); ++i) {
            cur_min = min(cur_min, nums[i]);
            prefix_min[i] = cur_min;
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            // find "3" -- prev greater element
            while(!st.empty() && nums[st.back()] <= nums[i]) {
                int cur_i = st.back(); // current is "2"
                st.pop_back(); 
                int prev_greater = st.empty() ? -1 : st.back(); // prev_greater is "3"
                if(prev_greater != -1 && prefix_min[prev_greater] < nums[cur_i]) 
                    return true;
            }
            st.push_back(i);
        }
        return false;
    }
};
