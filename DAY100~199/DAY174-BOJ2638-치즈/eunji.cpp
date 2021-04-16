#include<iostream>
#include<vector>
#include <queue>
#include<memory.h>
using namespace std;
int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };
int N, M;
bool visit[100][100] = { 0, };
int  cheese[100][100] = { 0, };
bool doBFS(int r, int c, vector<vector<int>>& map);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool flag;
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int turn = 0;
	while (++turn) {
		flag = doBFS(0, 0, map);

		if (!flag) {
			cout << turn - 1;
			return 0;
		}

		for (int i = 0; i < N; i++) {
			memset(visit[i], false, sizeof(bool) * M);
			memset(cheese[i], 0, sizeof(int) * M);
		}

	}

}

bool doBFS(int r, int c, vector<vector<int>>& map) {
	bool flag = false;
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
						flag = true;
						if (++cheese[row][col] == 2) {
							map[row][col] = 0;
							visit[row][col] = true;
						}
					}
					else {
						q.push({ row,col });
						visit[row][col] = true;
					}
				}
			}
		}
	}
	return flag;
}
