#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int cost[1001];

void topology(int N , vector<int> &inDegree ,vector<int> &dp, vector<int> graph[1001]) {
	int i;
	queue<int> q;

	for (i = 1; i <= N; i++) {
		if (inDegree[i] == 0) { // 선행 돼야 하는 건물이 없다면 큐에 먼저 삽입
			q.push(i);
			dp[i] = cost[i];
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];
			dp[next] = max(dp[next], cost[next] + dp[curr]); // 건물을 동시에 지을수 있기때문에 선행 된 건물중 가장 오래걸린 시간을 더한값이여야함
			if (--inDegree[next] == 0) { // 모든 선행 건물을 다 지었다면 큐에 삽입
				q.push(next);
			}
		}
	}
}

int main() {
	int T, i;
	scanf("%d", &T);
	while (T > 0) {
		int N, K;
		scanf("%d %d", &N, &K);
		vector<int> inDegree(N + 1, 0); // 진입차수
		vector<int> dp(N + 1, 0); 
		vector<int> graph[1001];

		for (i = 1; i <= N; i++) {
			scanf("%d", &cost[i]);
		}

		for (i = 0; i < K; i++) {
			int X, Y;
			scanf("%d %d", &X, &Y);
			graph[X].push_back(Y); 
			inDegree[Y] ++; // 먼저 지어야 하는 건물 수
		}

		topology(N, inDegree, dp, graph); // 위상 정렬
		int goal;
		scanf("%d", &goal);
		printf("%d\n", dp[goal]);
		T--;
	}
	return 0;
}
