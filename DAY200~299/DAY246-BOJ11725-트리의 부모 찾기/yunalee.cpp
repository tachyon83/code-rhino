#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> vc[100001];
int parent[100001];
bool visited[100001];

void solution(int start) {
	queue<int> Queue;
	Queue.push(start);
	visited[start] = true;

	while (!Queue.empty()) {
		int curr = Queue.front();
		Queue.pop();

		for (long unsigned int i = 0; i < vc[curr].size(); i++) {
			int next = vc[curr][i];

			if (!visited[next]) {
				parent[next] = curr;
				Queue.push(next);
				visited[next] = true;
			}
		}
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		vc[a].push_back(b);
		vc[b].push_back(a);
	}

	solution(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
}
