// Date: November 1, 2023
class Solution {
public:
    int longestSubarray(vector<int>& A, int limit) {
        deque<int> max_q, min_q;
        int res = 1;
        int left = 0;
        for(int i = 0; i < A.size(); ++i) {
            while(!max_q.empty() && A[max_q.back()] < A[i]) max_q.pop_back();
            while(!min_q.empty() && A[min_q.back()] > A[i]) min_q.pop_back();
            max_q.push_back(i);
            min_q.push_back(i);
            while (A[max_q.front()] - A[min_q.front()] > limit) {
                if (max_q.front() == left) max_q.pop_front();
                if (min_q.front() == left) min_q.pop_front();
                ++left;
            }
            res = max(res, i-left+1);
        }
        return res;
    }
};
