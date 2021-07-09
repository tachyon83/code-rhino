#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

void func(deque<int> v, string f) {
	int i;
	bool rever = false;
	for (i = 0; i < f.length(); i++) {
		if (f[i] == 'D') { // 앞에 문자를 제거
			if (v.size() == 0) { // 더 이상 제거할수 없다면 error
				cout << "error\n";
				return;
			}
			if (rever) // 뒤집었을경우 젤 뒤의 원소를 제거
				v.pop_back();
			else
				v.pop_front();
		}
		else { // 배열을 뒤집음
			rever = !rever;
		}
	}

	if (v.size() == 0) cout << "[]" << '\n';
	else {
		cout << '[';
		if (!rever) { // 뒤집지 않은 경우 앞에서부터
			for (i = 0; i < v.size() - 1; i++) {
				cout << v[i] << ',';
			}
		}
		else { // 뒤집었을 경우 뒤에서부터
			for (i = v.size() - 1; i > 0; i--) {
				cout << v[i] << ',';
			}
		}
		cout << v[i] << ']' << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T > 0) {
		string s1;
		int n;
		cin >> s1 >> n;
		char a;
		int num;
		deque<int> dq;
		cin >> a;
		if (n == 0) { 
			cin >> a;
		}
		else { // 정수와 문자를 나눠서 받음
			for (int i = 0; i < n; i++) {
				cin >> num >> a;
				dq.push_back(num);
			}
		}
		func(dq, s1);
		T--;
	}
	return 0;
}
