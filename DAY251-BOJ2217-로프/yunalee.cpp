#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> vc(n);
	for (int i = 0; i < n; i++) {
		cin >> vc[i];
	}

	sort(vc.begin(), vc.end());
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < vc[i] * (n-i)) {
			max = vc[i] * (n-i);
		}
	}
	
	cout << max << '\n';

	return 0;
}
