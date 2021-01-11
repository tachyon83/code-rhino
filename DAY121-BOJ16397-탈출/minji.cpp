#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
#define MAX 99999

int n, t, g;
queue<pair<int, int>> q;
bool check[100000];

int main() {
	cin >> n >> t >> g;
	check[n] = true;
	q.push({n, 0});
	
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cnt > t) {
			cout << "ANG";
			return 0;
		}
		if (cur == g) {
			cout << cnt;
			return 0;
		}

		if ((cur + 1 <= MAX) && !check[cur+1]){
			q.push({cur+1, cnt+1});
			check[cur+1] = true;
		}

		if (cur * 2 <= MAX){
			int sub = pow(10, (int)log10(cur * 2));
			int next = cur * 2 - sub;
			if (!check[next]) {
				q.push({next, cnt+1});
				check[next] = true;
			}
		}

	}

	cout << "ANG";
}
