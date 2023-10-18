// Date: October 18, 2023
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // find xor sum == 0    
        unordered_map<int, vector<int>> m={{0,{-1}}};
        int xor_pre = 0, res = 0;
        for(int i = 0; i < arr.size(); ++i) {
            xor_pre ^= arr[i];
            int target = xor_pre ^ 0; // 0 is target xor_sum
            for(auto j: m[target]) {
                res += max(0, i-(j+1));
            }
            m[xor_pre].push_back(i);
        }
        return res;
    }
};
