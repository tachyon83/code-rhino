#include<cstdio>
#include<deque>
#include<vector>
#define INF 987654321
typedef struct {
	int row;
	int col;
}Node;
int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };
using namespace std;
int N, M;
int map[100][100];
int dist[100][100];
int main() {
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
			dist[i][j] = INF;
		}

	}
	deque<pair<int, Node>> dq;
	Node node = { 0,0 };
	dq.push_back({ 0,node });
	dist[0][0] = 0;
	while (!dq.empty()) {
		int val = dq.front().first;
		int row = dq.front().second.row;
		int col = dq.front().second.col;
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int nextR = row + dirR[i];
			int nextC = col + dirC[i];
			if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M) continue;
			int cost = val + map[nextR][nextC];
			if (cost >= dist[nextR][nextC]) continue;
			dist[nextR][nextC] = cost;
			if (map[nextR][nextC]) dq.push_back({ cost,{nextR,nextC} });
			else dq.push_front({ cost,{nextR,nextC} });

		}
	}
	printf("%d", dist[N - 1][M - 1]);

}
