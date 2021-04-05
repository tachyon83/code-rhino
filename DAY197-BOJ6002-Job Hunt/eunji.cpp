#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main() {
	int D, P, C, F, S;
	vector<pair<int, int>>path[500];
	cin >> D >> P >> C >> F >> S;
	for (int i = 0; i < P; i++) {
		int x, y;
		cin >> x >> y;
		path[x].push_back({ y,0 });
	}
	for (int i = 0; i < F; i++) {
		int x, y, val;
		cin >> x >> y >> val;
		path[x].push_back({ y,val });
	}
	long long dist[221];
	for (int i = 1; i <= C; i++) {
		dist[i] = LONG_MAX;
	}
	bool update;
	long long max = D;
	dist[S] = D;
	for (int k = 0; k < C; k++) {
		update = false;
		for (int i = 1; i <= C; i++) {
			if (dist[i] == LONG_MAX) continue;
			for (int j = 0; j < path[i].size(); j++) {
				int next = path[i][j].first;
				long long cost = dist[i] - path[i][j].second + D;
				if (dist[next] == LONG_MAX || dist[next] < cost) {
					update = true;
					dist[next] = cost;
					if (cost > max)max = cost;
					if (k == (C - 1)) {
						cout << "-1";
						return 0;
					}
				}
			}
		}
		if (!update)break;
	}
	cout << max;
	return 0;
}
