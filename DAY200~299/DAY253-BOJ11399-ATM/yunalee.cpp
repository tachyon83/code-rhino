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
	for(int i = 0; i < n; i++){
		cin >> vc[i];
	}

	sort(vc.begin(), vc.end());

	int sum = 0;
	for (int i = 0; i < vc.size(); i++) {
		sum += (vc[i] * (n - i));
	}

	cout << sum << '\n';

	return 0;
}
