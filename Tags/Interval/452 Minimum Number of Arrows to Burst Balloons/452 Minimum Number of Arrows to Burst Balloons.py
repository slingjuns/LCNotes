// Date: September 16, 2022
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // greedy based on end time
        // sort
        sort(points.begin(), points.end(), [](const auto &a1, const auto &a2) {
            return a1[1] < a2[1];
        });
        // pick overlapping intervals
        int count = 1;
        int shortest_arrow = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > shortest_arrow || points[i][1] < shortest_arrow) {
                shortest_arrow = points[i][1];
                count++;
            }
        }
        return count;
    }
};
