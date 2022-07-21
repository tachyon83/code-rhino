#include <cstdio>
 
using namespace std;
 
int map[20][20];
 
// now : 0 가로, 1 세로, 2 대각선
int dx[3][3] = {{0, 0, 1}, {0, 1, 1}, {0, 1, 1}};
int dy[3][3] = {{1, 0, 1}, {0, 0, 1}, {1, 0, 1}};
 
int n;
int ans = 0;
void dfs(int x, int y, int now) {
    if (x == n-1 && y == n-1) {
        ans += 1;
        return;
    }
    for (int i = 0; i < 3; i++) {
 
        // 설치할 수 없을 경우 제외하기
        if (dx[now][i] == 0 && dy[now][i] == 0) continue;
 
        int nx = x + dx[now][i];
        int ny = y + dy[now][i];
 
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
 
            // 가로 또는 세로로 설치할 경우
            if (i == 0 || i == 1) {
                if (map[nx][ny] == 0) dfs(nx, ny, i);
            }
 
            // 대각선으로 설치할 경우
            else if (i == 2) {
                if (map[nx][ny] == 0 && map[nx-1][ny] == 0 && map[nx][ny-1] == 0) {
                    dfs(nx, ny, i);
                }
            }
        }
    }
}
 
int main() {
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) map[i][j] = -1;
        }
    }
 
    dfs(0, 1, 0);
    printf("%d\n", ans);
}
