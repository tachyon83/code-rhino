#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, answer = 0;
vector<string> v;
int flag;

void solution(int cnt, int start) {
	int chk = 0;
	if (cnt >= K) {
		for (int i = 0; i < v.size(); i++) {
			string tmp = v[i];
			int c = 0;
			for (int j = 0; j < tmp.length(); j++) {
				int tmpNum = tmp[j] - 'a';

				if ((1 << tmpNum) & flag) {	//해당 알파벳의 비트가 켜져있는지 확인
					c++;
				}
			}

			// 배운 글자로 단어를 읽을 수 있는 경우 카운팅
			if (c == tmp.length()) {
				chk++;
			}
		}

		answer = max(answer, chk);	// 읽을 수 있는 단어의 최대값 구하기

		return;
	}

	for (int i = start; i < 26; i++) {
		if ((flag & (1 << i)) == 0) {
			flag |= (1 << i);	// 비트켜기
			solution(cnt + 1, i + 1);
			flag &= ~(1 << i);	// 비트끄기
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(str);
	}

	// 배우는 글자가 5개 미만이면 anta/tica를 읽을 수 없는 경우
	if (K < 5) {
		cout << 0 << '\n';
		return 0;
	}
	else if (K == 26) {
		cout << N << '\n';
		return 0;
	}

	// or연산을 통해 비트 켜기
	flag |= 1 << ('a' - 'a');
	flag |= 1 << ('n' - 'a');
	flag |= 1 << ('t' - 'a');
	flag |= 1 << ('i' - 'a');
	flag |= 1 << ('c' - 'a');

	solution(5, 0);
	cout << answer << '\n';

	return 0;
}
