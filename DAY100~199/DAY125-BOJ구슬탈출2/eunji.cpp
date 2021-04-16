//짜는데 힘들었는데 잘 짠것같지도 않아요 ㅠㅠ
#include <iostream>
#include <queue>
using namespace std;
typedef struct {
	int row;
	int col;
}pos;
int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };
bool visit[10][10][10][10] = { false, };
char map[10][10];
pos target;
int change(pos red, pos blue);
pair<pos, pos> moveBall(pos nowR, pos nowB, int dir);
int main() {
	int N, M;
	cin >> N >> M;
	pos blue, red;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char tmp;
			cin >> tmp;
			if (tmp != '#' && tmp != '.') {
				map[i][j] = '.';
				if (tmp == 'B') blue = { i,j };
				else if (tmp == 'R') red = { i,j };
				else  target = { i,j };
			}
			else {
				map[i][j] = tmp;
			}
		}
	}
	cout << change(red, blue);
}

int change(pos red, pos blue) {
	visit[red.row][red.col][blue.row][blue.col] = true;
	//이렇게 복잡게 해야되나..??
	queue <pair<pair<pos, pos>, int>> q;
	q.push({ { red,blue },0 });
	while ((!q.empty())) {
		pos R = q.front().first.first;
		pos B = q.front().first.second;
		int turn = q.front().second;
		if (turn > 9) break;
		q.pop();
		for (int i = 0; i < 4; i++) {
			//방향따라 더 가까운것 먼저 움직이는게 포인트
			pair<pos, pos> tmp = moveBall(R, B, i);
			pos tmpR = tmp.first;
			pos tmpB = tmp.second;
			if (tmpB.row == 0) continue;
			if (tmpR.row == 0) return turn + 1;
			if (visit[tmpR.row][tmpR.col][tmpB.row][tmpB.col] == true) continue;
			visit[tmpR.row][tmpR.col][tmpB.row][tmpB.col] = true;
			q.push({ { tmpR, tmpB }, turn + 1 });
		}
	}
	return -1;
}

pair<pos, pos> moveBall(pos nowR, pos nowB, int dir) {
	bool flag = false;
	switch (dir) {
	case 0:
		flag = (nowR.col > nowB.col);
		break;
	case 1:
		flag = (nowR.row > nowB.row);
		break;
	case 2:
		flag = (nowR.col < nowB.col);
		break;
	case 3:
		flag = (nowR.row < nowB.row);
		break;
	}
	pos order[2] = { nowB,nowR };
	if (flag) {
		order[0] = nowR;
		order[1] = nowB;
	}
	//움직이는방향 먼저옮겨지는 구슬 옮기기
	for (int i = 0; i <= 1; i++) {
		while (map[order[i].row + dirR[dir]][order[i].col + dirC[dir]] != '#') {
			//다른공이 막고잇어도 break
			if (i == 1 && order[0].row == order[1].row + dirR[dir] && order[0].col == order[1].col + dirC[dir]) break;
			order[i].row += dirR[dir];
			order[i].col += dirC[dir];
			//공이 탈출하면 row를 0으로 표시
			if (order[i].row == target.row && order[i].col == target.col) {
				if (!flag && i == 0) {
					return { {0,0},{0,0} };
				}
				order[i].row = 0;
				break;
			}
		}
	}
	if (flag) return { order[0], order[1] };
	else return { order[1], order[0] };
}
