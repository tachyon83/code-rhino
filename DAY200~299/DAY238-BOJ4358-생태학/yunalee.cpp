#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	int cnt = 0;
	map<string, int> m;

	while (getline(cin, str)) {
		if (cin.eof()) {
			break;
		}
		if (m.find(str) == m.end()) {	//처음 입력된 종
			m[str] = 1;
		}
		else {
			m[str]++;	//이미 입력된 종의 경우 +1
		}

		cnt++;	//총 입력된 갯수 카운트
	}

	cout << fixed;
	cout.precision(4);
	map<string, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << ' ' << iter->second * 100 / (double)cnt << '\n';
	}

	return 0;
}
