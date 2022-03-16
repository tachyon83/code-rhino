#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

bool tag = false;

int main() {
	string s;
	getline(cin, s); // 공백 포함해서 한줄 입력
	
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '<' || s[i] == '>') { // 태그가 열리거나 닫힐때
			if (s[i] == '<') { // 열린 태그일때 스택에 문자열이 있다면 모두 출력
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
			}
			tag = !tag; // 태그가 열렸을때는 true 닫히면 false
			cout << s[i];
			continue;
		}

		if (tag) { // 열린태그 일때는 그대로 출력
			cout << s[i];
		}
		else { // 태그가 닫혔다면
			if (s[i] == ' ') { // 공백일시 이전 단어 반대로 출력
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << ' ';
			}
			else // 스택에 문자하나씩 삽입
				st.push(s[i]);
		}
	}

	if (!st.empty()) { // 스택에 남은 단어가 있다면 출력
		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
	}
	return 0;
}
