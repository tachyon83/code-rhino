class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();

        if (!rowSize) {
            return false;
        }
        int colSize = matrix[0].size();
        for (int r = 0, c = colSize - 1; r < rowSize && c >= 0; matrix[r][c] > target ? c-- : r++) {
            if (matrix[r][c] == target) {
                return true;
            }
        }
        return false;
    }
};