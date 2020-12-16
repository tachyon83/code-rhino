//시간초과->고치는중
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;
string pung(string s, string ch);
int main() {
	string s;
	string bomb;
	cin >> s >> bomb;
	cout << pung(s, bomb);
}

string pung(string s, string ch) {
	stack<int> st;
	int i = -1;
	while(++i<s.size()){
		//폭탄문자열을 순서대로 탐색
		for (int j = 0; j < ch.size(); j++) {
			//폭탄 문자열의 문자와 갔다면,
			if (s[i] == ch[j]) {
				//폭탄문자열의 맨앞자리 이거나 이미 스택 맨위의 문자 다음 문자라면
				if (j == 0 || (!st.empty() && j - 1 == st.top())) {
					st.push(j);
					//폭탄문자열을 스택에 다 넣었다면
					if (j == ch.size()-1) {
						for (int t = 0; t < ch.size(); t++) {
							s.erase(s.begin() + i--);
							st.pop();
						}
					}
				}
				else { //제대로도니 순서가 아니라면 스택비우기
					while (!st.empty()) st.pop();
				}
				break;
			}
		}
	}
	if (s.empty()) {
		return "FRULA";
	}
	return s;
}

void stackClear(stack<int> st) {
	while (!st.empty()) {
		st.pop();
	}
}
