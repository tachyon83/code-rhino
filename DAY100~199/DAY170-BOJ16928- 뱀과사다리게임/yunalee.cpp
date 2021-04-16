#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int arr[101];
int visited[101];

void solution() {	
	queue<int> Queue;
	Queue.push(1);
	visited[1] = 0;

	while (!Queue.empty()) {
		int curr = Queue.front();
		Queue.pop();

		for (int i = 1; i <= 6; i++) {
			int next = curr + i;
			if (next > 100) {
				continue;
			}

			next = arr[next] == 0 ? next : arr[next];
			
			if (visited[next] == -1) {
				visited[next] = visited[curr] + 1;
				Queue.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	memset(visited, -1, sizeof(visited));

	int tmp_a, tmp_b;
	for (int i = 0; i < N; i++) {
		cin >> tmp_a >> tmp_b;
		arr[tmp_a] = tmp_b;
	}
	for (int i = 0; i < M; i++) {
		cin >> tmp_a >> tmp_b;
		arr[tmp_a] = tmp_b;
	}

	solution();

	cout << visited[100] << '\n';

	return 0;
}
