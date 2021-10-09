#include <iostream>
#include <cmath>

using namespace std;

int n, k;
int map[51][51];

bool solution(int c, int r, int s) {
	if (s == 0) {
		return false;
	}
	int tmp = (n - k) / 2;
	int p = pow(n, s - 1);

	if (tmp * p <= r && r < (tmp + k) * p && tmp * p <= c && c < (tmp + k) * p) {
		return true;
	}

	while (1) {
		if (r - p >= 0) {
			r -= p;
		}
		else {
			break;
		}
	}

	while (1) {
		if (c - p >= 0) {
			c -= p;
		}
		else {
			break;
		}
	}

	return solution(r, c, s - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int s, r1, r2, c1, c2;
	cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

	for (int i = 0; i + r1 <= r2; i++) {
		for (int j = 0; j + c1 <= c2; j++) {
			map[i][j] = solution(i + r1, j + c1, s);
		}
	}

	for (int i = 0; i + r1 <= r2; i++) {
		for (int j = 0; j + c1 <= c2; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}
