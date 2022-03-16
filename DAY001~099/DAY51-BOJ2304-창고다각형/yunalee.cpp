#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int arr[1002] = { 0, };
	int maxH = 0;
	int maxL = 0;
	int startIdx = 1002, endIdx = -1;
	for (int i = 0; i < N; i++) {
		int L, H;
		cin >> L >> H;
		arr[L] = H;
		if (maxH < H) {
			maxH = H;
			maxL = L;
		}

		if (startIdx > L) {
			startIdx = L;
		}
		if (endIdx < L) {
			endIdx = L;
		}
	}

	int answer = maxH;
	for (int i = maxL - 1; i >= startIdx; i--) {
		int m = *max_element(arr, arr + i);
		answer = answer + max(arr[i], m);
	}
	for (int i = maxL + 1; i <= endIdx; i++) {
		int m = *max_element(arr + i, arr + endIdx + 1);
		answer = answer + max(arr[i], m);
	}

	cout << answer << '\n';

	return 0;
}
