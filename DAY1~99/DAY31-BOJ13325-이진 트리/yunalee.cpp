#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int m = (1 << n + 1) - 2;
	int len = m;
	vector<pair<int, int>> treVc(m);

	pair<int, int> p;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		
		p.first = tmp;
		p.second = tmp;
		treVc[i] = p;
	}

	for (int i = len - 1; i > 1; i-=2) {
		int maxVal = max(treVc[i].second, treVc[i - 1].second);
		treVc[(i >> 1) - 1].second += maxVal;

	}

	int result = 0;
	for (int i = 0; i < treVc.size()-1; i+=2) {
		int maxVal = max(treVc[i].second, treVc[i + 1].second);
		treVc[i].first += maxVal - treVc[i].second;
		result += treVc[i].first;
		treVc[i + 1].first += maxVal - treVc[i + 1].second;
		result += treVc[i + 1].first;
	}

	cout << result << '\n';
}
