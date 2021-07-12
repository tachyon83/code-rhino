#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[4001][4001];
string s1, s2;
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);

	cin >> s1 >> s2;
	int i, j;

	for (i = 0; i < s1.length(); i++) {
		for (j = 0; j < s2.length(); j++) {
			if (s1[i] == s2[j]) { // 문자가 같다면 
				if (i == 0 || j == 0) // 문자열의 시작이 포함된다면 무조건 부분문자열의 시작부분
					dp[i][j] = 1;
				else // 이전 자리까지의 부분문자열의 길이 + 1
					dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(dp[i][j], ans);
			}
		}
	}
	cout << ans;

	return 0;
}
