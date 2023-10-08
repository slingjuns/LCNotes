// Date: October 8, 2023
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if(topRight[0] < bottomLeft[0] || topRight[1] < bottomLeft[1]) return 0;
        bool res = sea.hasShips(topRight, bottomLeft);
        if(topRight == bottomLeft || res == false) return res;
        vector<int> mid = {(bottomLeft[0] + topRight[0]) >> 1, (bottomLeft[1] + topRight[1]) >> 1};
        vector<int> midp1 = {mid[0]+1, mid[1]+1};
        vector<int> bottomMidp1 = {mid[0]+1, bottomLeft[1]};
        vector<int> topMid = {mid[0], topRight[1]};
        vector<int> leftMidp1 = {bottomLeft[0], mid[1]+1};
        vector<int> rightMid = {topRight[0], mid[1]};
        return countShips(sea, mid, bottomLeft) + countShips(sea, topRight, midp1) + countShips(sea, rightMid, bottomMidp1) + countShips(sea, topMid, leftMidp1);
    }
};
