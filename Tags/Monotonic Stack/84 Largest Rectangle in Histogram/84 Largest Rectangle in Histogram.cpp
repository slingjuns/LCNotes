// Date: October 16, 2023
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        // monotonic increasing stack, find left and right next smaller element
        h.push_back(0);
        deque<int> st;
        int res = 0;
        for(int i = 0; i < h.size(); ++i) {
            auto tmp = h[i];
            while(!st.empty() && h[st.back()] >= tmp) { // Increasing Stack
                auto cur_index = st.back();
                st.pop_back();
                int left = st.empty() ? -1 : st.back();
                // i is the next smaller element for cur_index, st.back() is the prev smaller element for cur_index
                res = max(res, (i-left-1)*h[cur_index]);
            }
            st.push_back(i);
        }
        return res;
    }
};
