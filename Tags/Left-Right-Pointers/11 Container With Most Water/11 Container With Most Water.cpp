// Date: September 25, 2022
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxA = 0;
        while (left <= right) {
            int hl = height[left], hr = height[right];
            maxA = max(maxA, min(height[left], height[right])*(right-left));
            if (hl < hr) {
                while(left <= right && height[left] <= hl) {
                    left++;
                }
            } else {
                while (left <= right && height[right] <= hr) {
                    right--;
                }
            }
        }
        return maxA;
    }
};
