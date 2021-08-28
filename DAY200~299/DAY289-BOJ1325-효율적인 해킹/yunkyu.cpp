#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;
vector<int> graph[10001];
bool visited[10001];
vector<int> ans;
int m = -1;

int BFS(int n) {
	int cnt = 1;
	visited[n] = true;
	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i];
			if (!visited[next]) { 
				visited[next] = true;
				q.push(next);
				cnt++; // 해킹 가능한 컴퓨터의 수 + 1
			}
		}
	}
	
	return cnt;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		int cnt = BFS(i);
		if (m == cnt) { // 수가 같다면 ans 배열에 푸시
			ans.push_back(i);
		}
		else if (m < cnt) { // 더 큰 수라면 배열 비우고 새로 푸시
			m = cnt;
			ans.clear();
			ans.push_back(i);
		}
	}

	sort(ans.begin(), ans.end()); // 오름차순

	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	return 0;
}
