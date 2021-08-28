#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int inDegree[10001];
int cost[10001];
vector<int> v[10001];
int dp[10001];

void topology(int N) {
	int i, j;
	queue<int> q;
	for (i = 1; i <= N; i++) {
		if (inDegree[i] == 0) { // 선행 관계가 없는 작업을 q에 먼저 삽입
			q.push(i);
			dp[i] = cost[i];
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];
			dp[next] = max(dp[next],cost[next] + dp[curr]); // 다음작업을 하기까지 걸린시간중 더 긴 시간으로 갱신(시간이 더 적게 걸리는 작업들은 이미 완료)
			if(--inDegree[next] == 0) // 모든 선행 작업이 완료됐다면 q에 푸쉬
				q.push(next);
		}
	}
}

int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		int num, pre;
		scanf("%d %d", &cost[i], &num);
		inDegree[i] = num; // 진입차수
		for (int j = 0; j < num; j++) {
			scanf("%d", &pre);
			v[pre].push_back(i); 
		}
	}

	topology(N); 

	int ans = 0;
	// 총 걸린 시간을 구하기 위해 가장 큰 시간을 찾는다
	for (i = 1; i <= N; i++) { 
		if (ans < dp[i])
			ans = dp[i];
	}
	printf("%d", ans);
	return 0;
}
