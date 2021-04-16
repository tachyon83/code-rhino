#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
int ans = 0;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<vector<int> > dp;
vector<vector<int> > arr;
bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}
int dfs(int x, int y) {
	if (dp[y][x]) {
		return dp[y][x];
	}

	int subAns = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (isValid(nx, ny) && arr[y][x] < arr[ny][nx]) {
			subAns = max(subAns, dfs(nx, ny) + 1);
		}
	}
	return dp[y][x] = subAns;
}
int main(void) {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;
	arr.resize(n, vector<int>(n, 0));
	dp.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			ans = max(ans, dfs(x, y));
		}
	}
	cout << ans;
}