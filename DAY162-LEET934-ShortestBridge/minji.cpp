using vi  = vector<int>;
using vvi = vector<vi>;
using island = set<pair<int, int>>;

class Solution {
public:
    int n;
    vi dx = { 0, 0, 1, -1 };
    vi dy = { 1, -1, 0, 0 };
    
    
    void sol(island& A, const vvi& g, int x, int y){
        A.insert({x, y});
            for(int i = 0; i < 4; i++){
                int nx = x +dx[i];
                int ny = y +dy[i];
                
                if (x >= 0 && x < n && y >= 0 && y < n) continue;
                if(g[nx][ny] && !A.count({nx, ny}))
                    sol(A, g, nx, ny);
                
            }
    }
    
    template<class T>
    int dist(T a, T b){
        return abs(a.first - b.first) + abs(a.second - b.second) - 1;
    }


    
    int shortestBridge(vector<vector<int>>& A) {
        n = A.size();
        island a, b;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(A[i][j] == 0)
                    continue;
                if (a.empty())
                    sol(a, A, i, j);
                else if (b.empty() && !a.count({i, j}))
                    sol(b, A, i, j);
            }
        }
        int ans = 2* n;
        for (auto i:a)
            for (auto j:b)
                ans = min(ans, dist(i, j));
        return ans;
    }
};
