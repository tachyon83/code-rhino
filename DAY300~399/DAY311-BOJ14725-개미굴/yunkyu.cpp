#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Trie {
	bool finish = false;
	map<string, Trie> next;
};

void insert(Trie& t, vector<string> v, int ind) {
	if (ind == v.size()) { // 배열 끝일때 종료
		t.finish = true;
		return;
	}

	if (t.next.count(v[ind]) == 0) { // map에 값이 없다면 생성 
		t.next[v[ind]] = Trie();
	}

	insert(t.next[v[ind]], v, ind + 1); // child에 다음 인덱스 값 삽입
}

void print(Trie& t, int dep) {

	for (auto child : t.next) { // 모든 child에 대해
		for (int i = 0; i < dep; i++) { // 현재 깊이만큼 -- 출력
			cout << "--";
		}

		cout << child.first << "\n"; 

		print(child.second, dep + 1); // 다음 child로
	}
}

int main() {
	int n;
	cin >> n;
	int i;
	Trie root;

	for (i = 0; i < n; i++) {
		int k;
		cin >> k;
		vector<string> v(k);
		for (int j= 0; j < k; j++) {
			cin >> v[j];
		}
		insert(root, v, 0);
	}

	print(root, 0);

	return 0;
}
