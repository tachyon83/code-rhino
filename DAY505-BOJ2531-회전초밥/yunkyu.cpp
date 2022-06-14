#include <iostream>
#include <vector>
using namespace std;

int check[3001];
vector<int> dish;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, d, k, c;
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		dish.push_back(a);
	}

	int cnt = 0, maxCnt = 0;

	// 처음 k개의 초밥을 먹었을 때 
	for (int i = 0; i < k; i++) {
		if (!check[dish[i]]) cnt++; // 처음먹는 초밥이면
		check[dish[i]]++;
	}

	for (int i = 1; i < N; i++) {
		if (maxCnt <= cnt) { // 가장 많은 종류의 초밥을 먹었을 때
			if (!check[c]) maxCnt = cnt + 1; // 쿠폰 제공 초밥을 먹지 않았다면 추가
			else maxCnt = cnt;
		}
		// 가장 앞에서 먹었던 초밥 제외
		// 제외한 초밥이 k개에 해당되지 않는다면 개수를 뺀다
		check[dish[i - 1]]--; 
		if (!check[dish[i - 1]]) cnt--; 
		// 마지막 초밥 다음 초밥을 먹는다
		// 처음 먹은 초밥이면 개수를 더한다
		if (check[dish[(i + k - 1) % N]] == 0) cnt++; 
		check[dish[(i + k - 1) % N]]++;
	}

	cout << maxCnt;
	return 0;
}
