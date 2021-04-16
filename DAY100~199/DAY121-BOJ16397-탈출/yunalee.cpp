#include <iostream>
#include <queue>
#include <string>

using namespace std;

bool visited[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, T, G;
	int cnt = 0;

	cin >> N >> T >> G;

	queue<pair<int, int>> Queue;
	Queue.push(make_pair(N, 0));

	while (!Queue.empty()) {
		int num = Queue.front().first;
		cnt = Queue.front().second;
		Queue.pop();

		//cout << num << "||" << cnt << '\n';

		if (num == G) {
			cout << cnt << '\n';
			return 0;
		}

		if (cnt == T) {
			continue;
		}

		int next = num + 1;
		if (next < 100000 && !visited[next]) {
			visited[next] = true;
			Queue.push(make_pair(next, cnt + 1));
			//cnt++;
		}

		if (num == 0) {
			continue;
		}

		int tmp = num * 2;
		if (tmp >= 100000) {
			next = tmp;
		}
		else {
			string strnum = to_string(tmp);
			for (int i = 0; i < strnum.length(); i++) {
				if (strnum[i] != 0) {
					int strtmp = strnum[i] - '0';
					strtmp--;
					strnum[i] = strtmp + '0';
					break;
				}
			}
			next = stoi(strnum);
		}

		if (next < 100000 && !visited[next]) {
			visited[next] = true;
			Queue.push(make_pair(next, cnt + 1));
		}
		//cnt++;
	}

	cout << "ANG" << '\n';

	return 0;
}
