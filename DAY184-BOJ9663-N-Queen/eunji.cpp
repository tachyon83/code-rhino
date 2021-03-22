#include<iostream>

using namespace std;
void doDFS(int num, int row, int col, bool map[][15]);

int N;
int numCount = 0;
int dirR[3] = {1,1,1};
int dirC[3] = {1,0,-1 };
int main() {
	bool map[15][15] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!map[i][j]) {
				map[i][j] = true;
				doDFS(1,i,j,map);
				map[i][j] = false;
			}
		}
	}
	cout << numCount;
}
void doDFS(int num, int row, int col, bool map[][15]) {
	for (int i = 0; i < 3; i++) {
		int r = row+dirR[i];
		int c = col+dirC[i];
		while (r < N && r >= 0 && c < N && c >= 0) {
			map[r][c] = true;
			r += + dirR[i];
			c += + dirC[i];
		}
	}
	if (num == N) {
		numCount++;
	}
	else {

		for (int i = row + 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!map[i][j]) {
					map[i][j] = true;
					doDFS(num + 1, i, j, map);
					map[i][j] = false;
				}
			}
		}
	}
}
