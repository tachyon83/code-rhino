#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int D, N, ans;
	vector<int> oven, pizza;
	cin >> D >> N;

	oven.resize(D + 1);
	pizza.resize(N + 1);

	for (int i = 1; i <= D; i++) {
		cin >> oven[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> pizza[i];
	}

	int prev = oven[1];
	for (int i = 2; i <= D; i++)
	{
		if (prev < oven[i])
			oven[i] = prev;
		else
			prev = oven[i];
	}

	int pIdx = 1;
	for (ans = D; ans > 0 && pIdx <= N; ans--) {
		if (pizza[pIdx] <= oven[ans]) {
			pIdx++;
		}
	}

	if (ans < 0 || pIdx <= N) {
		cout << 0;
	}
	else {
		cout << ans + 1;
	}
}