// Date: October 2, 2023
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+2, 0), res(n+1, 0);
        // initialize diff array
        for(auto booking: bookings) {
            auto i = booking[0], j = booking[1], k = booking[2];
            diff[i]+= k;
            diff[j+1]-= k;
        }
        
        auto sum = 0;
        for(int i = 1; i < res.size(); ++i) {
            sum += diff[i];
            res[i] = sum;
        }
        res.erase(res.begin());
        return res;
    }
};
