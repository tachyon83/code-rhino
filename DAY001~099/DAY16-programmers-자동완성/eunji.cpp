#include <string>
#include <vector>
#include <memory.h>

using namespace std;

struct Trie {
	int count;
	bool finish;
	Trie * alpa[26];
    
	Trie() : finish(false) {
		count = 0;
		memset(alpa, 0, sizeof(alpa));
	}
    
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (alpa[i]) {
				delete alpa[i];
			}
		}
	}
    
	void insert(const char* key) {
  //넣을때마다 애초에 count변수를 두어서 몇번탐색되는지 저장함
		count++;
		if (*key == '\0') {
			finish = true;
		}
		else {
			//아스크코드 값으로 넣음
			int cur = *key - 'a';
			if (alpa[cur] == NULL) {
				alpa[cur] = new Trie();
			}alpa[cur]->insert(key + 1);
		}
	}
    
	int find(const char* key) {
			int cur = *key - 'a';
			if (count == 1 || *key=='\0') {
				return 0;
			}
			else {
				return (alpa[cur]->find(key + 1))+1;
			}
		}
    
};

int solution(vector<string> words) {
    int sum=0;
    Trie *root = new Trie;
	for (int i = 0; i < words.size(); i++) {
			root->insert(&(words[i][0]));
	}
	for (int i = 0; i < words.size(); i++) {
		sum += root->find(&words[i][0]);
	}
    return sum;
}
