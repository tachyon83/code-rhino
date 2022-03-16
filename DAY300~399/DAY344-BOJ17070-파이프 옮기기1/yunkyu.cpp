#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[17][17];
int dp[17][17];
int ans = 0;

bool check(int s,int y ,int x) {
	if (s == 0) { // 오른쪽으로 이동
		if (arr[y][x + 1] != 1 && x + 1 < N) return true;
	}
	else if (s == 1) { // 아래로 이동
		if (arr[y + 1][x] != 1 && y + 1 < N) return true;
	}
	else { // 오른쪽 대각선 아래로 이동
		if (arr[y][x + 1] != 1 && arr[y + 1][x] != 1 && arr[y + 1][x + 1] != 1 && y + 1 < N && x + 1 < N) {
			return true;
		}
	}

	return false;
}

void solve(int shape, int y, int x) {
	if (y == N - 1 && x == N - 1) { // 도착
		ans++;
		return;
	}

	if (shape == 0) { // 가로 
		if (check(0, y, x)) { 
			solve(0, y, x + 1); 
		}
		if (check(2, y, x)) {
			solve(2, y + 1, x + 1);
		}
	}
	else if (shape == 1) { // 세로 
		if (check(1, y, x)) solve(1, y + 1, x);
		if (check(2, y, x)) {
			solve(2, y + 1, x + 1);
		}
	}
	else { // 대각선
		if (check(0, y, x)) solve(0, y, x + 1);
		if (check(1, y, x)) solve(1, y + 1, x);
		if (check(2, y, x)) {
			solve(2, y + 1, x + 1);
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[0][1] = 1;
	solve(0, 0, 1);

	printf("%d", ans);

	return 0;
}
