#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 0: 48    9: 57
// 1: true  0: false
struct Trie {
	bool fin;	//문자열의 종료시점을 나타내기 위함
	Trie* next[10];

	// 생성자
	Trie() {
		fin = false;
		for (int i = 0; i < 10; i++) {
			next[i] = NULL;
		}
	}

	// 소멸자
	~Trie() {
		for (int i = 0; i <= 9; i++) {
			if (next[i]) {
				delete next[i];
			}
		}
	}

	// 문자열을 트라이에 삽입
	void insert(const char* ch) {
		if (*ch == NULL) {	// 문자 입력의 종료지점
			fin = true;
		}
		else {
			int curr = *ch - '0';
			if (next[curr] == NULL) {	// ch의 문자로 시작하는 문자열 최초 입력을 나타냄
				next[curr] = new Trie();
			}
			//cout << ch + 1 << '\n';
			next[curr]->insert(ch + 1);	//다음 문자열을 삽입
		}
	}

	bool find(const char* ch) {
		if (*ch == NULL) {
			if (fin == true) {
				return true;
			}
			return false;
		}
		int curr = *ch - '0';
		if (next[curr] == NULL) {
			return false;
		}

		if (*ch != NULL && fin == true) {
			return false;
		}
		return next[curr]->find(ch + 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, n;
	cin >> t;

	// 입력된 테스트케이스만큼 반복
	while (t--) {
		cin >> n;

		Trie* trie = new Trie();
		vector<string> vc;
		// n개의 전화번호만큼 반복하여 전화번호 입력
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			vc.push_back(str);
			const char* ch = str.c_str();	// string to char
			//cout << ch << '\n';

			trie->insert(ch);
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			const char* ch = vc[i].c_str();	// string to char
			//cout << vc[i] << ' ' << trie->find(ch) << '\n';

			if (trie->find(ch)) {
				cnt++;
			}
		}

		if (cnt == n) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << "\n";
		}
	}
}
