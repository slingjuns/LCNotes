// Date: April 30, 2023
class Solution {
private:
    pair<int,int> convert(vector<vector<int>>& matrix, int index) {
        return {index / matrix[0].size(), index % matrix[0].size()};
    } 
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() * matrix[0].size()-1, mid;
        while (l < r) {
            mid = l + (r-l)/2;
            auto p = convert(matrix, mid);
            auto i = p.first, j = p.second;
            if(matrix[i][j] >= target) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        
        auto p = convert(matrix, l);
        auto i = p.first, j = p.second;
        return matrix[i][j] == target ? true : false;
    }
};
