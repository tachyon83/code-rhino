#include <iostream>
#include <memory.h>

using namespace std;

char arr[101][101] = {0, };
bool visit[101][101] = { false, };
int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };
int N;

void doDFS(int row, int col);
void doDFS2(int row, int col, char color);
void SectionNum();

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	SectionNum();
	return 0;
}
void SectionNum() {
	int count = 0;
	int count2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				doDFS(i, j);
				count++;
			}
		}
	}
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				doDFS2(i, j, arr[i][j]);
				count2++;
			}
		}
	}
	cout << count << ' ' << count2;
}
void doDFS(int row, int col) {

	for (int i = 0; i < 4; i++) {
		int r = row + dirR[i];
		int c = col + dirC[i];
		if ((r >= 0 && r < N && c >= 0 && c < N) && (!visit[r][c]) && (arr[r][c] == arr[row][col])) {
			visit[r][c] = true;
			doDFS(r, c);
		}
	}
}

void doDFS2(int row, int col, char color) {

	for (int i = 0; i < 4; i++) {
		int r = row + dirR[i];
		int c = col + dirC[i];
		if ((r >= 0 && r < N && c >= 0 && c < N) && (!visit[r][c]) && (arr[r][c] == arr[row][col] || (color != 'B' && arr[r][c] != 'B'))) {
			visit[r][c] = true;
			doDFS2(r, c, color);
		}
	}
}
