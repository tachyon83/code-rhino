#include <iostream>
#include <climits>

using namespace std;

const int MAX = 10;

int N;
int map[MAX][MAX];
int answer = INT_MAX;
bool visited[MAX];

void solution(int start, int idx, int sum, int cnt) {
	if (cnt == N && start == idx) {
		if (answer > sum) {
			answer = sum;
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (map[idx][i] == 0) continue;

		if (!visited[idx] && map[idx][i] > 0) {
			visited[idx] = true;
			sum += map[idx][i];

			if (sum <= answer) {
				solution(start, i, sum, cnt + 1);
			}

			visited[idx] = false;
			sum -= map[idx][i];
		}
	}
}

int main() {
	iostream::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		solution(i, i, 0, 0);
	}

	cout << answer << '\n';

	return 0;
}
