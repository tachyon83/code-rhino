#include <iostream>
#include <queue>
using namespace std;
int doPrim(vector<vector<pair<int,int>>> path,int total);
vector<pair<int, int>> path[200000];
int main() {
	int m, n;
	cin >> m >> n;
	do {
		vector<vector<pair<int, int>>> path(n, vector<pair<int, int>>());
		int total = 0;
		for (int i = 0; i < n; i++) {
			int x, y, val;
			cin >> x >> y >> val;
			total += val;
			path[x].push_back({ val,y });
			path[y].push_back({ val,x });
		}
		cout << doPrim(path,total)<<endl;
		cin >> m >> n;
	} while (m != 0 && n != 0);
	return 0;
}

int doPrim(vector<vector<pair<int, int>>> path,int total) {
	int sum = 0;
	bool visited[20000] = { false, };
	priority_queue <pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for (int i = 0; i < path[0].size(); i++) {
		pq.push(path[0][i]);
	}
	visited[0] = true;
	while (!pq.empty()) {
		int num = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		if (visited[num]) continue;
		visited[num] = true;
		sum += val;
		for (int i = 0; i < path[num].size(); i++) {
			pq.push(path[num][i]);
		}
	}
	return total-sum;
}
