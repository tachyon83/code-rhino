#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[21][21];
vector<int> v;
int dice[4][3];

void move(int x , int y) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 1) { // 동쪽으로 주사위 회전
			if (y ==  M - 1) continue; // 지도 바깥으로 나갈수 없음
			int tmp = dice[1][1];
			dice[1][1] = dice[1][0];
			dice[1][0] = dice[3][1];
			dice[3][1] = dice[1][2];
			dice[1][2] = tmp;
			y++;
		}
		else if (v[i] == 2) { // 서쪽으로 회전
			if (y == 0) continue;
			int tmp = dice[1][1];
			dice[1][1] = dice[1][2];
			dice[1][2] = dice[3][1];
			dice[3][1] = dice[1][0];
			dice[1][0] = tmp;
			y--;
		}
		else if (v[i] == 3) { // 북쪽으로 회전
			if (x == 0) continue;
			int tmp = dice[1][1];
			dice[1][1] = dice[0][1];
			dice[0][1] = dice[3][1];
			dice[3][1] = dice[2][1];
			dice[2][1] = tmp;
			x--;
		}
		else { // 남쪽으로 회전
			if (x == N - 1) continue;
			int tmp = dice[1][1];
			dice[1][1] = dice[2][1];
			dice[2][1] = dice[3][1];
			dice[3][1] = dice[0][1];
			dice[0][1] = tmp;
			x++;
		}

		if (arr[x][y] == 0) { // 바닥이 0 이라면 
			arr[x][y] = dice[3][1];
		}
		else { // 바닥에 0 이 아닌 수가 있다면
			dice[3][1] = arr[x][y];
			arr[x][y] = 0;
		}

		printf("%d\n", dice[1][1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int x, y, K;

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int order;
		cin >> order;
		v.push_back(order);
	}

	move(x,y);

	return 0;
}
