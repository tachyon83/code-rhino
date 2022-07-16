#include <iostream>
#include <vector>
#include <queue>
#define MAX 100
#define INF 987654321
using namespace std;

struct current {
	int y, x, cnt, cost;
};

struct compare {
	bool operator() (const current& a, const current& b) {
		return a.cost > b.cost;
	}
};

int N, M;
int dist[3][MAX + 1][MAX + 1]; // 3가지 방향으로부터의 위치를 고려
int impulse[MAX + 1][MAX + 1];
vector<vector<int>> dy = { {0,0,1,-1},{1,-1},{0,0} };
vector<vector<int>> dx = { {1,-1,0,0},{0,0},{1,-1} };

void init(int N, int M) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				dist[i][j][k] = INF;
			}
		}
	}
}

void dijkstra(int sx, int sy, int ex, int ey) {
	priority_queue<current,vector<current>,compare> pq; // cost 오름차순 우선순위큐
	int ans = INF;

	pq.push({ sx,sy,1,0 });
	while (!pq.empty()) {
		current top = pq.top();
		int y = top.y;
		int x = top.x;
		int cnt = top.cnt;
		int cost = top.cost;
		pq.pop();

		if (y == ex && x == ey) { // 도달했다면 
			ans = min(ans, cost);
			break;
		}

		if (dist[cnt % 3][y][x] < cost) continue; // 이미 갱신된 위치라면

		// cnt % 3번째의 이동 방향을 따른다.
		for (int i = 0; i < dy[cnt % 3].size(); i++) {
			int ny = y + dy[cnt % 3][i];
			int nx = x + dx[cnt % 3][i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M && impulse[ny][nx] != -1) { // 바깥공간이 아니고 벽이 아니라면
				int nextCost = impulse[ny][nx] + cost;
				if (dist[(cnt + 1) % 3][ny][nx] > nextCost) { // 더 적은 값으로 갱신할 수 있을 때
					dist[(cnt + 1) % 3][ny][nx] = nextCost;
					pq.push({ny, nx, cnt + 1, nextCost}); 
				}
			}
		}
	}

	if (ans == INF) { // 도달할 수 없을 때
		cout << -1;
	}
	else cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> impulse[i][j];
		}
	}

	init(N, M); // dist 배열 초기화
	dijkstra(sx - 1, sy - 1, ex - 1, ey - 1);

	return 0;
}
