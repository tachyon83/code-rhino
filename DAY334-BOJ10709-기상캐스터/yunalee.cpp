#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000

using namespace std;

int H, W;
int dp[110][110];
bool arr[110][110];

int solved(int h, int w) {
	if (dp[h][w] == 0 && w == 1) {
		if (arr[h][w] == true) {
			dp[h][w] = 0;
		}
		else {
			dp[h][w] = -1;
		}
	}

	if (dp[h][w] == 0 && w > 1) {
		if (arr[h][w] == true) {
			dp[h][w] = 0;
		}
		else {
			if (dp[h][w - 1] != -1) {
				dp[h][w] = solved(h, w - 1) + 1;
			}
			else {
				dp[h][w] = -1;
			}
		}
	}

	return dp[h][w];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> H >> W;

	for (int i = 1; i <= H; i++) {
		string str;
		cin >> str;

		for (int j = 1; j <= W; j++) {
			if (str[j - 1] == 'c') {
				arr[i][j] = true;
			}
			else {
				arr[i][j] = false;
			}
		}
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			int answer = solved(i, j);
			cout << answer << ' ';
		}
		cout << '\n';
	}

	return 0;
}
