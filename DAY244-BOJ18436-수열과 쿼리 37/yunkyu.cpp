#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 100000
using namespace std;

int arr[MAX + 1];
vector<int> tree;

int init(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start] % 2; // 홀수면 1 짝수면 0
		return tree[node];
	}

	int mid = (start + end) / 2;

	// 왼쪽 서브 트리와 오른쪽 서브 트리로 이동
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

int update(int node, int start, int end, int i, int x) {
	if (start > i || end < i) return tree[node]; // index가 범위안에 없다면 종료
	if (start == end) // i 번째 인덱스라면 갱신
		return tree[node] = x;

	int mid = (start + end) / 2;

	return tree[node] = update(node * 2, start, mid, i, x) + update(node * 2 + 1, mid + 1, end, i, x);
}

int query(int node, int start, int end , int left , int right) {
	if (start > right || end < left) // 범위의 바깥이면 0더해줌
		return 0;
	if (left <= start && end <= right) { // 범위에 포함된다면 더해준다
		return tree[node];
	}

	int mid = (start + end) / 2;

	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	int n, m, i;
	scanf("%d", &n);
	int h = (int)ceil(log2(n)); 
	int tsize = (1 << (h + 1));	// tree 사이즈
	tree.resize(tsize);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	init(1, 1, n); // 트리 생성

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) { // 갱신
			update(1, 1, n, b, c % 2);
		}
		else if (a == 2) { // 짝수의 수
			printf("%d\n", c - b + 1 - query(1, 1, n, b, c)); // 구간 내에서 홀수의 개수를 뺴면 짝수
		}
		else { // 홀수의 수
			printf("%d\n", query(1, 1, n, b, c));
		}
	}

	return 0;
}
