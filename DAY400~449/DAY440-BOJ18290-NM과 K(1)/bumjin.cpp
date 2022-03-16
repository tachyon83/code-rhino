#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int arr[10][10];
bool check[10][10];
int ans = -210000000;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void go(int cnt, int sum) {
    if (cnt == k) {
        if (ans < sum) ans = sum;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j]) continue;
            bool ok = true;
            for (int z = 0; z < 4; z++) {
                int nx = i + dx[z];
                int ny = j + dy[z];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                    if (check[nx][ny]) ok = false;
            }
            if (ok) {
                check[i][j] = true;
                go(cnt + 1, sum+arr[i][j]);
                check[i][j] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    go(0, 0);
    cout << ans;
}
