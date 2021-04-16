#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

void printSumPower(int M, int N, vector<vector<char>> map);
int BFS(int row, int col, vector<vector<bool>>& visit, vector<vector<char>> map, int M, int N);

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<char>> map(M, vector<char>(N));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	printSumPower(M, N, map);
}

void printSumPower(int M, int N, vector<vector<char>> map) {
	int sumWhite = 0;
	int sumBlue = 0;
	vector<vector<bool>> visit(M, vector<bool>(N));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				if (map[i][j] == 'W') sumWhite += BFS(i, j, visit, map, M, N);
				else sumBlue += BFS(i, j, visit, map, M, N);
			}
		}
	}
	cout << sumWhite << " " << sumBlue;
}

int BFS(int row, int col, vector<vector<bool>>& visit, vector<vector<char>> map, int M, int N) {
	int sum = 1;
	int color = map[row][col];
	int dirR[4] = { 0, 1, 0, -1 };
	int dirC[4] = { 1,0,-1,0 };
	queue<pair<int, int>> q;

	q.push({ row,col });
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextR = r + dirR[i];
			int nextC = c + dirC[i];
			if (nextR >= 0 && nextR < M && nextC >= 0 && nextC < N && !visit[nextR][nextC] && color == map[nextR][nextC]) {
				visit[nextR][nextC] = true;
				sum++;
				q.push({ nextR,nextC });
			}
		}
	}
	return (int)(pow(sum, 2));
}
