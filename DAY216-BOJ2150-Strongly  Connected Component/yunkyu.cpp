#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> graph[10001];
vector<int> rGraph[10001];
stack<int> st;
int visited[10001];
vector<int> scc[10001];

void DFS(int curr) { 
	visited[curr] = true;
	int i;

	for (i = 0; i < graph[curr].size(); i++) {
		int next = graph[curr][i];
		if (!visited[next]) {
			DFS(next);
		}
	}

	st.push(curr); // 노드를 순서대로 저장하기 위함
}

void reverse_DFS(int curr,int cnt) {
	visited[curr] = true;
	int i;
	scc[cnt].push_back(curr);

	for (i = 0; i < rGraph[curr].size(); i++) {
		int next = rGraph[curr][i];
		if (!visited[next]) {
			reverse_DFS(next,cnt);
		}
	}
}

int main() {
	int V, E, i;
	scanf("%d %d", &V, &E);
	for (i = 0; i < E; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		graph[A].push_back(B);
		rGraph[B].push_back(A); //코사라주 알고리즘을 위해 역방향 그래프도 선언
	}

	for (i = 1; i <= V; i++) {
		if(!visited[i])
			DFS(i);
	}
	memset(visited, false, sizeof(visited));

	int cnt = 0;
	vector<pair<int, int>> v; //scc의 첫번째원소에 대해 정렬하기 위해 사용
	while (!st.empty()) { // 처음 DFS에서 방문했던 원소들의 마지막 순서부터 DFS
		int ver = st.top();
		st.pop();
		if (!visited[ver]) { 
			reverse_DFS(ver,cnt);
			sort(scc[cnt].begin(), scc[cnt].end()); // scc 오름차순 정렬
			v.push_back({ scc[cnt][0],cnt });
			cnt++; // 한번의 DFS에 scc한개
		}
	}

	sort(v.begin(), v.end()); // 첫번째 원소의 크기로 정렬
	printf("%d\n", cnt);
	for (i = 0; i < v.size(); i++) {
		int index = v[i].second;
		for (int j = 0; j < scc[index].size(); j++) {
			printf("%d ", scc[index][j]);
		}
		printf("-1\n");
	}
	return 0;
}
