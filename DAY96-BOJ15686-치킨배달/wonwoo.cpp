#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int N, M;
int result;
vector<vector<int> > graph;
vector<pair<int, int> > house, chicken;
vector<bool> visited(13, false);
int distance(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
void dfs(int idx, int selected) {
	if (selected == M) {
		int tmpResult = 0;
		for (int i = 0; i < house.size(); i++) {
			int dist = INT_MAX;
			for (int j = 0; j < chicken.size(); j++) {
				if (visited[j]) {
					int dist2 = distance(house[i], chicken[j]);
					dist = dist < dist2 ? dist : dist2;
				}
			}
			tmpResult += dist;
		}

		result = result < tmpResult ? result : tmpResult;
		return;
	}

	if (idx == chicken.size()) {
		return;
	}

	visited[idx] = true;
	dfs(idx + 1, selected + 1);

	visited[idx] = false;
	dfs(idx + 1, selected);
}
int main(void) {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> N >> M;
	graph = vector<vector<int> >(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (graph[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	result = INT_MAX;
	dfs(0, 0);
	cout << result << '\n';
	return 0;
}