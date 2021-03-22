#include <iostream>

using namespace std;

int num[20];
int cnt;
int n; int s;

void solve(int res, int now) {
    if (now == n) {
        return;
    }
    if (res + num[now] == s) {
        ++cnt;
    }
    solve(res+num[now], now + 1);
    solve(res, now + 1);
}

int main() {
    cnt = 0;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    solve(0, 0);
    cout << cnt;
    return 0;
}
