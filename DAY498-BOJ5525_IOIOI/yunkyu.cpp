#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> s;

	int ans = 0;
	for (int i = 0; i < M; i++) {
		if (s[i] == 'I') { 
			int cnt = 0;
			while (s[i + 1] == 'O' && s[i + 2] == 'I') { // "01" 세트가 존재하지 않을 때까지
				cnt++; // 세트의 수
				if (cnt == N) { // Pn을 찾았을 때
					cnt--; // 가장 앞의 "01" 세트를 제외
					ans++;
				}
				i += 2;
			}
		}
	}

	cout << ans;

	return 0;
}
