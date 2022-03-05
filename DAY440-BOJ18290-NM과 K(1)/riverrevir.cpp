#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int arr[11][11];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
bool v[11][11];
int ret = -987654321;
bool check(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (v[ny][nx]) return false;
    }
    return true;
}
void go(int y, int x, int cnt, int sum) {
    if (cnt == k) {
        ret = max(ret, sum);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j]) continue;
            if (check(i, j)) {
                v[i][j] = true;
                go(i, j, cnt + 1, sum + arr[i][j]);
                v[i][j] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    go(0, 0, 0, 0);
    cout << ret;
}
