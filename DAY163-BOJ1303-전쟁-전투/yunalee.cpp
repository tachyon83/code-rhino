#include <iostream>
#include <queue>

using namespace std;

int N, M;
char map[101][101];
bool chkMap[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int solution(int x, int y, char ch) {
	int cnt_result = 1;
	queue<pair<int, int>> Queue;

	Queue.push(make_pair(x, y));
	chkMap[x][y] = true;

	while (!Queue.empty()) {
		int curr_x = Queue.front().first;
		int curr_y = Queue.front().second;

		Queue.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + dx[i];
			int next_y = curr_y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < M && next_y < N) {
				if (!chkMap[next_x][next_y] && ch == map[next_x][next_y]) {
					cnt_result++;
					chkMap[next_x][next_y] = true;
					Queue.push(make_pair(next_x, next_y));
				}
			}
		}
	}

	return cnt_result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int w_result = 0;
	int b_result = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int tmp = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!chkMap[i][j]) {
				if (map[i][j] == 'W') {
					tmp = solution(i, j, 'W');
					w_result += (tmp * tmp);
				}
				else if (map[i][j] == 'B') {
					tmp = solution(i, j, 'B');
					b_result += (tmp * tmp);
				}
			}
		}
	}

	cout << w_result << ' ' << b_result << '\n';

	return 0;
}
