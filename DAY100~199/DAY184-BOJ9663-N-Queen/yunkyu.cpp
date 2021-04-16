#include <cstdio>
#include <algorithm>
using namespace std;

int cnt = 0;
int queens[15]; //각 열마다 n번째 칸에 퀸을 저장

bool check(int row ,int ind) {
	for (int i = row - 1; i >= 0; i--) {
		if (queens[i] == ind || queens[i] == ind - (row - i) || queens[i] == ind + (row -i)) // 이전의 열들에 세로와 대각선에 퀸이 있는지 검사
			return false;
	}

	return true;
}

void nQueen(int row, int N) {
	if (row == N) { // N개의 퀸을 다 배치했다면 count
		cnt++;
		return;
	}

	int i;
	
	for (i = 0; i < N; i++) {
		if (check(row, i)) {
			queens[row] = i; // i번째 칸에 퀸 배치
			nQueen(row + 1, N); // 다음 열을 조사
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);

	nQueen(0, N);
	printf("%d", cnt);
	return 0;
}
