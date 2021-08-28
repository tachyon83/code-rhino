#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, int> mp;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, i;
	cin >> n;
	string s;
	int ans = 0;

	for (i = 0; i < n; i++) { // 들어온 순서대로 번호를 매김
		cin >> s;
		mp[s] = i;
	}

	for (i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	// 나온 차중에 들어온 순서보다 빠르게 들어온 차를 찾는다
	for (i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (mp[v[i]] > mp[v[j]]) {
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
