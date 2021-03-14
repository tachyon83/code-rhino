#include<iostream>
#include<queue>

using namespace std;

int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };
char map[250][250];
bool visit[250][250] = { false, };
int R, C;
int W = 0;
int S = 0;
void doBFS(int i, int j);
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visit[i][j] && map[i][j] != '#') {
				doBFS(i, j);
			}
		}
	}

	cout << S << ' ' << W;

}

void doBFS(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	visit[i][j] = true;
	int wolf = 0;
	int sheep = 0;
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		if (map[row][col] == 'v') wolf++;
		else if (map[row][col] == 'o')sheep++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int rr = row + dirR[i];
			int cc = col + dirC[i];
			if (rr >= 0 && rr < R && cc >= 0 && cc < C) {
				if (map[rr][cc] != '#' && !visit[rr][cc]) {
					q.push({ rr,cc });
					visit[rr][cc] = true;
				}
			}
		}
	}
	if (wolf >= sheep) W += wolf;
	else S += sheep;
}
