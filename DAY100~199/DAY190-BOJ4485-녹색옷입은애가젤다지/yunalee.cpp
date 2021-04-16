#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[126][126];
int dist[126][126];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
bool visited[126][126];

void solution(int x, int y) {
	queue<pair<int, int>> Queue;
	Queue.push(make_pair(x, y));
	dist[x][y] = arr[x][y];

	while (!Queue.empty()) {
		int curr_x = Queue.front().first;
		int curr_y = Queue.front().second;
		Queue.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + dx[i];
			int next_y = curr_y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N) {
				if (dist[next_x][next_y] > dist[curr_x][curr_y] + arr[next_x][next_y]) {
					dist[next_x][next_y] = dist[curr_x][curr_y] + arr[next_x][next_y];
					Queue.push(make_pair(next_x, next_y));
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int testcase = 1;
	while (1) {
		cin >> N;
		if (N == 0) {
			break;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				dist[i][j] = 987987987;
			}
		}

		solution(0, 0);
		cout << "Problem " << testcase << ": "<< dist[N - 1][N - 1] << '\n';
		testcase++;
	}

	return 0;
}
