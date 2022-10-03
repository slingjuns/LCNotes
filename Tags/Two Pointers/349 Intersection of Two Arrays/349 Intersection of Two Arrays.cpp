// Date: October 3, 2022
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int left = 0, right = 0;
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        while (left < nums1.size() && right < nums2.size()) {
            if (nums1[left] == nums2[right]) {
                res.push_back(nums1[left]);
                left++;
                right++;
            }
            else if (nums1[left] < nums2[right]) {
                left++;
            } else {
                right++;
            }
            while(left > 0 && left < nums1.size() && nums1[left] == nums1[left - 1]) left++;
            while(right > 0 && right < nums2.size() && nums2[right] == nums2[right - 1]) right++;
        }
        return res;
    }
};
