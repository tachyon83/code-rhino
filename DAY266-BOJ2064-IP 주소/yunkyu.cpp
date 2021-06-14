// 틀림

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int arr[1001][4];

int main() {

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d.%d.%d.%d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
	}

	int n = 0;
	for (int i = 0; i < 4; i++) {
		int t = arr[0][i];
		for (int j = 1; j < N; j++) {
			if (arr[j][i] != t) {
				n = i;
				break;
			}
		}
	}

	int ind;
	bool check = false;
	for (int i = 7; i >= 0; i--) {
		int bit = arr[0][n] & (1 << i);
		for (int j = 1; j < N; j++) {
			if (bit != (arr[j][n] & (1 << i))) {
				ind = i;
				check = true;
				break;
			}
		}
		if (check) break;
	}

	for (int i = 0; i <= ind; i++) {
		arr[0][n] &= ~(1 << i);
	}

	for (int i = 0; i < 4; i++) {
		if (i > n) arr[0][i] = 0;

		if (i == 3) {
			printf("%d", arr[0][i]);
		}
		else
			printf("%d.", arr[0][i]);
	}

	printf("\n");

	int mask[4] = { 255,255,255,255 };
	for (int i = 0; i <= ind; i++) {
		mask[n] &= ~(1 << i);
	}

	for (int i = 0; i < 4; i++) {
		if (i > n) mask[i] = 0;

		if (i == 3) {
			printf("%d", mask[i]);
		}
		else
			printf("%d.", mask[i]);
	}
	return 0;
}
