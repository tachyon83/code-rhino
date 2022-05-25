#include <bits/stdc++.h>
using namespace std;
int n;
int arr[101][101];
long long dp[101][101];
long long dfs(int x, int y) {
	if (x == n-1 && y == n-1) return 1;
	else if (dp[x][y] == -1) {
		dp[x][y] = 0;
		// 오른쪽가는친구
		int right_x = x+ arr[x][y];
		int right_y = y;
		if (right_x >= 0 && right_x < n && right_y >= 0 && right_y < n) {
			dp[x][y] += dfs(right_x, right_y);
		}
		int down_x = x;
		int down_y = y + arr[x][y];
		if (down_x >= 0 && down_x < n && down_y >= 0 && down_y < n) {
			dp[x][y]+=dfs(down_x, down_y);
		}
	}
	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	 
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	cout<<dfs(0, 0);
}
 
