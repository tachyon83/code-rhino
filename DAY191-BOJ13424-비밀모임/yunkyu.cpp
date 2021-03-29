#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;

int n, m;
//vector<pair<int, int>> graph[101];

vector<int> dijkstra(int start, int n, vector<pair<int,int>> graph[101]) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> dist(n + 1, INF);
	int i;
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int d = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (d > dist[curr]) continue; // 이미 더 짧은 경로가 존재

		for (i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			int cost = d + graph[curr][i].second;
			if (cost < dist[next]) { // 더 짧은 경로일시 갱신
				dist[next] = cost;
				pq.push({ cost,next });
			}
		}
	}

	return dist; // 최단경로 배열 반환
}

int getMeetingRoom(int n,vector<vector<int>> &dists) {
	int i, j, minCost = INF, ret = 0;

	// 1 ~ n번째 방을 모임장소로 하는 경우에 이동거리의 총합이 
	// 가장 작은 방을 찾는다
	for (i = 1; i <= n; i++) {
		int sum = 0;
		for (j = 0; j < dists.size(); j++) {
			sum += dists[j][i];
		}
		if (sum < minCost) {
			minCost = sum;
			ret = i;
		}
	}
	return ret;
}
int main() {
	int T, i, k, a, b, c;
	scanf("%d", &T);

	while (T > 0) {
		scanf("%d %d", &n, &m);
		vector<pair<int, int>> graph[101];

		for (i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			graph[a].push_back({ b,c });
			graph[b].push_back({ a,c });
		}
		scanf("%d", &k);

		vector<int> v;
		vector<vector<int>> dists;

		for (i = 0; i < k; i++) {
			int num;
			scanf("%d", &num);
			v.push_back(num);
		}

		for (i = 0; i < v.size(); i++) {
			dists.push_back(dijkstra(v[i], n,graph)); // 각 친구들이 있는 위치에서의 최단경로를 조사함
		}

		printf("%d\n", getMeetingRoom(n, dists)); 
		T--;
	}
	return 0;
}
