// Date: April 16, 2023
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<int> arr;
        unordered_set<int>Set(nums.begin(), nums.end());
        unordered_map<int, int> sb2count; // # set bits to count
        // remove duplicate
        long long res = 0;
        for (auto x: Set)
        {
            sb2count[__builtin_popcount(x)]++;
            arr.push_back(__builtin_popcount(x));        
        }
        
        sort(arr.begin(), arr.end());
        set<int> self_pairs;
        // num1 or num2 + num1 and num2 <==> arr[i] + arr[j] >= k
        for (int i = 0; i < arr.size(); ++i) {
            auto low = lower_bound(arr.begin(), arr.end(), k-arr[i]);
            res += arr.end() - low;
        }
        return res;
    }
};
