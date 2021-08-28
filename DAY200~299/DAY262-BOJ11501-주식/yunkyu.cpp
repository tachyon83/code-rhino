#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

long long maxProfit(vector<int> &v) {
	long long profit = 0;
	int i;

	long long mx = 0;
	for (i = v.size() - 1; i >= 0; i--) { 
		if (v[i] > mx) // 더 클 경우 갱신 
			mx = v[i];
		else
			profit += mx - v[i]; // 매수 이후로 가장 큰 주가에서 매도
	}
	return profit;
}

int main() {
	int T, n, i, j;
	scanf("%d", &T);
	
	int price;

	for (i = 0; i < T; i++) {
		scanf("%d", &n);
		vector<int> v;
		for (j = 0; j < n; j++) {
			scanf("%d", &price);
			v.push_back(price);
		}
		printf("%lld\n",maxProfit(v));
	}

	return 0;
}
