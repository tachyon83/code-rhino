#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int n,ans;
int col[16];
bool check(int x) {
	for (int i = 0; i < x; i++) {
		if (col[x] == col[i] || abs(col[x] - col[i]) == abs(x - i)) {
			return false;
		}
	}
	return true;
}
void go(int x) {
	if (x == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		col[x] = i;
		if (check(x)) {
			go(x + 1);
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	go(0);
	cout << ans;
}

