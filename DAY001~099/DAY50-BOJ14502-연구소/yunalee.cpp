#include <iostream>
#include <queue>
using namespace std;

int N, M;
int Input[10][10];
int cpInput[10][10];

//          상  좌  하  우
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int result = 0;
int zeroCnt = 0;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cpInput[i][j] = Input[i][j];
		}
	}
}

int solution(int x, int y, int zc) {
	queue<pair<int, int>> Queue;
	Queue.push(pair<int, int>(x, y));
	cpInput[x][y] = 2;
	while (!Queue.empty()) {
		int cur_x = Queue.front().first;
		int cur_y = Queue.front().second;
		cpInput[cur_x][cur_y] = 2;
		
		if (zc < result) {
			break;
		}

		Queue.pop();
		zc--;

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) {
				continue;
			}
			if (cpInput[next_x][next_y] == 0) {
				Queue.push(pair<int, int>(next_x, next_y));
				cpInput[next_x][next_y] = 2;
			}
		}
	}

	return zc;
}

void selectWall(int startX, int startY, int cnt) {
	if (cnt == 3) {
		init();
		int tmp = zeroCnt - cnt;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (Input[i][j] == 2) {
					tmp = solution(i, j, tmp);
				}
			}
		}

		if (result < tmp) {
			result = tmp;
		}

		return;
	}

	for (int i = startX; i < N; i++, startY = 0) {
		for (int j = startY; j < M; j++) {
			if (Input[i][j] == 0) {
				Input[i][j] = 1;
				selectWall(i, j + 1, cnt + 1);
				Input[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Input[i][j];
			if (Input[i][j] != 1) {
				zeroCnt++;
			}
		}
	}
	init();
	selectWall(0, 0, 0);

	cout << result << '\n';
}
