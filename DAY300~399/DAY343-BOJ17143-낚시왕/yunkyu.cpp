#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct shark {
	int speed;
	int dir;
	int size;
}shark;

int R, C, M;
shark arr[101][101];
int dy[] = { 0, -1,1,0,0 };
int dx[] = { 0, 0,0,1,-1 };
queue<pair<pair<int, int>,shark>> q;
long long total = 0;

int changeDir(int d) { // 가장 자리에 오면 방향 반대로
	if (d == 1) return 2;
	else if (d == 2) return 1;
	else if (d == 3) return 4;
	else return 3;
}

pair<pair<int, int>,shark> move(int y, int x) {
	int d = arr[y][x].dir;
	int s = arr[y][x].speed;
	int sz = arr[y][x].size;
	shark tmp;
	arr[y][x].size = 0; // 이동 전 자리를 비움

	if (d == 1 || d == 2) { // 아래나 위일때
		s %= (R - 1) * 2; // (R-1) * 2 번째에 처음상태로 돌아온다
		for (int i = 0; i < s; i++) { // 나머지 s만큼 이동
			if (y + dy[d] < 1 || y + dy[d] > R) d = changeDir(d);
			y += dy[d];
			x += dx[d];
		}
	}
	else if (d == 3 || d == 4) { // 좌우 일때
		s %= (C - 1) * 2; // // (C-1) * 2 번째에 처음상태로 돌아온다
		for (int i = 0; i < s; i++) { // 나머지 s만큼 이동
			if (x + dx[d] < 1 || x + dx[d] > C) d = changeDir(d);
			y += dy[d];
			x += dx[d];
		}
	}

	tmp.speed = s;
	tmp.size = sz;
	tmp.dir = d;

	return { { y,x }, tmp };
}

void setShark() {
	int qsize = q.size();
	vector<pair<int, int>> v;
	for (int i = 0; i < qsize; i++) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		shark tmp = q.front().second;
		q.pop();
		if (arr[y][x].size > tmp.size) continue; // 현재 있는 상어보다 크기가 작다면 먹힘
		arr[y][x] = tmp;
		v.push_back({ y,x });
	}

	for (int i = 0; i < v.size(); i++) { // 먹힌 상어를 제외한 모든 상어
		int y = v[i].first;
		int x = v[i].second;
		q.push({ {y,x},arr[y][x] });
	}
}
void solve(int col) {
	if (col > C) return;

	int catchY = -1, catchX = -1;
	// 현재 column 에서 y를 오름차순으로 가장 가까운 상어를 잡는다
	for (int i = 1; i <= R; i++) {
		if (arr[i][col].size > 0) {
			total += arr[i][col].size; // 잡은 상어의 크기를 답에 더함
			arr[i][col].size = 0;
			catchY = i;
			catchX = col;
			break;
		}
	}

	int qsize = q.size();
	for (int i = 0; i < qsize; i++) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		q.pop();
		if (y == catchY && x == catchX) continue; // 잡은 상어는 제외하고 상어 이동
		q.push(move(y, x));
	}
	setShark(); // 이동한 상어들을 set
	solve(col + 1); // 한칸 옆으로 이동
}

int main() {
	scanf("%d %d %d", &R, &C, &M);
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		arr[r][c].speed = s;
		arr[r][c].dir = d;
		arr[r][c].size = z;
		q.push({ { r,c },arr[r][c]});
	}

	solve(1);

	printf("%d", total);
	return 0;
}
