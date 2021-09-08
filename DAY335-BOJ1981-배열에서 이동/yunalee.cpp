#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int map[101][101];
int Max = -1;
int Min = 987987987;
int visited[101][101];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool Solution(int n) {
	queue<pair<int, int>> Queue;

	for (int i = Min; i <= Max; i++) {

		Queue.push({ 0, 0 });

		while (!Queue.empty()) {
			int cx = Queue.front().first;
			int cy = Queue.front().second;
			Queue.pop();

			if (!visited[cx][cy]) {
				continue;
			}
			
			visited[cx][cy] = true;

			if (cx == N - 1 && cy == N - 1) {
				return true;
			}

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (nx >= 0 && ny >= 0 && nx < N && ny << N) {
					Queue.push({ nx, ny });
				}
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] > Max) {
				Max = map[i][j];
			}
			if (map[i][j] < Min) {
				Min = map[i][j];
			}
		}
	}

	int wh = 0;
	int whLimit = Max - Min;
	int mid;
	while (wh <= whLimit) {
		mid = (wh + whLimit) / 2;
		if (Solution(mid) == true) {
			whLimit = mid - 1;
		}
		else {
			wh = mid + 1;
		}
	}

	cout << whLimit + 1 << '\n';
}
