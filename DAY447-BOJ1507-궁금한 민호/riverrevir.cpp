#include <bits/stdc++.h>
using namespace std;
int d[21][21];
int d1[21][21];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
            d1[i][j] = d[i][j];
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || i == k || j == k) continue;
                if (d[i][j] == d[i][k] + d[k][j]) {
                    d1[i][j] = 0;
                }
                else if (d[i][j] > d[i][k] + d[k][j]) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ret += d1[i][j];
        }
    }
    cout << ret/2;
}
