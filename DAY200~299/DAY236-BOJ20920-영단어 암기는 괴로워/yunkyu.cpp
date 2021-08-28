#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<string, int> cnt;
vector<string> v;

bool cmp(string& a, string& b) {
	if (cnt[a] != cnt[b]) // 빈도 수로 내림차순
		return cnt[a] > cnt[b];
	else if (a.length() != b.length()) // 길이 순으로 내림차순
		return a.length() > b.length();
	else // 모두 같다면 사전순으로 정렬
		return a < b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, i;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		string word;
		cin >> word;
		if (word.length() >= M) {
			if(cnt[word] == 0) // 나왔던 단어가 아니라면 벡터에 삽입
				v.push_back(word);
			cnt[word] ++; // 맵에 개수를 세어준다
		}
	}
	sort(v.begin(), v.end(), cmp); // 정렬

	for (i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}
