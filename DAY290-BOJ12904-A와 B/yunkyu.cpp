#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int canChange(string s, string t) {
	int i;

	for (i = t.length() - 1; i >= 0; i--) { // t 문자열의 끝에서부터 거꾸로 확인
		if (s == t) return 1; // 문자열이 같아졌다면 성공
		char a = t[i];
		t = t.substr(0, i); // 끝의 문자가 A든 B든 잘라야한다
		if (a == 'B') { // B라면 자른 문자열을 뒤집음
			reverse(t.begin(), t.end());
		}
	}

	return 0;
}

int main() {
	string s, t;
	cin >> s >> t;

	printf("%d", canChange(s, t));
	return 0;
}
