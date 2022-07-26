#include <bits/stdc++.h>
using namespace std;
queue<int> qu;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n;
     
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int top = arr[0];
    int cnt = 0;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (top >= arr[i]) cnt++;
        else {
            top = arr[i];
            ans = max(ans, cnt);
            cnt = 1;
        }
    }

    cout << max(cnt, ans);
}
