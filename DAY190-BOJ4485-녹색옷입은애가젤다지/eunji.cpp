#include<iostream>
#include<queue>
#include<vector>

#define INF 987654321

int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };
int N;

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num = 0;
	cin >> N;
	while (N != 0) {

		vector<vector<int>> map(N, vector<int>(N));
		vector<vector<int>> dist(N, vector<int>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				dist[i][j] = INF;
			}
		}

		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push({ -map[0][0],{0,0 } });
		dist[0][0] = map[0][0];
		while (!pq.empty()) {
			int val = -pq.top().first;
			int row = pq.top().second.first;
			int col = pq.top().second.second;
			pq.pop();
			for (int i = 0; i < 4; i++) {
				int nextR = row + dirR[i];
				int nextC = col + dirC[i];
				if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N) continue;
				int cost = val + map[nextR][nextC];
				if (cost >= dist[nextR][nextC]) continue;
				dist[nextR][nextC] = cost;
				pq.push({ -cost,{nextR,nextC} });

			}
		}
		cout << "Problem " << (++num) << ": " << dist[N - 1][N - 1] << endl;
		cin >> N;
	}
}
