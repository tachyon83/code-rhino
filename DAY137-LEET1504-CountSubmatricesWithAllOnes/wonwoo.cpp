class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> row(m, 1);
            for (int y = i; y < n; y++) {
                for (int x = 0; x < m; x++) {
                    row[x] &= mat[y][x];
                }
                ans += count(row);
            }
        }

        return ans;
    }

    int count(vector<int>& row) {
        int ans = 0;
        int length = 0;
        int size = row.size();

        for (int i = 0; i < size; i++) {
            length = row[i] == 0 ? 0 : length + 1;
            ans += length;
        }

        return ans;
    }
};