#include <bits/stdc++.h>
 
#define INF 0x3f3f3f3f3f3f3f3fLL
#define ft first
#define sd second
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
 
int n;
ll d[111'111][5];
pll p[111'111];
int dx[] = {0, 0, 1, 0, -1}, dy[] = {0, 1, 0, -1, 0};
 
ll getDist(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
 
ll go(int i, int j, int x, int y) {
    if (i == n) return 0;
    ll &ret = d[i][j];
    if (ret != -1) return ret;
    ret = INF;
    for (int k = 0; k < 5; k++) {
        ll nx = p[i + 1].ft + dx[k];
        ll ny = p[i + 1].sd + dy[k];
        ret = min(ret, go(i + 1, k, nx, ny) + getDist(x, y, nx, ny));
    }
 
    return ret;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n;
    memset(d, -1, sizeof(d));
    cin >> p[0].ft >> p[0].sd;
    for (int i = 1; i < n + 1; i++) {
        cin >> p[i].ft >> p[i].sd;
    }
    cout << go(0, 0, p[0].ft, p[0].sd);
}
