#include <iostream>
#include <deque>
using namespace std;

int N, M;
int x, y, K;
int arr[20][20];

deque<int> col_q;
deque<int> row_q;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void init() {
	for (int i = 0; i < 4; i++) {
		col_q.push_back(0);
	}
	for (int i = 0; i < 2; i++) {
		row_q.push_back(0);
	}
}

void solution(int next_x, int next_y, int move) {
	
	if (move == 4) {	//남쪽이동이거나 북쪽일 경우
		//주사위 이동모습
		col_q.push_front(col_q.back());
		col_q.pop_back();
	}
	else if (move == 3) {
		//주사위 이동모습
		col_q.push_back(col_q.front());
		col_q.pop_front();
	}
	else if (move == 2) {	//서쪽일 경우
		for (int i = 1; i <= 2; i++) {
			col_q.push_back(col_q.front());
			col_q.pop_front();
			col_q.push_back(row_q.back());
			row_q.pop_back();
			if (i == 1) {
				row_q.push_front(col_q.front());
				col_q.pop_front();
			}
			else if (i == 2) {
				row_q.push_back(col_q.front());
				col_q.pop_front();
			}
			
		}
	}
	else if (move == 1) {	//동쪽일 경우
		for (int i = 1; i <= 2; i++) {
			col_q.push_back(col_q.front());
			col_q.pop_front();
			col_q.push_back(row_q.front());
			row_q.pop_front();
			if (i == 1) {
				row_q.push_back(col_q.front());
				col_q.pop_front();
			}
			else if (i == 2) {
				row_q.push_front(col_q.front());
				col_q.pop_front();
			}
		}
	}

	if (arr[next_x][next_y] == 0) {	//맵의 수가 0인경우
		arr[next_x][next_y] = col_q[3];	//주사위 수를 맵에 옮김
	}
	else {	//맵의 수가 0이 아닌경우
		col_q[3] = arr[next_x][next_y];	//주사위 바닥에 맵의 수를 옮김
		arr[next_x][next_y] = 0;	//맵 0으로 만듦
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> x >> y >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	init();

	int move;
	for (int i = 0; i < K; i++) {
		cin >> move;
		
		int next_x = x + dx[move - 1];
		int next_y = y + dy[move - 1];

		//바깥으로 나가는 명령일 경우 무시
		if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) {
			continue;
		}

		solution(next_x, next_y, move);
		x = next_x;
		y = next_y;
		cout << col_q[1] << '\n';
	}
}
