#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[301][301];
bool check[301][301];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
queue<pair<int, int>> qu;
int ret;
void bfs(int y, int x) {
    qu.push({ y,x });
    check[y][x] = true;
    while (!qu.empty()) {
        int oy = qu.front().first;
        int ox = qu.front().second;
        qu.pop();
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + oy;
            int nx = dx[i] + ox;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (check[ny][nx]) continue;
            if (arr[ny][nx] == 0) {
                if (arr[oy][ox] > 0) {
                    arr[oy][ox] -= 1;
                }
            }
            else {
                qu.push({ ny,nx });
                check[ny][nx] = true;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    while (true) {
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] != 0 && !check[i][j]) {
                    flag = true;
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        ret++;
        if (cnt >= 2) {
            cout << ret-1;
            break;
        } 
        if (!flag&&cnt<2) {
            cout << 0;
            break;
        }
        memset(check, false, sizeof(check));
         
    }
}
