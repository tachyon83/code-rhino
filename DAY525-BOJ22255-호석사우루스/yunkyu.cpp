// 틀린 코드

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define MAX 100
#define INF 987654321
using namespace std;

struct current {
	int y, x, cnt, cost;
};

struct compare {
	bool operator() (const current& c1, const current& c2) {
		return c1.cnt < c2.cnt;
	}
};

int N, M;
int arr[MAX + 1][MAX + 1];
int impulse[MAX + 1][MAX + 1];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void dijkstra(int sx, int sy) {
	priority_queue<current,vector<current>,compare> pq;
	current start;
	start.x = sx;
	start.y = sy;
	start.cnt = 1;
	start.cost = 0;

	arr[sy][sx] = 0;
	pq.push(start);
	while (!pq.empty()) {
		current top = pq.top();
		pq.pop();

		int y = top.y;
		int x = top.x;
		int cnt = top.cnt;
		int cost = top.cost;

		if (cnt % 3 == 0) {
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= 0 && ny < N && nx >= 0 && nx < M && impulse[ny][nx] != -1) {
					if (arr[ny][nx] > impulse[ny][nx] + arr[y][x]) {
						arr[ny][nx] = impulse[ny][nx] + arr[y][x];
						current tmp;
						tmp.y = ny;
						tmp.x = nx;
						tmp.cnt = cnt + 1;
						tmp.cost = arr[ny][nx];
						pq.push(tmp);
					}
				}
			}
		}
		else if (cnt % 3 == 1) {
			for (int i = 2; i <= 3; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= 0 && ny < N && nx >= 0 && nx < M && impulse[ny][nx] != -1) {
					if (arr[ny][nx] > impulse[ny][nx] + arr[y][x]) {
						arr[ny][nx] = impulse[ny][nx] + arr[y][x];
						current tmp;
						tmp.y = ny;
						tmp.x = nx;
						tmp.cnt = cnt + 1;
						tmp.cost = arr[ny][nx];
						pq.push(tmp);
					}
				}
			}
		}
		else {
			for (int i = 0; i <= 1; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= 0 && ny < N && nx >= 0 && nx < M && impulse[ny][nx] != -1) {
					if (arr[ny][nx] > impulse[ny][nx] + arr[y][x]) {
						arr[ny][nx] = impulse[ny][nx] + arr[y][x];
						current tmp;
						tmp.y = ny;
						tmp.x = nx;
						tmp.cnt = cnt + 1;
						tmp.cost = arr[ny][nx];
						pq.push(tmp);
					}
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> impulse[i][j];
			arr[i][j] = INF;
		}
	}

	dijkstra(sx - 1, sy - 1);
	cout << arr[ey - 1][ex - 1];
	return 0;
}
