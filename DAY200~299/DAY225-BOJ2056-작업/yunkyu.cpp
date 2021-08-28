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
		if (inDegree[i] == 0) {
			q.push(i);
			dp[i] = cost[i]; 
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];
			dp[next] = max(dp[next],cost[next] + dp[curr]);  // 선행 작업을 할수록 커지기때문에 max로 비교
			if(--inDegree[next] == 0) // 선행 작업들을 다했을시 큐에 삽입
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
		inDegree[i] = num;
		for (int j = 0; j < num; j++) {
			scanf("%d", &pre);
			v[pre].push_back(i); // 선행 작업들을 연결
		}
	}

	topology(N); // 위상정렬

	int ans = 0;
	for (i = 1; i <= N; i++) { 
		if (ans < dp[i])
			ans = dp[i];
	}
	printf("%d", ans);
	return 0;
}
