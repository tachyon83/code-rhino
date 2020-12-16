class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int answer = 0;
        
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= triangle[i].size() - 1; j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        
        answer = triangle[0][0];

        return answer;
    }
};
