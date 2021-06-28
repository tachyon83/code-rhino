#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int dp[1001][1001];
string s1, s2;
stack<char> st;

void lcs(int i ,int j) {
	if (dp[i][j] == 0) { // lcs를 찾았다면 출력
		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
		return;
	}

	if (s1[i - 1] == s2[j - 1]) { // 같은 문자면 i - 1 , j - 1
		st.push(s1[i - 1]);
		lcs(i - 1, j - 1);
	}
	else { // 다른 문자면 더 큰 값으로
		if (dp[i][j - 1] > dp[i - 1][j])
			lcs(i, j - 1);
		else
			lcs(i - 1, j);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s1 >> s2;

	int i, j;
	for (i = 1; i <= s1.size(); i++) {
		for (j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) { // 같은 문자면 두 문자열의 이전까지의 lcs 길이 + 1
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else { // 다른 문자면 첫번째 문자와 두번째 문자를 제거한 상태중 비교
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[s1.size()][s2.size()] << '\n';
	lcs(s1.size(), s2.size());
	return 0;
}
