#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#define MAX 100000
using namespace std;

int arr[MAX + 1];
vector<int> tree;

int init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;

	return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end)); // 왼쪽과 오른쪽 구간에 더 작은 값으로 정해준다
}

int update(int node, int start, int end, int index, int value) {
	if (index < start || index > end) // 구간 안에 인덱스가 없다면
		return tree[node];

	if (start == end) { // index라면
		return tree[node] = value;
	}

	int mid = (start + end) / 2;

	return tree[node] = min(update(node * 2, start, mid, index, value), update(node * 2 + 1, mid + 1, end, index, value)); 
}

int query(int node, int start, int end, int left, int right) {
	if (right < start || left > end) // 구간 밖이기 때문에 가장 큰 값 반환
		return INT_MAX;
	if (left <= start && end <= right) // 구간 안이라면 반환
		return tree[node];

	int mid = (start + end) / 2;

	return  min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right)); // 더 작은값을 반환
}

int main() {
	int n, m, i;
	scanf("%d", &n);
	int h = (int)ceil(log2(n));
	int tsize = 1 << (h + 1);
	tree.resize(tsize); // 트리 사이즈 정함
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	init(1, 1, n);
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) { // 갱신
			update(1, 1, n, b, c);
		}
		else { // 구간에서 가장 작은값 
			printf("%d\n", query(1, 1, n, b, c));
		}
	}
	return 0;
}
