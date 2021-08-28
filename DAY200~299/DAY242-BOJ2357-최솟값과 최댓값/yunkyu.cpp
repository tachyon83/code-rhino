#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

vector<pair<int,int>> tree;
int arr[100001];

pair<int,int> init(int node ,int start ,int end) {
	if (start == end) { // 리프 노드일시
		tree[node].first = tree[node].second = arr[start]; // 최솟값 최댓값 저장
		return tree[node];
	}

	int mid = (start + end) / 2; 

	// left child와 right child로 이동
	pair<int, int> l = init(node * 2, start, mid);
	pair<int, int> r = init(node * 2 + 1, mid + 1, end);
	
	// 현재 범위의 최솟값과 최댓값을 자식 노드에서부터 구해준다
	tree[node].first = min(l.first, r.first);
	tree[node].second = max(l.second, r.second);
	return tree[node];

}

pair<int, int> find(int node, int start, int end, int left, int right) {
	if (right < start || left > end) { // 범위를 넘어섰을때
		return {INT_MAX ,0 };
	}
	if (left <= start && end <= right) { // 범위안에 포함될때
		return tree[node];
	}

	int mid = (start + end) / 2;
	// left child 와 right child 에서의 범위안의 최댓값과 최솟값을 구한다
	pair<int, int> l = find(node * 2, start, mid, left, right);
	pair<int, int> r = find(node * 2 + 1, mid + 1, end, left, right);

	return { min(l.first,r.first) , max(l.second, r.second) };
}

int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);
	// 트리 사이즈 구함
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);
	for (i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	init(1, 1, N);

	for (i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		pair<int, int> ans = find(1, 1, N, a, b);
		printf("%d %d\n", ans.first, ans.second);
	}

	return 0;
}
