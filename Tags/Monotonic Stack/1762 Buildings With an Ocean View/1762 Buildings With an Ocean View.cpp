// Date: October 18, 2023
class Solution {
public:
    vector<int> findBuildings(vector<int>& h) {
        vector<int> st; // next greater, monotonic decreasing
        for(int i = 0; i < h.size(); ++i) {
            while(!st.empty() && h[st.back()] <= h[i]) {
                st.pop_back();
            }
            st.push_back(i);
        }
        return st;
    }
};
