// Date: October 26, 2023
class Solution {
public:
    int bestClosingTime(string customers) {
        // [1,1,0,1] prefix sum
        vector<int> prefix_y = {0}, prefix_n = {0};
        int sum = 0, n = customers.size();
        for(int i = 0; i < customers.size(); ++i) {
            if(customers[i] == 'Y') sum += 1;
            prefix_y.push_back(sum);
            prefix_n.push_back(i+1-sum);
        }
        prefix_y.push_back(sum);
        prefix_n.push_back(0);
        
        int min_penalty = INT_MAX, res = INT_MAX;
        for(int i = 1; i < prefix_y.size(); ++i) {
            // compute penalty closed at i
            int penalty_i = prefix_n[i-1] + (prefix_y[n]-prefix_y[i-1]);
            if(penalty_i < min_penalty) {
                res = i-1;
                min_penalty = penalty_i;
            }
        }
        return res;
    }
};
