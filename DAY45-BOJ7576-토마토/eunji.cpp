#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
struct matrix {
	int row;
	int col;
	int day;
};
queue <matrix> q;
int dirr[4] = { -1,0,1,0 };
int dirc[4] = { 0,-1,0,1 };
int M, N;
int tomatoGo(vector<vector<int>> tomato);
int no;
int main() {

	cin >> M >> N;

	vector<vector<int>> tomato(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push({ i, j ,0});
			}
			else if (tomato[i][j] == -1) {
				no++;
			}
		}
	}
	cout << tomatoGo(tomato);

}

int tomatoGo(vector<vector<int>> tomato) {
	if (q.empty()) {
		return -1;
	}
	else if ((q.size()+no)==(N*M)) {
		return 0;
	}
	else {
		matrix tmp;
		while (!q.empty()) {
			tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int row = tmp.row + dirr[i];
				int col = tmp.col + dirc[i];
				int day = tmp.day + 1;
				if (row >= 0 && row < N && col >= 0 && col < M && tomato[row][col] == 0) {
					q.push({ row,col ,day });
					tomato[row][col] = 1;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tomato[i][j] == 0) {
					return -1;
				}
			}
		}
		return tmp.day;
	}


}
