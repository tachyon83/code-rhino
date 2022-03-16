#include <iostream>
#include <stack>
#include <set>

using namespace std;

int main() {
	set<pair<int, int>>gidung;
	int N;
	cin >> N;
	int max = 0;
	int maxindex = 0;
	int answer = 0;

	for (int i = 0; i < N; i++) {
		int L, H;
		cin >> L >> H;
		gidung.insert({ L,H });
		if (H > max) {
			max = H;
			maxindex = L;
		}
	}

	stack<pair<int, int>> left;
	left.push(*gidung.begin());
	gidung.erase(gidung.begin());

	while (!gidung.empty() && (*gidung.begin()).first<=maxindex) {
		pair<int, int> tmp = left.top();
		pair<int, int> cur = (*gidung.begin());
		if (cur.second - tmp.second >= 0) {
			answer += (cur.first - tmp.first) * tmp.second;
			left.pop();
			left.push(cur);
		}
		gidung.erase(gidung.begin());
	}
	gidung.insert(left.top());
	left.pop();
	left.push(*(gidung.rbegin()));
	gidung.erase(--gidung.end());

	while (!gidung.empty()) {
		pair<int, int> tmp = left.top();
		pair<int, int> cur = (*gidung.rbegin());
		if (cur.second - tmp.second >= 0) {
			answer += (tmp.first-cur.first) * tmp.second;
			left.pop();
			left.push(cur);
		}
		gidung.erase(--gidung.end());

	}
	answer += max;
	cout << answer;
}
