#include<iostream>
#include<string.h>
using namespace std;
int dp[2][1001][1001];

int dfs(int turn, int start, int end, int arr[1001]) {
    if (start == end)
        return (turn == 0) ? arr[start] : 0;
    
    int& ref = dp[turn][start][end];
    if (ref != -1)
        return ref;

    if (turn == 0)
        ref = max(dfs((turn + 1) % 2, start + 1, end, arr) + arr[start], dfs((turn + 1) % 2, start, end - 1, arr) + arr[end]);
    else
        ref = min(dfs((turn + 1) % 2, start + 1, end, arr), dfs((turn + 1) % 2, start, end - 1, arr));
    return ref;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        memset(dp, -1, sizeof(dp));
        int N; cin >> N;
        int arr[1001];
        for (int i = 0; i < N; ++i)
            cin >> arr[i];
        cout << dfs(0, 0, N - 1, arr) << '\n';
    }
    return 0;
}
