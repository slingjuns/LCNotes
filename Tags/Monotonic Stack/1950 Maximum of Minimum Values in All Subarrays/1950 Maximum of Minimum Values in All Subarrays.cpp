// Date: October 18, 2023
class Solution {
public:
    vector<int> findMaximums(vector<int>& nums) {
        map<int, int> m; // num -> maximum length of subarray whose minimum is num
        vector<int> res(nums.size(), -1);
        deque<int> st;
        nums.push_back(-1);
        for(int i = 0; i < nums.size(); ++i) {
            while(!st.empty() && nums[st.back()] > nums[i]) { // next smaller
                int curr_index = st.back();
                st.pop_back();
                int left = st.empty() ? -1 : st.back();
                int L = i-left-1;
                m[nums[curr_index]] = max(m[nums[curr_index]], L);
            }
            st.push_back(i);
        }
        for(auto it = m.rbegin(); it != m.rend(); ++it) {
            auto num = it->first, L = it->second;
            for(int i = 1; i <= L; ++i) {
                if(res[i-1] != -1) continue;
                res[i-1] = num;
            }
        }
        return res;
    }
};
