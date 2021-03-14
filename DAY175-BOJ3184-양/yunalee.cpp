#include <iostream>
#include <queue>

using namespace std;

int R, C;
char arr[251][251];
bool visited[251][251];
int result_w, result_s;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void solution(int x, int y) {
	int w = 0;
	int s = 0;

	queue<pair<int, int>> Queue;
	Queue.push(make_pair(x, y));
	visited[x][y] = true;

	while (!Queue.empty()) {
		int curr_x = Queue.front().first;
		int curr_y = Queue.front().second;
		Queue.pop();

		if(arr[curr_x][curr_y] == 'v') {
			w++;
		}
		if (arr[curr_x][curr_y] == 'o') {
			s++;
		}

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + dx[i];
			int next_y = curr_y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C) {
				if (arr[next_x][next_y] != '#' && !visited[next_x][next_y]) {
					visited[next_x][next_y] = true;
					Queue.push(make_pair(next_x, next_y));
				}
			}
		}
	}

	if (s > w) {
		result_s = result_s + s;
	}
	else {
		result_w = result_w + w;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visited[i][j]) {
				solution(i, j);
			}
		}
	}

	cout << result_s << ' ' << result_w << '\n';

	return 0;
}
