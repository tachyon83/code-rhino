#include <iostream>

using namespace std;
int arr[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;

        for (int j = 1; j <= i; j++) {
            if (arr[j] > arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    int result = dp[1];
    for (int i = 2; i <= n; i++) {
        if (result < dp[i]) {
            result = dp[i];
        }
    }
    
    cout << result << '\n';

    return 0;
}
