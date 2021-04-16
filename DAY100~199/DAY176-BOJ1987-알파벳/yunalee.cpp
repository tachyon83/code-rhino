#include <iostream>
#include <queue>

using namespace std;

int R, C;
char arr[21][21];
bool visited[26];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int result = 0;

void solution(int x, int y, int cnt) {
	result = result > cnt ? result : cnt;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C) {
			if (!visited[arr[next_x][next_y] - 'A']) {
				visited[arr[next_x][next_y] - 'A'] = true;
				solution(next_x, next_y, cnt + 1);
				visited[arr[next_x][next_y] - 'A'] = false;
			}
		}
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

	visited[arr[0][0] - 'A'] = true;
	solution(0, 0, 1);

	cout << result << '\n';

	return 0;
}
