#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<memory.h>
//어렵네용ㅎㅎ

using namespace std;

struct Trie {
	bool finish;
	int count;
	Trie* arr[26];

	Trie() :finish(false){
		memset(arr, 0, sizeof(arr));
		count = 0;
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (arr[i]) {
				delete arr[i];
			}
		}
	}

	void insert(const char *key) {
		if (*key == '\0') {
			finish = true;
			return;
		}
		else {
			int pos = *key - 'a';
			if (arr[pos] == NULL) {
				arr[pos] = new Trie();
			}
			arr[pos]->insert(key + 1);
			count++;
		}
	}


	int find(const char* key) {
		if (*key == '\0') {
			return 0;
		}
		else if (*key=='?') {
			return count;
		}
		else {
			int pos = *key - 'a';
			if (arr[pos] == NULL) {
				return 0;
			}
			return arr[pos]->find(key + 1);
		}
		return count;
	}

};
vector<int> solution(vector<string> words, vector<string> queries) {
//정방향으로랑 반대로 두개로 해줬습니다. 배열 만들어서 길이별로 넣었습니다.
	Trie* real[100001] = { 0, };
	Trie * rever[100001] = { 0, };
	vector<int> answer;

	for (int i = 0; i < words.size(); i++) {
		string tmp;
		tmp.assign(words[i].begin(), words[i].end());
		reverse(tmp.begin(), tmp.end());
		if (real[words[i].size()] == 0) {
			real[words[i].size()] = new Trie();
			rever[words[i].size()] = new Trie();
		}
		real[words[i].size()]->insert(&words[i][0]);
		rever[words[i].size()]->insert(&tmp[0]);
	}

	for (int i = 0; i < queries.size(); i++) {
		if (queries[i][0] == '?') {
			if (rever[queries[i].size()] == 0) {
				answer.push_back(0);
				continue;
			}
			string tmp;
			tmp.assign(queries[i].begin(), queries[i].end());
			reverse(tmp.begin(), tmp.end());
			answer.push_back(rever[queries[i].size()]->find(&tmp[0]));
		}
		else {
			if (real[queries[i].size()] == 0) {
				answer.push_back(0);
				continue;
			}
			answer.push_back(real[queries[i].size()]->find(&queries[i][0]));
		}
	}
	return answer;
}
