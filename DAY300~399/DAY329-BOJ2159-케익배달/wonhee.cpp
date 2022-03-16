#include<iostream>
using namespace std;
#define LLONGMAX 10000000000000
long long int dp[100001][5];
int d[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };
int start[2];

int main()
{
	cin.tie(0);	cout.tie(0);
	cin.sync_with_stdio(0);
    int N; cin >> N;
    cin >> start[0] >> start[1];
    int y, x; cin >> y >> x;
    for (int i = 0; i < 5; i++) {
        long long minDist = LLONGMAX;
        for (int j = 0; j < 5; j++) {
            long long temp = abs(y + d[i][0] - start[0]) + abs(x + d[i][1] - start[1]);
            minDist = min(minDist, temp);
        }
        dp[0][i] = minDist;
    }
    start[0] = y; start[1] = x;

    for (int i = 1; i < N; i++) {
        cin >> y >> x;
        for (int j = 0; j < 5; j++) {
            long long minDist = LLONGMAX;
            for (int k = 0; k < 5; k++) {
                long long temp = dp[i - 1][k] + abs(y + d[j][0] - (start[0] + d[k][0]))
                    + abs(x + d[j][1] - (start[1] + d[k][1]));
                minDist = min(minDist, temp);
            }
            dp[i][j] = minDist;
        }
        start[0] = y; start[1] = x;
    }

    long long result = dp[N-1][0];
    for (int i = 1; i < 5; i++)
        result = min(result, dp[N-1][i]);
    cout << result << '\n';
}