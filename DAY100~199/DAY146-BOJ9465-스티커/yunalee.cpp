#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001][2];
int maxArr[100001][3] = { 0, };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i][0];
        }
        for (int i = 1; i <= n; i++) {
            cin >> arr[i][1];
        }

        for (int i = 1; i <= n; i++) {
            maxArr[i][0] = max({ maxArr[i - 1][0],maxArr[i - 1][1],maxArr[i - 1][2] });
            maxArr[i][1] = max(maxArr[i - 1][0], maxArr[i - 1][2]) + arr[i][0];
            maxArr[i][2] = max(maxArr[i - 1][0], maxArr[i - 1][1]) + arr[i][1];
        }
        int result = max({ maxArr[n][0], maxArr[n][1], maxArr[n][2] });
        cout << result << '\n';
    }
    return 0;
}
