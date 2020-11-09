#include <iostream>
#include <vector>
using namespace std;
void DP(int max);
int dp[100001][4] = { 0, };
int main() {

	int N;
	int max = 0;
	cin >> N;
	vector<int> num(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		if (num[i] > max) {
			max = num[i];
		}
	}
	DP(max);

	for (int i = 0; i < N; i++) {
		int tmp = 0;
		for (int j = 1; j <= 3; j++) {
			tmp += dp[num[i]][j];
		}
		cout << tmp << endl;
	}
}

void DP(int max) {
	dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i <= max; i++) {
		dp[i][1] = 1;
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];

	}

}
