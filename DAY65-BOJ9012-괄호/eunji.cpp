#include <iostream>
#include <string>
#include <stack>

using namespace std;
bool isVPS(string s);
int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		bool answer = isVPS(s);
		if (answer == true) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

}

bool isVPS(string s) {
	stack<char> st;
	if (s[0] == ')') {
		return false;
	}
	st.push(s[0]);
	int i = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else {
			if (st.empty()) {
				return false;
			}
			else {
				st.pop();
			}
		}
	}
	if (!st.empty()) {
		return false;
	}
	return true;
}
