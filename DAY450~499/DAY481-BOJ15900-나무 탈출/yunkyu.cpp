#include <iostream>
#include <vector>
#define MAX 500000
using namespace std;

vector<int> graph[MAX + 1];
bool visited[MAX + 1];
int sum = 0;

void dfs(int curr,int depth) { // dfs로 탐색하며 리프 노드로의 depth를 모두 합한다
	visited[curr] = true;
	if (curr != 1 && graph[curr].size() == 1) { // 리프 노드일시
		sum += depth;
		return;
	}
	
	for (auto next : graph[curr]) {
		if (!visited[next]) {
			dfs(next, depth + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		// 그래프 생성
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, 0);

	if (sum % 2 == 0) { // depth의 합이 짝수일 때
		cout << "No";
	}
	else { // depth의 합이 홀수일 때
		cout << "Yes";
	}

	return 0;
}
