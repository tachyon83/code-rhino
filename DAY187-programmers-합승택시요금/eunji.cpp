#include <string>
#include <vector>
#include<iostream>
#include<queue>
#define INF 987654321;
using namespace std;
int dist[3][201];
vector<pair<int, int>> node[201];
void doDijkstra();

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

	for (int i = 0; i < fares.size(); i++) {
		int x = fares[i][0];
		int y = fares[i][1];
		int z = fares[i][2];
		node[x].push_back({ z,y });
		node[y].push_back({ z,x });
	}


	for (int i = 1; i <= n; i++) {
		dist[0][i] = INF;
		dist[1][i] = INF;
		dist[2][i] = INF;
	}
	dist[0][0] = s; dist[0][s] = 0;
	dist[1][0] = a; dist[1][a] = 0;
	dist[2][0] = b; dist[2][b] = 0;
	doDijkstra();

	int answer = INF;
	for (int i = 1; i <= n; i++) {
		long long length = dist[0][i] + dist[1][i];
		length += dist[2][i];
		if (length < answer) answer = length;
	}
	return answer;
}

int main() {
	vector<vector<int>> fares = { {5, 7, 9},{4, 6, 4},{3, 6, 1},{3, 2, 3},{2, 1, 6} };

	cout << solution(7, 3, 4, 1, fares);
}
void doDijkstra() {
	for (int i = 0; i < 3; i++) {
		priority_queue<pair<int, int>> pq;
		pq.push({ 0,dist[i][0] });
		while (!pq.empty()) {
			int val = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			if (val > dist[i][cur]) continue;
			for (int j = 0; j < node[cur].size(); j++) {
				int cost = node[cur][j].first + val;
				int next = node[cur][j].second;
				if (cost < dist[i][next]) {
					dist[i][next] = cost;
					pq.push({ -cost,next });
				}
			}
		}
	}
}
