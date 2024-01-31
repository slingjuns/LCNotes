// Date: January 31, 2024
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int top = arr[0], max_v = top;
        deque<int> dq;
        for(int i = 1; i < arr.size(); ++i) {
            dq.push_back(arr[i]);
            max_v = max(max_v, arr[i]);
        }
        
        unordered_map<int, int> win_count;
        bool end = false;
        while(!end) {
            int next = dq.front();
            if(top > next) {
                win_count[top]++;
                dq.pop_front();
                dq.push_back(next);
            } else {
                win_count[next]++;
                dq.pop_front();
                dq.push_back(top);
                top = next;
            }
            // pruning
            if(win_count[top] >= k || top == max_v) end=true;
        }
        return top;
    }
};
