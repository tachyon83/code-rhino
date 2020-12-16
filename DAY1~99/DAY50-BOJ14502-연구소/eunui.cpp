#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void Wall(int count, int row, int col,int block[][2]);
int BFS(int block[][2]);
int N, M;
int answer=0;
int virus = 0;
int wall = 3;
int vv[10][2] = { 0, };
int map[9][9] = { 0, };
int dirx[4] = { 1,0,-1,0 };
int diry[4] = { 0,1,0,-1 };
int main() {
	cin >> N >> M;
	int block[3][2] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				wall++;
			}else if(map[i][j]==2){
				vv[virus][0] = i;
				vv[virus][1] = j;
				virus++;
			}

		}
	}
Wall(0,0,0,block);
}

void Wall(int count,int row,int col,int block[][2]) {
	if (count >= 3) {
		int tmp = BFS(block);
		if (tmp < answer) answer = tmp;
		return;
	}
	int start = 0;
	for (int i = row; i < N; i++) {
		if (i == row) start = col;
		for (int j = start; j < M; j++) {
			block[count][0] = i;
			block[count][0] = j;
			Wall(count + 1, i , j + 1, block);
		}
	}
	return;
}

int BFS(int block[][2]){
	queue<pair<int, int>>q;
	int tmp[9][9];
	memcpy(tmp, map, sizeof(map));
	for (int i = 0; i < 3; i++) {
		tmp[block[i][0]][block[i][1]] = 1;
	}
	for (int i = 0; i < virus; i++) {
		q.push({ vv[i][0], vv[i][1] });
	}

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (tmp[row + diry[i]][col + dirx[i]] == 0) {
				q.push({ row + diry[i], col + dirx[i] });
				tmp[row + diry[i]][col + dirx[i]] = 2;
				virus++;
			}
		}
	}
	return N * M - wall - virus;


}
