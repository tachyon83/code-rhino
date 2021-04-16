#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987987987

using namespace std;

int N, M;
vector<pair<int, int>> vc[1001];
int d[1001];

void solution(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));
	d[start] = 0;
	while (!pq.empty()) {
		int curr = pq.top().first;
		int dst = pq.top().second * -1;
		pq.pop();

		if (d[curr] < dst) {
			continue;
		}
		for (int i = 0; i < vc[curr].size(); i++) {
			int next = vc[curr][i].first;

			int next_dst = dst + vc[curr][i].second;

			if (next_dst < d[next]) {
				d[next] = next_dst;
				pq.push(make_pair(next, next_dst * -1));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	int tmp_a, tmp_b, tmp_c;
	for (int i = 0; i < N - 1; i++) {
		cin >> tmp_a >> tmp_b >> tmp_c;

		vc[tmp_a].push_back(make_pair(tmp_b, tmp_c));
		vc[tmp_b].push_back(make_pair(tmp_a, tmp_c));
	}

	for (int i = 0; i < M; i++) {
		cin >> tmp_a >> tmp_b;
		fill_n(d, 1001, INF);
		solution(tmp_a);
		cout << d[tmp_b] << '\n';
	}

	return 0;
}
