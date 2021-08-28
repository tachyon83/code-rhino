//가르침
//https://www.acmicpc.net/problem/1062

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

int alphabet = 0;
int m = 0;

void getRead() {
	int i, j;
	int cnt = 0;

	for (i = 0; i < v.size(); i++) {
		string word = v[i];
		bool check = true;
		for (j = 4; j < word.length() - 4; j++) { // anta tica 는 정해져 있으므로 제외하고 검사
			if (!(alphabet & (1 << (word[j] - 'a')))) { // k개의 글자로 읽을수 없을때 
				check = false;
				break;
			}
		}
		if (check) // k 개의 글자로 읽을수 있다면 count + 1
			cnt++;
	}

	m = max(m, cnt); // 더 높은 개수로 갱신
}

void DFS(int ind , int cnt, int k) {
	int i;
	if (cnt == k) { // k 개의 글자를 골랐다면
		getRead();
		return;
	}

	for (i = ind; i < 26; i++) {
		if (!(alphabet & (1 << i))) { // 가르치지 않은 알파벳이라면 고름
			alphabet |= (1 << i);
			DFS(i + 1, cnt + 1, k);
			alphabet &= ~(1 << i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, i;
	cin >> n >> k;
	for (i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	if (k < 5) { // 5개 이하라면 anta tica 때문에 불가능 
		cout << 0;
		return 0;
	}
	else if (k == 26) { // 모든 알파벳을 가르친다면 단어 전부를 알수 있다
		cout << n;
		return 0;
	}

	// anta tica에 속하는 알파벳
	alphabet |= (1 << 'a' - 'a');
	alphabet |= (1 << 'n' - 'a');
	alphabet |= (1 << 't' - 'a');
	alphabet |= (1 << 'i' - 'a');
	alphabet |= (1 << 'c' - 'a');

	DFS(0, 5, k);

	cout << m;
	return 0;
}
