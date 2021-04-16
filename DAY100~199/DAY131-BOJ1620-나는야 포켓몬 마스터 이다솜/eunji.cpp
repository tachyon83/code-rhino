#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<int, string> m;
	map<string, int>m2;
	int N, M;
	cin >> N >> M;
	string s;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		m[i] = s;
		m2[s] = i;
	}
	for (int i = 1; i <= M; i++) {
		cin >> s;
		//문자일때
		if (s[0] >= 65) {
			cout << m2[s]<<'\n';
		}
		else cout << m[stoi(s)] << '\n';

	}
}
