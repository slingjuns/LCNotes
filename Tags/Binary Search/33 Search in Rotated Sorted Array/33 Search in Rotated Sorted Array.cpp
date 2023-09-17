// Date: September 17, 2023
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[left]) { // subarray on mid's left is sorted
                cout << "Left sorted MId:  " << nums[mid] << endl;
                if (target >= nums[left] && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else { // subarray on mid's right is sorted
                // cout << "Right sorted MId:  " << nums[mid] << "  " << (target <= nums[right-1]) <<  (target > nums[mid]) << endl;
                if (target <= nums[right-1] && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        cout << left;
        return -1;
    }
};
