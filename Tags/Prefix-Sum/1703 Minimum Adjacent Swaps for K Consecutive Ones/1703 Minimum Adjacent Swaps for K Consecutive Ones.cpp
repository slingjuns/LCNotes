// Date: October 25, 2023
class Solution {
using LL = long long;
public:
    
    int minMoves(vector<int>& nums, int k) {
        vector<int> ones = {-1};
        vector<LL> prefix = {0};
        LL index_sum = 0;
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i]==1) {
                index_sum += i;
                ones.push_back(i);
                prefix.push_back(index_sum);
            }
        }

        // why i-1+k, i-1 is actual index in ones, i-1+k means the right of sliding window is within the array range
        for(int i = 1; i-1+k < ones.size(); ++i) {  
            // sliding window left =i, mid, right
            LL radius = k % 2 == 0 ? (k-2)/2 : (k-1)/2;
            LL mid = i+radius, right = i-1+k;
            LL center = ones[mid];
            // cout << i << " " << mid << " " << right << endl;
            LL upper_sum = prefix[mid+radius]-prefix[mid]; // sum of [mid+1 ... mid+radius]
            // cout << "Mid radius: " << mid+radius << " " << mid << endl;
            LL lower_sum = prefix[mid]-prefix[i-1]; // sum of [mid-radius ... mid]
            LL center_lower_sum = (center-radius+center) * (radius+1) / 2;
            LL center_upper_sum = (center+radius+center+1) * radius / 2;
            int moves = (upper_sum - center_upper_sum) + (center_lower_sum - lower_sum);
            // cout << "Sum: " << lower_sum << " " << upper_sum  << " " << center_lower_sum << " " << center_upper_sum << endl;
            if(k % 2 == 0) moves += ones[right]-(center+radius+1);
            res = min(res, moves);
        }
        return res;
    }
};
