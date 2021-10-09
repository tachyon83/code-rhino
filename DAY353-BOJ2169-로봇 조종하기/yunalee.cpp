#include <iostream>
using namespace std;

int n, m;
int map[1001][1001];
int value_calc_map[1001][1001][3];
bool visited[1001][1001];

//          아래 왼 오
int dx[] = { 1, 0, 0 };
int dy[] = { 0, -1, 1 };

int solution(int x, int y, int d) {
	if (x == n - 1 && y == m - 1) {
		return map[x][y];
	}
	if (value_calc_map[x][y][d] != -987987987) {
		return value_calc_map[x][y][d];
	}

	visited[x][y] = true;

	int result = -987987987;
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}

		if (!visited[nx][ny]) {
			result = max(result, solution(nx, ny, i));
		}
	}
	visited[x][y] = false;
	value_calc_map[x][y][d] = map[x][y] + result;

	return value_calc_map[x][y][d];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			value_calc_map[i][j][0] = -987987987;
			value_calc_map[i][j][1] = -987987987;
			value_calc_map[i][j][2] = -987987987;
		}
	}
	
	int answer = solution(0, 0, 0);

	cout << answer << '\n';
}
