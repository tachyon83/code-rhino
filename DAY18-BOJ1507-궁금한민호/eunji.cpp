#include <iostream>

using namespace std;

int main() {
	int city;
	cin >> city;
	int best[21][21] = { 0, };
	int d[21][21];
	for (int i = 1; i <= city; i++) {
		for (int j = 1; j <= city; j++) {
			cin >> best[i][j];
			d[i][j] = 1;
		}
	}

	for (int pass = 1; pass <= city; pass++) {
		for (int s = 1; s <= city; s++) {
			for (int e = 1; e <= city; e++) {
				if (pass == s || pass == e || s == e) {
					continue;
				}
				if (best[s][pass] + best[pass][e] < best[s][e]) {
					cout << -1;
					return 0;
				}
				else if (best[s][pass] + best[pass][e] == best[s][e]) {
					d[s][e] = 0;
				}
			}
		}

	}
	int sum=0;
	for (int i = 1; i <= city; i++) {
		for (int j = i + 1; j <= city; j++) {
			if (d[i][j] == 1) {
				sum += best[i][j];
			}
		}
	}
	cout << sum;

}
