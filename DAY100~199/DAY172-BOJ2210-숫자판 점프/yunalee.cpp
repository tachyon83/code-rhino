#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> s;
int arr[5][5];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void solution(int x, int y, int cnt, string num) {
	if (cnt > 5) {
		s.insert(num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_y >= 0 && next_x < 5 && next_y < 5) {
			solution(next_x, next_y, cnt + 1, num + to_string(arr[next_x][next_y]));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			solution(i, j, 1, to_string(arr[i][j]));
		}
	}

	cout << s.size() << '\n';
}
