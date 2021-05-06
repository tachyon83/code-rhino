#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

vector<string> name;
vector<string> root;
map<string, int> inDegree;
map<string, vector<string>> mp;
map<string, vector<string>> tree;
int cnt = 0;

void topology(int N, vector<string> & name) {
	int i;
	queue<string> q;
	for (i = 0; i < N; i++) {
		if (inDegree[name[i]] == 0) { // 조상이 없다면 가문의 시조가 됨
			q.push(name[i]);
			cnt++;
			root.push_back(name[i]);
		}
	}

	while (!q.empty()) {
		string x = q.front();
		q.pop();
		for (i = 0; i < mp[x].size(); i++) {
			string child = mp[x][i];
			if (--inDegree[child] == 0) { // 자식의 조상이 다 확인 됐다면 현재 조상의 child
				q.push(child);
				tree[x].push_back(child);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, i;
	cin >> N;
	string n;
	for (i = 0; i < N; i++) {
		cin >> n;
		name.push_back(n);
	}
	cin >> M;
	for (i = 0; i < M; i++) {
		string X, Y;
		cin >> X >> Y;
		inDegree[X] ++; // 조상의 수
		mp[Y].push_back(X); 
	}
	sort(name.begin(), name.end()); // 이름 오름차순 정렬
	topology(N, name); // 위상정렬
	cout << cnt << '\n';
	for (i = 0; i < root.size(); i++) {
		cout << root[i] << ' ';
	}
	cout << '\n';
	for (i = 0; i < name.size(); i++) {
		cout << name[i] << ' ' << tree[name[i]].size() << ' ';
		for (int j = 0; j < tree[name[i]].size(); j++) {
			cout << tree[name[i]][j] << ' '; // child 가 있다면 출력
		}
		cout << '\n';
	}

	return 0;
}
