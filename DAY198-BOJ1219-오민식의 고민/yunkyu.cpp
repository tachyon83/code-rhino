#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

vector<pair<int, int>> v[100];
int profit[100];
bool cycle[100];
long long dist[100];
int visited[100];

bool BFS(int to,int N) {
	queue<int> q;
	// 사이클을 지난상태에서 도착지점까지 갈수있는지 확인
	for (int i = 0; i < N; i++) {
		if (cycle[i]) {
			visited[i] = true;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == to) {
			return true;
		}

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i].first;
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}

	return false;
}
int main() {
	int N, start, to, M;
	scanf("%d %d %d %d", &N, &start, &to, &M);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,-c });
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &profit[i]);
	}

	for (int i = 0; i < N; i++) dist[i] = LONG_MIN; 
	dist[start] = profit[start]; // 첫 지역에서의 이윤

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[j] == LONG_MIN) continue; // 도착 할수 없는곳이면 무시
			for (auto& p : v[j]) {
				int cost = p.second;
				int next = p.first;
				if (dist[next] < dist[j] + cost + profit[next]) { // 더 좋은 이익을 얻을수 있다면 갱신
					dist[next] = dist[j] + cost + profit[next];
					if (i == N - 1) { // N번째 반복에 갱신이된다면 사이클발생
						cycle[j] = true; // 사이클 노드를 저장한다
					}
				}
			}
		}
	}

	bool check = BFS(to, N); // 사이클 노드에서 도착지점으로 갈수있는지 확인
	if (dist[to] == LONG_MIN) printf("gg"); // 갈 수 없는 경우
	else if (check) printf("Gee"); // 돈을 무한히 많이 가지고 있는 경우
	else
		printf("%lld", dist[to]);
	return 0;
}
