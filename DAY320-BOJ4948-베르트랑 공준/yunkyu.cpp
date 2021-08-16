#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 123456 * 2
using namespace std;

int arr[MAX + 1];

int main() {
	int n;

	// 에라토스테네스의 체 이용
	for (int i = 2; i <= MAX; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= MAX; i++) {
		if (arr[i] == 0)continue;
		for (int j = i + i; j <= MAX; j += i) {
			arr[j] = 0; // i 자기 자신을 제외한 i의 배수를 0으로
		}
	}

	//남은 수가 소수이다

	while (1) {
		scanf("%d", &n);
		if (n == 0)break;
		
		int cnt = 0;
		for (int i = n + 1; i <= n * 2; i++) {
			if (arr[i] != 0) cnt++; // 소수의 개수를 구한다
		}

		printf("%d\n", cnt);
	}
	return 0;
}
