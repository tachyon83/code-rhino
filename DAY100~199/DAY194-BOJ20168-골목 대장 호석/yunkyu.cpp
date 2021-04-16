#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;
vector<pii> graph[11];

int dijkstra(int from, int to, int money, int n) {
	priority_queue<pair<int,pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
	vector<int> v(n + 1, INF);
	int i;
	pq.push({0 ,{ from,money } }); // 수치심이 최소가 되는 경로를 구하기 위해 수치심에 대하여 우선순위 정렬
	v[from] = 0;

	while (!pq.empty()) {
		int shame = pq.top().first;
		int curr = pq.top().second.first;
		int cash = pq.top().second.second;
		pq.pop();

		if (shame > v[curr]) continue; // 수치심이 더 적은 경로가 있을 경우

		for (i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			int cost = shame > graph[curr][i].second ? shame : graph[curr][i].second; // 지금까지의 경로에서의 최대 수치심
			int rest = cash - graph[curr][i].second; // 지불하고 남은 돈
			if (cost < v[next] && rest >= 0) { // 수치심이 더 적고 돈을 지불할 수 있을 경우
				v[next] = cost;
				pq.push({ cost, { next,rest } });
			}
		}
	}

	return v[to] == INF ? -1 : v[to]; // 갈 수 있는 경로가 없을시에는 -1출력
}

int main() {
	int n, m, from, to, money;
	scanf("%d %d %d %d %d", &n, &m, &from, &to, &money);
	int i;
	for (i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	printf("%d",dijkstra(from, to, money, n));
	return 0;
}
