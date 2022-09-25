// Date: September 25, 2022
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size()-1;
        int boats = 0;
        while (left <= right) {
            int sum = people[left] + people[right];
            if (sum > limit) {
                right--;
            } else {
                right--;
                left++;
            }
            boats++;
            if (left == right) {
                return boats;
            }
        }
        return boats;
    }
};
