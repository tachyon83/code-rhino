#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[501];
int inDegree[501];
int cost[501];
int dp[501];

void topology(int n) {
	int i;
	queue<int> q;
	for (i = 1; i <= n; i++) {
		if (inDegree[i] == 0) { // 선행되어야하는 노드가 없다면
			q.push(i);
			dp[i] = cost[i]; 
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (i = 0; i < graph[curr].size(); i++) { 
			int next = graph[curr][i];
			dp[next] = max(dp[next], dp[curr] + cost[next]); // 가장 큰 소요시간이 걸리는 선행 건물의 시간을 더해줌 
			if (--inDegree[next] == 0) { // 모든 선행 건물을 다 지었다면
				q.push(next);
			}
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++) {
		int a;
		scanf("%d", &cost[i]);
		while (1) {
			scanf("%d", &a);
			if (a == -1) // -1 입력시 종료
				break;
			inDegree[i] ++; // 진입차수 표시
			graph[a].push_back(i);
		}
	}

	topology(n); // 위상 정렬

	for (i = 1; i <= n; i++)
		printf("%d ", dp[i]);
	return 0;
}
