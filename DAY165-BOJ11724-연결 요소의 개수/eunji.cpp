#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void doBFS(bool visited[], int start, int N);

vector<int> node[1001];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}
	int group = 0;
	bool visited[1001] = { false, };
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			group++;
			doBFS(visited, i, N);
		}
	}
	cout << group;
}
void doBFS (bool visited[],int start,int N) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int num=q.front();
		q.pop();
		for (int i = 0; i < node[num].size(); i++) {
			if (!visited[node[num][i]]) {
				visited[node[num][i]] = true;
				q.push(node[num][i]);
			}
		}
	}

}
