class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        for (int i = size - 2; i >= 0; i--) {
            int lineSize = triangle[i].size();
            for (int j = 0; j < lineSize; j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};