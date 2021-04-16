#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

//           좌  상 하 우
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };

int bfs(vector<vector<int>>& vc, int x, int y) {
	queue<int> Queue_x;
	queue<int> Queue_y;
	Queue_x.push(x);
	Queue_y.push(y);
	int cnt = 0;

	while (!Queue_x.empty()) {
		int q_x = Queue_x.front();
		int q_y = Queue_y.front();
		Queue_x.pop();
		Queue_y.pop();
		vc[q_x][q_y] = 0;
		cnt++;

		for (int i = 0; i < 4; i++) {
			int t_x = q_x + dx[i];
			int t_y = q_y + dy[i];
			if (t_x >= 0 && t_x < vc.size() && t_y >= 0 && t_y < vc.size()) {
				if (vc[t_x][t_y] == 1) {
					Queue_x.push(t_x);
					Queue_y.push(t_y);
					vc[t_x][t_y] = 0;
				}
			}
		}

	}

	//cout << '\n' << "cnt:" << cnt << '\n';
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> vc_map(n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			int num = str[j] - '0';
			vc_map[i].push_back(num);
		}
	}

	vector<int> result;
	int danji = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vc_map[i][j] == 1) {
				//함수호출
				int r = bfs(vc_map, i, j);
				result.push_back(r);
				danji++;
			}
		}
	}

	sort(result.begin(), result.end());
	cout << danji << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}

	return 0;
}
