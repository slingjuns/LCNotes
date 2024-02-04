// Date: February 4, 2024
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> m;
        int res = 0;
        for(int i = 0; i < time.size(); ++i) {
            int cur = time[i];
            res += m[(60 - cur % 60) % 60];
            m[cur % 60]++;
        }
        return res;
    }
};
