#include <iostream>
#include <queue>

using namespace std;

int N, M, result = 987987987;
int arr[101][101];
int dist[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
bool checked[101][101];

void solution(int x, int y) {
	queue<pair<int, int>> Queue;
	Queue.push(make_pair(x, y));
	dist[x][y] = 0;

	while (!Queue.empty()) {
		int curr_x = Queue.front().first;
		int curr_y = Queue.front().second;
		Queue.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + dx[i];
			int next_y = curr_y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < M && next_y < N) {
				if (arr[next_x][next_y] == 1) {
					if (dist[next_x][next_y] > dist[curr_x][curr_y] + 1) {
						dist[next_x][next_y] = dist[curr_x][curr_y] + 1;
						Queue.push(make_pair(next_x, next_y));
					}
				}
				else if (arr[next_x][next_y] == 0) {
					if (dist[next_x][next_y] > dist[curr_x][curr_y]) {
						dist[next_x][next_y] = dist[curr_x][curr_y];
						Queue.push(make_pair(next_x, next_y));
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	string tmpStr;
	for (int i = 0; i < M; i++) {
		cin >> tmpStr;
		for (int j = 0; j < N; j++) {
			arr[i][j] = tmpStr[j] - '0';
			dist[i][j] = 987987987;
		}
	}

	solution(0, 0);
	cout << dist[M - 1][N - 1] << '\n';

	return 0;
}
