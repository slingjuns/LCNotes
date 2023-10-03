// Date: October 3, 2023
class Solution {
private:
    int res = 0;
    vector<int> tmp;
public:
    int reversePairs(vector<int>& nums) {
        tmp.resize(nums.size(), 0);
        mergeSort(nums, 0, nums.size()-1);
        return res;
    }
    
    void mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r) return;
        int mid = l + r >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid+1, r);
        // count
        for(int j = mid+1; j <= r; ++j) {
           auto it = upper_bound(nums.begin()+l, nums.begin()+mid+1, (long long)2 * nums[j]);
           res += nums.begin()+mid+1-it;
        }
        
        // merge
        int i = l, cur_l = l, cur_r = mid+1;
        
        
        while(cur_l <= mid && cur_r <= r) {
            if(nums[cur_r] > nums[cur_l]) tmp[i++] = nums[cur_l++];
            else tmp[i++] = nums[cur_r++];
        }
        while(cur_l <= mid) tmp[i++] = nums[cur_l++];
        while(cur_r <= r) tmp[i++] = nums[cur_r++];
        for(int j = l; j <= r; j++) {
            nums[j] = tmp[j];
        }
    }
};
