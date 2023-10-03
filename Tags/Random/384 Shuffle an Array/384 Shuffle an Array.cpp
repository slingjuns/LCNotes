// Date: October 3, 2023
class Solution {
private:
    vector<int> initial, curr;
    int n;
public:
    Solution(vector<int>& nums) {
        initial = nums;
        curr = nums;
        n = nums.size();
    }
    
    vector<int> reset() {
        return initial;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < n; ++i) {
            int randi = rand() % (n-i) + i; // random int [i, n]
            swap(curr[randi], curr[i]);
        }
        return curr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
