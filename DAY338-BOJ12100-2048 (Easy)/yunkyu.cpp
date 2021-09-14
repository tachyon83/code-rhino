#include <cstdio>
#include <algorithm>

int n;
int board[21][21];
int maxB = 0;

void playing(char dir, int (*bd)[21], int cnt){
	if (cnt == 5)
		return;

	int i,j;

	int cpy[21][21];

  //tmp배열에 현재 board복사
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cpy[i][j] = bd[i][j];
		}
	}

	//상하좌우로 PUSH
	if (dir == 'U') {
		for (j = 0; j < n; j++) {
			int pb = 0, pbind = 0;
			for (i = 0; i < n; i++) {
				if (cpy[i][j] != 0) {
					if (pb && cpy[i][j] == pb) { // 똑같은숫자가 만났을때 합침
						cpy[pbind][j] = pb * 2;
						if (maxB < pb * 2) maxB = pb * 2;
						cpy[i][j] = 0;
						pb = 0;
					}
					else { // 이전 블록 기록
						pb = cpy[i][j];
						pbind = i;
					}
				}
			}
		}

		for (j = 0; j < n; j++) {
			int ind = 0;
			for (i = 0; i < n; i++) {
				if (cpy[i][j]) {
					cpy[ind][j] = cpy[i][j];
					if (ind != i)
						cpy[i][j] = 0;
					ind++;
				}
			}
		}

		playing('U', cpy, cnt + 1);
		playing('D', cpy, cnt + 1);
		playing('L', cpy, cnt + 1);
		playing('R', cpy, cnt + 1);
	}
	else if (dir == 'D') {
		for (j = 0; j < n; j++) {
			int pb = 0, pbind = 0;
			for (i = n - 1; i >= 0; i--) {
				if (cpy[i][j] != 0) {
					if (pb && cpy[i][j] == pb) {
						cpy[pbind][j] = pb * 2;
						if (maxB < pb * 2) maxB = pb * 2;
						cpy[i][j] = 0;
						pb = 0;
					}
					else {
						pb = cpy[i][j];
						pbind = i;
					}
				}
			}
		}

		for (j = 0; j < n; j++) {
			int ind = n - 1;
			for (i = n - 1; i >= 0; i--) {
				if (cpy[i][j]) {
					cpy[ind][j] = cpy[i][j];
					if (ind != i)
						cpy[i][j] = 0;
					ind--;
				}
			}
		}

		playing('U', cpy, cnt + 1);
		playing('D', cpy, cnt + 1);
		playing('L', cpy, cnt + 1);
		playing('R', cpy, cnt + 1);
	}
	else if (dir == 'L') {
		for (i = 0; i < n; i++) {
			int pb = 0, pbind = 0;
			for (j = 0; j < n; j++) {
				if (cpy[i][j] != 0) {
					if (pb && cpy[i][j] == pb) {
						cpy[i][pbind] = pb * 2;
						if (maxB < pb * 2) maxB = pb * 2;
						cpy[i][j] = 0;
						pb = 0;
					}
					else {
						pb = cpy[i][j];
						pbind = j;
					}
				}
			}
		}

		for (i = 0; i < n; i++) {
			int ind = 0;
			for (j = 0; j < n; j++) {
				if (cpy[i][j]) {
					cpy[i][ind] = cpy[i][j];
					if(ind != j)
						cpy[i][j] = 0;
					ind++;
				}
			}
		}

		playing('U', cpy, cnt + 1);
		playing('D', cpy, cnt + 1);
		playing('L', cpy, cnt + 1);
		playing('R', cpy, cnt + 1);
	}
	else {
		for (i = 0; i < n; i++) {
			int pb = 0, pbind = 0;
			for (j = n - 1; j >= 0; j--) {
				if (cpy[i][j] != 0) {
					if (pb && cpy[i][j] == pb) {
						cpy[i][pbind] = pb * 2;
						if (maxB < pb * 2) maxB = pb * 2;
						cpy[i][j] = 0;
						pb = 0;
					}
					else {
						pb = cpy[i][j];
						pbind = j;
					}
				}
			}
		}

		for (i = 0; i < n; i++) {
			int ind = n - 1;
			for (j = n - 1; j >= 0; j--) {
				if (cpy[i][j]) {
					cpy[i][ind] = cpy[i][j];
					if (ind != j)
						cpy[i][j] = 0;
					ind--;
				}
			}
		}

		playing('U', cpy, cnt + 1);
		playing('D', cpy, cnt + 1);
		playing('L', cpy, cnt + 1);
		playing('R', cpy, cnt + 1);
	}
}
int main() {
	int i, j;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] > maxB) maxB = board[i][j]; 
		}
	}

  //상하좌우
	playing('U', board, 0);
	playing('D', board, 0);
	playing('L', board, 0);
	playing('R', board, 0);

	printf("%d", maxB);
	return 0;
}
