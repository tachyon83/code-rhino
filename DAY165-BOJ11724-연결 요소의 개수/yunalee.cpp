#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
bool visited[1001];
vector<int> vc[500000];
int answer = 0;

void solution(int start) {
	queue<int> Queue;
	Queue.push(start);
	visited[start] = true;
	
	while (!Queue.empty()) {
		int curr = Queue.front();
		Queue.pop();

		for (int i = 0; i < vc[curr].size(); i++) {
			int next = vc[curr][i];

			if (!visited[next]) {
				visited[next] = true;
				Queue.push(next);
			}
		}
	}

	answer++;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;
	
	int tmp_a, tmp_b;
	for (int i = 0; i < M; i++) {
		cin >> tmp_a >> tmp_b;
		vc[tmp_a].push_back(tmp_b);
		vc[tmp_b].push_back(tmp_a);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			solution(i);
		}
	}

	cout << answer << '\n';

	return 0;
}
