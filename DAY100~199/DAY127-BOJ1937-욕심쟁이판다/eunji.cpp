#include<iostream>
using namespace std;

int Max = 0;
int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };
int N;
int map[500][500];
int dp[500][500] = { 0, };
int doDFS(int row, int col);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x = doDFS(i, j);
			if (x > Max)Max = x;
		}
	}
	cout << Max;
}
int doDFS(int row, int col) {
	if (dp[row][col] != 0) return dp[row][col];
	int dpmax = 1;
	for (int i = 0; i < 4; i++) {
		int r = row + dirR[i];
		int c = col + dirC[i];
		if (r < 0 || r >= N || c < 0 || c >= N || map[r][c] <= map[row][col]) continue;
		int val=doDFS(r, c)+1;
		if (val > dpmax) dpmax = val;
	}
	return dp[row][col]=dpmax;
}
