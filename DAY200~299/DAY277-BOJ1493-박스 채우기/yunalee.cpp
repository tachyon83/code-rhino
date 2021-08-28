#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> vc;
int cnt = 0;
bool p = true;

void solution(int len, int wid, int hgt) {
	if (!p) {
		return;
	}
	if (len == 0 || wid == 0 || hgt == 0) {
		return;
	}

	for (int i = vc.size() - 1; i >= 0; i--) {
		if (vc[i].second > 0 && vc[i].first <= len && vc[i].first <= wid && vc[i].first <= hgt) {
			cnt++;
			vc[i].second--;

			solution(len, wid, hgt - vc[i].first);
			solution(vc[i].first, wid - vc[i].first, vc[i].first);
			solution(len - vc[i].first, wid, vc[i].first);

			return;
		}
	}

	p = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int len, wid, hgt;
	cin >> len >> wid >> hgt;

	int N;
	cin >> N;

	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		vc.push_back({ pow(2, a), b });
	}

	solution(len, wid, hgt);

	if (!p) {
		cout << -1 << '\n';
	}
	else {
		cout << cnt << '\n';
	}
}
