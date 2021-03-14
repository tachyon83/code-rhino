#include<iostream>
#include<vector>
using namespace std;
int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };
int dmax = 0;
int R, C;
char map[20][20];
bool apb[26] = { 0, };
bool visit[20][20] = { 0, };
void doDFS(int r, int c, int depth);

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
	visit[0][0] = true;
	apb[map[0][0] - 'A'] = true;
	doDFS(0, 0, 1);

	cout << dmax;
}

void doDFS(int r, int c, int depth) {
	for (int i = 0; i < 4; i++) {
		int row = r + dirR[i];
		int col = c + dirC[i];
		if (row >= 0 && row < R && col >= 0 && col < C && !visit[row][col] && !apb[map[row][col] - 'A']) {
			visit[row][col] = true;
			apb[map[row][col] - 'A'] = true;
			doDFS(row, col, depth + 1);
			visit[row][col] = false;
			apb[map[row][col] - 'A'] = false;
		}
	}
	if (depth > dmax) dmax = depth;
}
