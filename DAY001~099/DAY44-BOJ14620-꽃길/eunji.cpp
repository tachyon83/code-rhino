#include <iostream>
#include <vector>

using namespace std;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int N;
int gardening(int num, int cost, vector<vector<bool>> visit, int row, int col, vector<vector<int>> garden);

int main() {
	cin >> N;
	vector<vector<int>> garden(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> garden[i][j];
		}
	}

	vector<vector<bool>> visit(N, vector<bool>(N, 0));
	int mincost = 3000;
	for (int i = 1; i < N-1; i++) {
		for (int j = 1; j < N - 1; j++) {
			int tmp = gardening(1, 0, visit, i, j,garden);
			if (tmp < mincost) mincost = tmp;
		}
	}
	cout << mincost;

}

int gardening(int num,int cost ,vector<vector<bool>> visit,int row,int col,vector<vector<int>> garden) {
	int costmin = 3000;
	visit[row][col] = visit[row + dir[0][0]][col + dir[0][1]] = visit[row + dir[1][0]][col + dir[1][1]] = visit[row + dir[2][0]][col + dir[2][1]] = visit[row + dir[3][0]][col + dir[3][1]] = true;
	cost += garden[row][col] + garden[row + dir[0][0]][col + dir[0][1]] + garden[row + dir[1][0]][col + dir[1][1]] + garden[row + dir[2][0]][col + dir[2][1]] + garden[row + dir[3][0]][col + dir[3][1]];
	if (num == 3) {
		return cost;
	}
	else {
		for (int i = row; i < N - 1; i++) {
			int start = 1;
			if (i == row)start = col + 3;
			for (int j = start; j < N - 1; j++) {
				if (!visit[i][j] && !visit[i + dir[0][0]][j + dir[0][1]] && !visit[i + dir[1][0]][j + dir[1][1]] && !visit[i + dir[2][0]][j + dir[2][1]] && !visit[i + dir[3][0]][j + dir[3][1]]) {
					int tmp=gardening(num + 1, cost, visit, i, j,garden);
					if (tmp < costmin) {
						costmin = tmp;
					}
				}

			}
		}

	}
	return costmin;

}
