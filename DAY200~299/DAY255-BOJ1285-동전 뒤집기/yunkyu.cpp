#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int coin[21];
int ans = 20 * 20 + 1;

void flip(int ind, int n) {
	if (ind == n) { // n번째 줄까지 뒤집었다면
		int i, j;
		int sum = 0;
		for (i = 0; i < n; i++) {
			int t = 0;
			for (j = 0; j < n; j++) {
				if ((coin[j] & (1 << i)) != 0) { // 비트가 1이라면(뒷면이라면) 
					t++;
				}
			}
			sum += min(n - t, t); // 1과 0중 더 작은 개수를 앞면으로 정해야한다
		}
		ans = min(ans, sum);

		return;
	}

	flip(ind + 1, n);
	coin[ind] = ~coin[ind]; // ind번째 줄을 뒤집는다
	flip(ind + 1, n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (j = 0; j < n; j++) {
			if (s[j] == 'T') { // 뒷면일 경우 비트를 1로
				coin[i] |= (1 << j);
			}
		}
	}

	flip(0, n);

	cout << ans;

	return 0;
}
