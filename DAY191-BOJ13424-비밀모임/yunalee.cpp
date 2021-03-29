#include <iostream>
#include <vector>
#include <queue>

#define INF 987987987

using namespace std;

int N, M, K;

void dijkstra(int start, vector<pair<int, int>> vc[101], vector<int> &dist) {
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int curr = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if (dist[curr] < distance) {
			continue;
		}
		for (int i = 0; i < vc[curr].size(); i++) {
			int next = vc[curr][i].first;
			int nextDist = distance + vc[curr][i].second;

			if (nextDist < dist[next]) {
				dist[next] = nextDist;
				pq.push(make_pair(next, -nextDist));
			}
		}
	}
}

int findingRoom(vector<vector<int>> &v) {
	int min = INF;
	int result = 0;

	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 0; j < v.size(); j++) {
			sum += v[j][i];
		}
		if (sum < min) {
			min = sum;
			result = i;
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int testcase;
	cin >> testcase;

	while (testcase--) {
		cin >> N >> M;

		int a, b, c, answer = 0;
		vector<pair<int, int>> vc[101];
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			vc[a].push_back(make_pair(b, c));	// a->b로 가는 비용
			vc[b].push_back(make_pair(a, c));	// b->a로 가는 비용
		}

		cin >> K;

		vector<int> pos;
		int tmp;
		for (int i = 0; i < K; i++) {
			cin >> tmp;
			pos.push_back(tmp);
		}

		vector<vector<int>> minDist;
		for (int i = 0; i < pos.size(); i++) {
			vector<int> dist(N + 1, INF);
			dijkstra(pos[i], vc, dist);
			minDist.push_back(dist);
		}

		answer = findingRoom(minDist);

		cout << answer << '\n';
	}

	return 0;
}
