#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string str;

struct Dict {
	bool finish;
	Dict* abc[26];

	Dict() : finish(false) {
		memset(abc, 0, sizeof(abc));
	}

	~Dict() {
		for (int i = 0; i < 26; i++)if (abc[i])delete abc[i];
	}

	void insert(int idx) {
		if (idx >= str.size()) {
			finish = true;
			return;
		}
		int curr = str[idx] - 'a';
		if (abc[curr] == NULL)abc[curr] = new Dict();
		abc[curr]->insert(idx + 1);
	}

	bool find(int idx) {
		if (idx==(int)str.size()) {
			if(finish)return true;
			else return false;
		}
		int curr = str[idx] - 'a';
		if (abc[curr]==NULL)return false;
		return abc[curr]->find(idx + 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Dict dict;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;
		dict.insert(0);
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (dict.find(0))cnt++;
	}
	cout << cnt;
}
