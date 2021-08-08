#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;

int cnt = 0;

struct Trie {
	bool finish;
	Trie* next[26];

	Trie():finish(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') { // 문자열의 끝이라면 표시
			finish = true;
			return;
		}
		int curr = *key - 'a';
		if (!next[curr])
			next[curr] = new Trie();
		next[curr]->insert(key + 1);
		
	}

	void find(const char * key) {
		if (*key == '\0') { // 문자열의 끝이라면
			if (finish == true) cnt++; // 트라이에 존재하는 단어라면 개수 증가
			return;
		}
		int curr = *key - 'a';
		if (!next[curr]) // 현재까지의 부분문자열이 없는 문자열이라면
			return;

		next[curr]->find(key + 1);
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int i;

	Trie* root = new Trie;
	string s;
	for (i = 0; i < n; i++) {
		cin >> s;
		root->insert(s.c_str()); // 트라이에 문자열을 삽입
	}

	for (i = 0; i < m; i++) {
		cin >> s;
		root->find(s.c_str());
	}

	cout << cnt;
	return 0;
}
