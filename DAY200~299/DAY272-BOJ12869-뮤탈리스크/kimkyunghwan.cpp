#include <bits/stdc++.h>
using namespace std;
int dp[61][61][61];
int dx[6] = { 1,1,3,3,9,9 };
int dy[6] = { 3,9,1,9,1,3 };
int dz[6] = { 9,3,9,1,3,1 }; //6가지 상태
int a[4];
 
int f(int x) {return max(0, x);}
 
int go(int x, int y, int z) {
    if (!x && !y && !z) return 0; // 모두 0이면 종료
    int& ret = dp[x][y][z];
    if (ret != -1) return ret;
    ret = 1e9;
    for (int k = 0; k < 6; k++) { //6가지 순회하며 최솟값 갱신
        ret = min(ret, go(f(x-dx[k]), f(y-dy[k]), f(z-dz[k])) + 1);
    }
    return ret;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = go(a[0], a[1], a[2]);
    cout << ans << '\n';
}
