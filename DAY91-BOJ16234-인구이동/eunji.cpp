//지저분하게 짠거같다...
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//인구배열
int A[50][50];
//그룹표시배열
int group[50][50];
//{그룹이루는 칸개수,그룹별 총합}
int groupNum[2500][2] = { 0, };
//입력값
int N, L, R;
bool flag=false;
int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };

void makeGroup(int r1, int c1, int r2, int c2);
void mergeGroup(int r1, int c1, int r2, int c2);

int main() {

	cin >> N >> L >> R;
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	while (1)
	{
		//그룹초기화
		int k = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				group[i][j] = (++k);
				groupNum[k][0] = 1;
				groupNum[k][1] = A[i][j];
			}
		}

		//인구이동전 그룹나누기
		for (int i = 0; i < N-1; i++) {
			for (int j = 0; j < N-1; j++) {
				makeGroup(i, j, i, j + 1);
				makeGroup(i, j, i + 1, j);
			}
			makeGroup(i, N - 1, i + 1, N - 1);
		}
		for (int i = 0; i < N-1; i++) {
			makeGroup(N - 1, i, N - 1, i + 1);
		}
		if (flag == false) break;
		//인구 이동
		for (int i = 0; i < N ; i++) {
			for (int j = 0; j < N; j++) {

				A[i][j] = groupNum[group[i][j]][1] / groupNum[group[i][j]][0];
			}
		}
		num++;
		flag = false;
	}
	cout << num;
	return 0;

}

void makeGroup(int r1, int c1, int r2, int c2) {
	if (group[r1][c1] == group[r2][c2]) return;
	int deg = abs(A[r1][c1] - A[r2][c2]);
	if (deg >= L && deg <= R) {
		flag = true;
		if (group[r1][c1] <= group[r2][c2]) mergeGroup(r1, c1, r2, c2);
		else mergeGroup(r2, c2, r1, c1);
	}
	return;
}
void mergeGroup(int r1, int c1, int r2, int c2) {
	groupNum[group[r1][c1]][0] += groupNum[group[r2][c2]][0];
	groupNum[group[r1][c1]][1] += groupNum[group[r2][c2]][1];
	//groupNum[group[r2][c2]][0] = 0;
	//groupNum[group[r2][c2]][1] = 0;
	queue <pair<int, int>>q;
	bool visit[50][50] = { false, };
	visit[r2][c2] = true;
	q.push({ r2,c2 });
	while (!q.empty()) {
		int r, c;
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int posR = dirR[i] + r;
			int posC = dirC[i] + c;
			if (posR<N && posR>=0 && posC<N && posC>=0&&group[posR][posC] == group[r2][c2] && visit[posR][posC] == false) {
				group[posR][posC] = group[r1][c1];
				q.push({ posR,posC });
				visit[posR][posC] = true;
			}
		}
		
	}
	group[r2][c2] = group[r1][c1];
	return;
}
