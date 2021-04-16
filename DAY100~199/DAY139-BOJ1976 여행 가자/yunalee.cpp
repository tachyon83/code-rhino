#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vc(210, 0);

int getParent(int n) {
	if (vc[n] == n) {
		return n;
	}
	return vc[n] = getParent(vc[n]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) {
		vc[b] = a;
	}
	else {
		vc[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		vc[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;

			if (tmp) {
				unionParent(i, j);
			}
		}
	}

	int start;
	bool flag = true;

	for (int i = 0; i < M; i++) {
		int city;
		cin >> city;

		if (i == 0) {
			start = getParent(city);
		}
		else {
			if (start != getParent(city)) {
				flag = false;
				break;
			}
		}
	}

	if (flag) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}
