#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n); // 오름차순 정렬

	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > sum + 1) { // i번째 추의 무게가 누적합보다 2 이상 크다면 누적합 + 1 의 무게를 측정불가능
			break;
		}
		sum += arr[i]; // 누적합
	}

	printf("%d", sum + 1);
	return 0;
}
