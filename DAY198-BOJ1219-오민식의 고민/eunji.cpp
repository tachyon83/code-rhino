#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main() {
	int N, start, end, M;
	vector<pair<int, int>> city[100];
	cin >> N >> start >> end >> M;
	for (int i = 0; i < M; i++) {
		int x, y, val;
		cin >> x >> y >> val;
		city[x].push_back({ y,val });
	}
	long long dist[100];
	int citymoney[100];
	for (int i = 0; i < N; i++) {
		dist[i] = LONG_MAX;
		cin >> citymoney[i];
	}
	bool update;
	bool cycle = false;
	int temp;
	dist[start] = citymoney[start];
	for (int k = 0; k < N; k++) {
		temp = dist[end];
		update = false;
		for (int i = 0; i < N; i++) {
			if (dist[i] == LONG_MAX) continue;
			for (int j = 0; j < city[i].size(); j++) {
				int next = city[i][j].first;
				long long cost = dist[i] - city[i][j].second + citymoney[next];
				if (dist[next] == LONG_MAX || dist[next] < cost) {
					update = true;
					dist[next] = cost;
				}
			}
		}
		if ((k == (N - 1)) && (temp != dist[end]))cycle = true;
		if (!update)break;
	}
	if (dist[end] == LONG_MAX) cout << "gg";
	else {
		//cycle이 있어도 cycle과 도착점이 연결되어있지않다면 거를수없다->dfs로 연결되어잇나 확인해야1!
		if (cycle) cout << "Gee";
		else cout << dist[end];
	}
	return 0;
}
