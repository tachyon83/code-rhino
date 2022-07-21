#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 2001
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;
vector<pair<int, int>> v[MAX];
int dist[MAX];
bool flag[MAX]; // n번째 노드까지의 최단경로에 g~h경로가 포함되어있는지 체크

void dijkstra(int start, int g, int h) {
	priority_queue<pii,vector<pii>> pq; 

	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int d = -pq.top().first; // 현재까지의 거리
		int curr = pq.top().second; // 현재 노드
		pq.pop();

		if (dist[curr] < d) continue; // 이미 조사한곳

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i].first;
			int cost = d + v[curr][i].second;
			if (cost < dist[next]) { // 최단 거리라면
				if ((curr == g && next == h) || (curr == h && next == g)) { // g ~ h 경로를 통과한다면
					flag[next] = true;
				}
				else {
					flag[next] = flag[curr];
				}
				dist[next] = cost;
				pq.push({ -cost,next }); 
			}
			if (cost == dist[next]) { // 최단 경로가 2개 이상일때
				if ((curr == g && next == h) || (curr == h && next == g)) { // g ~ h 경로를 통과한다면
					flag[next] = true;
				}
				flag[next] = flag[curr] || flag[next]; // next가 g ~ h 를 포함한 최단경로를 가지고 있다면 true로
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T > 0) {
		int n, m, t, s, g, h;
		cin >> n >> m >> t >> s >> g >> h;
		for (int i = 0; i < m; i++) { // 그래프 생성
			int a, b, d;
			cin >> a >> b >> d;
			v[a].push_back({ b,d });
			v[b].push_back({ a,d });
		}
		vector<int> dest;
		for (int i = 0; i < t; i++) {
			int x;
			cin >> x;
			dest.push_back(x);
		}
		sort(dest.begin(), dest.end()); // 오름차순 정렬
		fill(dist, dist + MAX, INF);
		fill(flag, flag + MAX, false);
		dijkstra(s, g, h); // 다익스트라로 최단경로 조사
		for (int i = 0; i < dest.size(); i++) {	// g ~ h 경로를 최단경로에 포함하는 목적지 출력
			if (flag[dest[i]]) {
				cout << dest[i] << " ";
			}
		}
		cout << "\n";

		for (int i = 1; i <= n; i++) v[i].clear();
		T--;
	}
	return 0;
}
