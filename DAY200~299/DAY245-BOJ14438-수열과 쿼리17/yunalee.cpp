#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

//#define INF 987987987987

using namespace std;

int N, M;
vector<int> vc;
vector<int> tree;

int init(int start, int end, int node) {
	if (start == end) {
		return tree[node] = vc[start];
	}

	int mid = (start + end) / 2;

	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

void update(int start, int end, int node, int index, int num) {
	if (index < start || index > end) {
		return;
	}

	if (start == end) {
		tree[node] = num;
		return;
	}

	int mid = (start + end) / 2;

	update(start, mid, 2 * node, index, num);
	update(mid + 1, end, 2 * node + 1, index, num);
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int query(int start, int end, int node, int left, int right) {
	if (left > end || right < start) {
		return INT_MAX;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;

	return min(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vc.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> vc[i];
	}

	tree.resize(4 * (N + 1));

	init(1, N, 1);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, N, 1, b, c);
		}
		else if (a == 2) {
			cout << query(1, N, 1, b, c) << '\n';
		}
	}
}
