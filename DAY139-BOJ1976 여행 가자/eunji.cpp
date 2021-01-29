#include<iostream>
#include <vector>
int find(int x);
void uni(int x, int y);
using namespace std;
int par[201];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		par[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp) uni(i, j);
		}
	}
	int prev;
	cin >> prev;
	int b = find(prev);
	for (int i = 1; i < M; i++) {
		int tmp;
		cin >> tmp;
		if (b != find(tmp)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;

}

int find(int x) {
	if (x == par[x]) return x;

	return par[x] = find(par[x]);;
}

void uni(int x, int y) {

	x = find(x);
	y = find(y);
	if (x != y) par[x] = y;
	return;
}
