#include<iostream>
#include<vector>
#include <queue>
#include<memory.h>
using namespace std;
int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };
int N, M;
bool visit[300][300] = { 0, };


void doBFS(int r, int c, vector<vector<int>>& map);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int group;
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int turn = 0;
	while (++turn) {
		group = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visit[i][j] && map[i][j] != 0) {
					doBFS(i, j, map);
					group++;
				}
			}
		}
		if (group == 0) {
			cout << 0;
			return 0;
		}
		else if (group > 1) {
			cout << turn - 1;
			return 0;
		}
		for (int i = 0; i < N; i++) {
			memset(visit[i], false, sizeof(bool) * M);
		}

	}

}

void doBFS(int r, int c, vector<vector<int>>& map) {
	queue<pair<int, int>> q;
	q.push({ r,c });
	visit[r][c] = true;
	while (!q.empty()) {
		int rr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int row = rr + dirR[i];
			int col = cc + dirC[i];
			if (row >= 0 && row < N && col >= 0 && col < M) {
				if (!visit[row][col]) {
					if (map[row][col]) {
						visit[row][col] = true;
						q.push({ row,col });
					}
					else {
						if (map[rr][cc] > 0) map[rr][cc]--;
					}
				}
			}
		}
	}
}
