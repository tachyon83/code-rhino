#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;
		vector<pair<int, int>> map[101];

		for (int j = 0; j < M; j++) {
			int a, b, val;
			cin >> a >> b >> val;
			map[a].push_back({ b,val });
			map[b].push_back({ a,val });
		}
		int K;
		cin >> K;
		vector<vector<int>> dist(K, vector<int>(N + 1));
		for (int p = 0; p < K; p++) {
			cin >> dist[p][0];
			for (int j = 1; j <= N; j++) {
				dist[p][j] = INF;
			}
			dist[p][dist[p][0]] = 0;
		}
		for (int j = 0; j < K; j++) {
			priority_queue<pair<int, int>> pq;
			pq.push({ 0,dist[j][0] });
			while (!pq.empty()) {
				int val = -pq.top().first;
				int cur = pq.top().second;
				pq.pop();
				if (val > dist[j][cur])continue;
				for (int p = 0; p < map[cur].size(); p++) {
					int next = map[cur][p].first;
					int cost = map[cur][p].second + val;
					if (cost >= dist[j][next])continue;
					dist[j][next] = cost;
					pq.push({ -cost,next });
				}
			}
		}
		int minSum = INF;
		int index = 0;
		for (int j = 1; j <= N; j++) {
			int sum = 0;
			for (int k = 0; k < K; k++) {
				sum += dist[k][j];
			}
			if (sum < minSum) {
				minSum = sum;
				index = j;
			}

		}
		cout << index << endl;

	}
}
