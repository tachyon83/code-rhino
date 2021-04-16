#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comPare(const pair<int, int>& vc1, const pair<int, int>& vc2) {
	if (vc1.second == vc2.second) {
		return vc1.first < vc2.first;
	}
	else {
		return vc1.second < vc2.second;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> vc(n);
	for (int i = 0; i < n; i++) {
		cin >> vc[i].first >> vc[i].second;
	}

	sort(vc.begin(), vc.end(), comPare);
	int match;
	int cnt = 0;
	int max = 0;

	match = vc[0].second;
	cnt++;
	for (int j = 1; j < n; j++) {
		if (match <= vc[j].first) {
			match = vc[j].second;
			cnt++;
		}
		if (max >= cnt) {
			continue;
		}
	}
	if (max < cnt) {
		max = cnt;
	}

	cout << max << '\n';

	return 0;
}
