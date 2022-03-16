#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

double total = 0;
string dict[100001];

struct Trie {
	bool finish;
	Trie* next[26];

	Trie() :finish(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i])
				delete next[i];
		}
	}

	void insert(const char* key) {
		if (*key == '\0') {
			finish = true;
		}
		else {
			int curr = *key - 'a';
			if (!next[curr])
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}

	
	void search(const char* key, double cnt) {
		if (*key == '\0') { // 문자열 끝이면 버튼 횟수 더하고 종료
			total += cnt;
			return;
		}
		int ind = *key - 'a';
		if (cnt == 0) { // 처음 인덱스는 무조건 버튼을 눌러야한다
			next[ind]->search(key + 1, cnt + 1);
			return;
		}

		// 모든 문자열의 현재 인덱스가 key인지 확인
		bool flag = true;
		for (int i = 0; i < 26; i++) {
			if (i != ind && next[i]) {
				flag = false;
				break;
			}
		}

		if (!flag) { // 아니라면 버튼 누른다
			next[ind]->search(key + 1, cnt + 1);
		}
		else { // 맞다면
			if (finish) // 현재까지의 문자열이 사전에 있는 단어라면 버튼을 눌러야한다
				next[ind]->search( key + 1, cnt + 1);
			else 
				next[ind]->search(key + 1, cnt);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	int i;

	while (1) {
		cin >> n;
		if (cin.eof()) return 0; // 입출력 없을시 종료
		Trie* root = new Trie; // 새 Trie 생성
		for (i = 0; i < n; i++) {
			cin >> dict[i];
			root->insert(dict[i].c_str()); // 단어 Trie에 삽입
		}
		
		for (i = 0; i < n; i++) { 
			root->search(dict[i].c_str(),0); // 각 단어에 버튼 횟수 구함
		}

		// 소수점 둘째자리까지 반올림
		cout << fixed;
		cout.precision(2);
		cout << total / n << '\n';
		total = 0;
		delete root;
	}

	return 0;
}
