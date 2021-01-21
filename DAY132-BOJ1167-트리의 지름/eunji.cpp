#include<iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> edges[100001];
bool visited[100001] = { 0, };
int nummax = 0;
int num = 0;
void doDFS(int x, int depth);

int main() {
	int V;
	cin >> V;

	for (int i = 0; i < V; i++) {
		int start;
		cin >> start;
		int end, val;
		while (1) {
			cin >> end;
			if (end == -1) break;
			cin >> val;
			edges[start].push_back({ end, val });
		}
	}
	doDFS(1, 0);
	doDFS(num, 0);
	cout << nummax;
}

void doDFS(int x, int depth) {
	visited[x] = true;

	for (int i = 0; i < edges[x].size(); i++) {
		int end = edges[x][i].first;
		int val = edges[x][i].second;
		if (!visited[end]) {
			doDFS(end, depth + val);

		}
	}
	if (depth > nummax) {
		nummax = depth;
		num = x;
	}
	visited[x] = false;
}
