#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

bool flag;

bool compare(string a, string b) {
	return a.length() < b.length();
}

vector<string> v;

struct Trie {
	bool finish; // 끝을 표시
	Trie* next[11];

	Trie() :finish(false) {
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 10; i++)
			if (next[i]) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') { // 문자열의 끝
			finish = true;
		}
		else {
			if (finish) flag = false; // 만약 이미 있는 전화번호를 포함해서 넘어선다면
			int curr = *key - '0';
			if (next[curr] == NULL) 
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}
};

int main() {
	int T, n;
	string num;
	cin >> T;

	while (T > 0) {
		cin >> n;
		flag = true;
		Trie* root = new Trie; // 트라이 생성
		for (int i = 0; i < n; i++) {
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end(), compare); // 문자열 길이 오름차순 정렬

		for (int i = 0; i < n; i++) {
			root->insert(v[i].c_str()); 
		}

		if (!flag) { // 다른 전화번호를 포함한 번호가 있다면 
			cout << "NO\n";
		}
		else
			cout << "YES\n";

		v.clear();
		T--;
	}

	return 0;
}
