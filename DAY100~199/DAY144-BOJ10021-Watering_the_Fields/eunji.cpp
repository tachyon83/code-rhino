#include<queue>
#include<iostream>
#include<cmath>
using namespace std;

typedef struct Edge {
	int start;
	int end;
	int val;
}edge;
struct compare {
	bool operator()(edge& x, edge& y) {
		return x.val > y.val;
	}
};
int par[2000];
bool merge(int u, int k);
int find(int u);
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, C;
	cin >> N >> C;
	vector<pair<int, int>> node(N);
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		node[i] = make_pair(x, y);
		par[i] = i;
	}
	priority_queue <edge, vector<edge>, compare> pq;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int val = pow(node[i].first - node[j].first, 2) + pow(node[i].second - node[j].second, 2);
			if (val < C) continue;
			edge ne = { i,j,val };
			pq.push(ne);
		}
	}
	int sum = 0;
	int num = 0;
	while (!pq.empty()) {
		int s = pq.top().start;
		int e = pq.top().end;
		int val = pq.top().val;
		pq.pop();
		if (merge(s, e)) {
			num++;
			sum += val;
		}
	}
	if (num < N - 1) {
		cout << -1;
	}
	else {
		cout << sum;
	}
}

bool merge(int u, int k) {
	u = find(u);
	k = find(k);
	if (u != k) {
		par[u] = k;
		return true;
	}
	return false;
}

int find(int u) {
	if (u == par[u]) return u;
	return par[u] = find(par[u]);
}
