#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <queue>

using namespace std;
int arr[1001][1001] = { 0, };

void DFS(int N,int M,int v) {
	stack <int> st;
	vector<int> vec;
	int visited[1001] = { 0, };
	st.push(v);
	while (st.top()) {
		int x = st.top();
		if (visited[x] == 0) {
			visited[x] = 1;
			vec.push_back(x);
		}
		else {
			st.pop();
			continue;
		}
		if (vec.size() == N || vec.size()>M) {
			for (int i = 0; i < vec.size(); i++) {
				printf("%d ",vec[i]);
			}
			return;
		}
		st.pop();
		for (int i = N; i > 0; i--) {
			if (!visited[i]&&(arr[x][i])) {
				st.push(i);
			}
		}
	}

}

void BFS(int N, int M, int v) {
	queue <int> q;
	vector<int> vec;
	int visited[1001] = { 0, };
	q.push(v);

	while (!q.empty()) {
		int x = q.front();
		if (visited[x] == 0) {
			visited[x] = 1;
			vec.push_back(x);
		}
		else {
			q.pop();
			continue;
		}

		if (vec.size() == N || vec.size() > M) {
			for (int i = 0; i < vec.size(); i++) {
				printf("%d ", vec[i]);
			}
			return;
		}
		q.pop();
		for (int i = 1; i <= N;i++) {
			if ((!visited[i])&&(arr[x][i])) {
				q.push(i);
			}
		}
	}

}
int main() {
	//dfs는 스택으로 bfs는 큐로 구현해보자!
	int N, M, first;
	int x, y;
	stack <int> st;
	cin >> N >> M >> first;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1;
	}
	DFS(N,M, first);
	printf("\n");
	BFS(N,M,first);

}