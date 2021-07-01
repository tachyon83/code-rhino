#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

set<string> st; // 중복 제거 위해 set 이용

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);

	int n, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s2 == "enter") { // 출근
			st.insert(s1);
		}
		else { // 퇴근 
			st.erase(s1);
		}
	}

	// 사전 역순으로 출력
	for (auto iter = st.rbegin(); iter != st.rend(); iter++) {
		cout << *iter << '\n';
	}

	return 0;
}
