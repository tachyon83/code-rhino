#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int n, m, loc = 1, cnt = 0;

	cin >> n >> m;
	vector<int> maps(n + 1);
	vector<int> dice(m);
	for (int i = 1; i <= n; i++) {
		cin >> maps[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> dice[i];
	}

	for (int i = 0; i < m; i++) {
		loc += dice[i];
		if (loc >= n) {
			cout << i + 1;
			break;
		} else {
			loc += maps[loc];
			if (loc >= n) {
				cout << i + 1;
				break;
			}
		}
	}
}