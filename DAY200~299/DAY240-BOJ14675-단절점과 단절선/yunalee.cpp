#include <iostream>

using namespace std;

int treeA[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;

		treeA[a] += 1;
		treeA[b] += 1;
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int t, k;
		cin >> t >> k;
		if (t == 2) {
			cout << "yes" << '\n';
		}
		else {
			if (treeA[k] == 1) {
				cout << "no" << '\n';
			}
			else {
				cout << "yes" << '\n';
			}
		}
	}
}
