#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[1001][1001];
int N;

void solution() {
	queue<pair<int, int>> Queue;
	Queue.push(make_pair(1, 0));
	arr[1][0] = 0;       

	while (!Queue.empty()) {
		int screen = Queue.front().first;
		int clip = Queue.front().second;
		Queue.pop();

		//복사
		if (arr[screen][screen] == -1) {
			arr[screen][screen] = arr[screen][clip] + 1;
			Queue.push(make_pair(screen, screen));
		}

		//붙여넣기
		if (screen + clip <= N && arr[screen + clip][clip] == -1) {
			arr[screen + clip][clip] = arr[screen][clip] + 1;
			Queue.push(make_pair(screen + clip, clip));
		}

		//삭제
		if (screen - 1 >= 0 && arr[screen - 1][clip] == -1) {
			arr[screen - 1][clip] = arr[screen][clip] + 1;
			Queue.push(make_pair(screen - 1, clip));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	
	memset(arr, -1, sizeof(arr));

	solution();

	int result = -1;
	for (int i = 0; i <= N; i++) {
		if (arr[N][i] != -1) {
			if (result == -1 || result > arr[N][i]) {
				result = arr[N][i];
			}
		}
	}

	cout << result << '\n';

	return 0;
}
