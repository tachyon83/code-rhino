#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct boxXY {
	int x;
	int y;
};

int zeroCnt = 0;
int result = 0;
int N, M;
int arr[1000][1000];
vector<boxXY> vc;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

//void Print() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cout << arr[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//}

void solution() {
	queue<boxXY> Queue;
	boxXY bxy;
	for (int i = 0; i < vc.size(); i++) {
		bxy.x = vc[i].x;
		bxy.y = vc[i].y;
		Queue.push(bxy);
	}

	while (!Queue.empty()) {
		int cur_x = Queue.front().x;
		int cur_y = Queue.front().y;
		int num = arr[cur_x][cur_y];
		Queue.pop();

		//Print();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				continue;
			}

			if (arr[nx][ny] > 1 && arr[nx][ny] <= num + 1) {
				continue;
			}

			if (arr[nx][ny] == -1 || arr[nx][ny] == 1) {
				continue;
			}

			arr[nx][ny] = num + 1;
			zeroCnt--;
			bxy.x = nx;
			bxy.y = ny;
			Queue.push(bxy);
			if (result < num) {
				result = num;
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;
	boxXY bxy;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 0) {
				zeroCnt++;
			}

			if (arr[i][j] == 1) {
				bxy.x = i;
				bxy.y = j;
				vc.push_back(bxy);
			}
		}
	}

	if (zeroCnt == 0) {
		cout << 0 << '\n';
		return 0;
	}

	solution();

	if (zeroCnt == 0) {
		cout << result << '\n';
	}
	else {
		cout << -1 << '\n';
	}

	return 0;
}
