#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int a[100][100];
int d[100][100];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int n,m;

void solution(int x, int y, int cnt) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    d[x][y] = cnt;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k=0; k<8; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] == 1 && d[nx][ny] == 0) {
                    q.push(make_pair(nx,ny));
                    d[nx][ny] = cnt;
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    while (true) {
        cin >> m >> n;
        if (n == 0 && m == 0){
            break;   
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> a[i][j];
                d[i][j] = 0;
            }
        }
        
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == 1 && d[i][j] == 0) {
                    solution(i, j, ++cnt);
                }
            }
        }
        
        cout << cnt << '\n';
    }
    return 0;
}
