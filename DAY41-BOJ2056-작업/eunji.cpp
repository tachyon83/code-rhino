#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//최소시간을 찾아야합니다. 모든 작업을 해야하므로, 적어도 시간이 제일 많이 걸리는 길보다 더 커야합니다. 그래서 우선순위를 쓰게되었습니다. 
int main() {
	int N;
	cin >> N;
	vector<int> indegree(N+1, 0);
	vector<int> cost(N+1, 0);
	vector <vector<int>> connect(N+1,vector<int>());
	priority_queue <int> q;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		cin >> indegree[i];
		for (int j = 0; j < indegree[i]; j++) {
			int x;
			cin >> x;
			connect[x].push_back(i);
		}
	}

	q.push(1);
	while (!q.empty()) {
		int tmp = q.front();
		cout << tmp << endl;
		q.pop();
		for (int i = 0; i < connect[tmp].size(); i++) {
			if (--indegree[connect[tmp][i]] == 0) {
				q.push(connect[tmp][i]);
			}
		}
	}
}
