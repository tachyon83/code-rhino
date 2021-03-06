#include <iostream>
#include <queue>

using namespace std;

int N, M;
int visited[501][501];
int arr[501][501];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int solution(int x, int y) {
	queue<pair<int, int>> Queue;
	Queue.push(make_pair(x, y));
	visited[x][y] = true;

	int cnt = 1;
	while (!Queue.empty()) {
		int currX = Queue.front().first;
		int currY = Queue.front().second;
		Queue.pop();

		for (int i = 0; i < 4; i++) {
			int nX = currX + dx[i];
			int nY = currY + dy[i];
			if (nX >= 0 && nX < N && nY >= 0 && nY < M) {
				if (!visited[nX][nY] && arr[nX][nY] == 1) {
					visited[nX][nY] = true;
					cnt++;
					Queue.push(make_pair(nX, nY));
				}
			}
		}
	}

	return cnt;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int maxAns = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && arr[i][j] == 1) {
				cnt++;
				int tmp = solution(i, j) ;
				if (tmp > maxAns) {
					maxAns = tmp;
				}
			}
		}
	}

	cout << cnt << '\n' << maxAns << '\n';

	return 0;
}
