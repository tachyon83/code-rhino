#include<iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> friends[2000];
bool visit[2000] = { false, };
void DFS(int start,int depth);
bool findPath = false;
int main() {
	int N, M;
	cin >> N >> M;
	for (int j = 0; j < M; j++) {
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		visit[i] = true;
		DFS(i, 1);
		visit[i] = false;
		if (findPath == true) {
			cout << 1;
			return 0;
		}
		findPath = false;
	}
	cout << 0;
	return 0;

}

//사이클이 있는 그래프에서 조사할때 stack보다 재귀가 쉬운거 같다.
void DFS(int start,int depth) {
	if (depth >= 5) {
		findPath = true;
		return;
	}
	for (int i = 0; i < friends[start].size(); i++) {
		if (visit[friends[start][i]]) continue;
		visit[friends[start][i]] = true;
		DFS(friends[start][i], depth + 1);
		visit[friends[start][i]] = false;
	}
	return;
}
