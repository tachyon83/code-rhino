#include<iostream>
#include<vector>
using namespace std;
int par[51];
void uni(int a, int b);
int find(int x);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	int num;
	cin >> num;
	vector<vector<int>>party(M, vector<int>());
	for (int i = 0; i <= N; i++) par[i] = i;
	for (int i = 0; i < num; i++) {
		int tmp;
		cin >> tmp;
		par[tmp] = 0;
	}
	for (int i = 0; i < M; i++) {
		cin >> num;
		int prev;
		cin >> prev;
		party[i].push_back(prev);
		for (int j = 1; j < num; j++) {
			int x;
			cin >> x;
			party[i].push_back(x);
			uni(prev, x);
		}
	}
	int sum = 0;
	for (int i = 0; i < M; i++) {
		if (find(party[i][0])) sum++;
	}
	cout << sum;
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	else if (a < b) par[b] = a;
	else {
		par[a] = b;
	}
}

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}
