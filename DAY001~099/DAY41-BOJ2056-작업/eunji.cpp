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
	priority_queue <pair<int,int>> q;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		cin >> indegree[i];
		for (int j = 0; j < indegree[i]; j++) {
			int x;
			cin >> x;
			connect[x].push_back(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push({-cost[i],i });
		}
	}
	int totalcost = 0;
	while (!q.empty()) {
		int next = q.top().second;
		int nextcost = -(q.top().first);
		//cout << tmp << endl;
		if (totalcost < nextcost) totalcost = nextcost;
		q.pop();
		for (int i = 0; i < connect[next].size(); i++) {
			if (--indegree[connect[next][i]] == 0) {
				q.push({ -(cost[connect[next][i]]+nextcost),connect[next][i] });
			}
		}
	}
	cout << totalcost;
}
