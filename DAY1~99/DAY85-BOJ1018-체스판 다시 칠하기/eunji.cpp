#include <iostream>
#include <vector>
using namespace std;
int check(int srow, int scol,vector<vector<char>> map);

int main() {
	int N, M;
	cin >> N >> M;
	int min = N * M;
	vector<vector<char>> map(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N-7; i++) {
		for (int j = 0; j < M-7; j++) {
			int num=check(i, j,map);
			min = num < min ? num : min;
		}
	}
	cout << min;
}

int check(int srow, int scol,vector<vector<char>> map) {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				if (map[srow + i][scol + j] == 'W') count++;
			}
			else {
				if (map[srow + i][scol + j] == 'B') count++;
			}
		}
	}
	return count < 64 - count ? count: 64 - count;
}

