// Date: October 17, 2023
class Solution {
private:
    int maxRect1D(vector<int>& m) {
        deque<int> st; // monotonic increasing stack
        m.push_back(-1);
        int res = 0;
        for(int i = 0; i < m.size(); ++i) {
            while(!st.empty() && m[st.back()] >= m[i]) {
                int curr_index = st.back();
                st.pop_back();
                int left = st.empty() ? -1 : st.back();
                res = max(res, (i-left-1) * m[curr_index]);
            }
            st.push_back(i);
        }
        return res;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // 2D => 1D
        vector<int> m(matrix[0].size(), 0);
        int res = 0;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == '0') m[j] = 0;
                else m[j] += 1;
            }
            res = max(res, maxRect1D(m));
        }
        
        return res;
    }
};
