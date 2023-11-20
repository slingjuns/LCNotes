class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row, col = 0, len(matrix[0])-1
        while row < len(matrix) and col >= 0:
            top_right = matrix[row][col]
            if top_right == target: return True
            if top_right > target: col -= 1
            else: row += 1
        return False
