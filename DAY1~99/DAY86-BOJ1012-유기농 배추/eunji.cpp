#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int countW( bool map[][50],int M,int N,int K);
void doBFS(bool map[][50], int M, int N, int strow, int stcol);
int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };

int main() {
	int T, M, N, K;
	cin >> T;
	for (int i = 0; i < T;i++) {
		int row, col;
		cin >> M >> N >> K;
		bool map[50][50] = { 0, };
		for (int j = 0; j < K; j++) {
			cin >> col >> row;
			map[row][col] = true;
		}
		cout << countW(map,M,N,K)<<endl;
	}


}

int countW( bool map[][50], int M, int N, int K) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) {
				count++;
				doBFS(map, M, N,i,j);
			}
		}
	}
	return count;
}

void doBFS(bool map[][50], int M, int N,int strow,int stcol) {
	queue <pair<int, int>> q;
	map[strow][stcol] = false;
	q.push({ strow, stcol });
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextrow = row + dirR[i];
			int nextcol = col + dirC[i];
			if (nextrow>=0 && nextrow<N && nextcol>=0 && nextcol<M&&map[nextrow][nextcol]) {
				map[nextrow][nextcol] = false;
				q.push({ nextrow,nextcol });
			}
		}
	}

}
