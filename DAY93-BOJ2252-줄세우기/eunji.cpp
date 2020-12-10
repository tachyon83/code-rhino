#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void topologySort(int indegree[], vector<int> order[], int N);

int main() {
	int N, M;
	cin >> N >> M;
	int indegree[32001] = { 0, };
	vector <int> order[32001];
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		order[A].push_back(B);
		indegree[B]++;
	}
	topologySort(indegree, order, N);
	return 0;
}
void topologySort(int indegree[], vector<int> order[], int N) {
	queue <int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int tmp = q.front();
		printf("%d ", tmp);
		q.pop();
		for (int i = 0; i < order[tmp].size(); i++) {
			if (--indegree[order[tmp][i]] == 0) {
				q.push(order[tmp][i]);
			}
		}
	}
	return;
}

