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
	int count = 0;
	int visited[1001] = { 0, };
	st.push(v);
	
	while (!st.empty()) {
		int x = st.top();
		st.pop();
		if (visited[x]) {
			continue;
		}
		visited[x] = 1;
		for (int i = N; i >0; i--) {
			if (!visited[i]&&(arr[x][i])) {
				st.push(i);
			}
		}
		printf("%d ", x);
		if (++count == N) {
			return;
		}
	}

}

void BFS(int N, int M, int v) {
	queue <int> q;
	int count = 0;
	int visited[1001] = { 0, };
	q.push(v);
	visited[v] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= N;i++) {
			if ((!visited[i])&&(arr[x][i])) {
				q.push(i);
				visited[i] = 1;
			}
		}
		printf("%d ", x);
		if (++count == N) {
			return;
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
