#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int arr[10001];

int main() {
	int t, n, i;
	scanf("%d", &t);
	while (t > 0) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + n); // 오름차순 정렬
		
		vector<int> v;
		// 2칸씩 떨어진 통나무로 정렬할시 가장 작은 높이차이
		if (n % 2 == 0) { // 짝수 일시
			for (i = 0; i < n; i+=2) { 
				v.push_back(arr[i]);
			}
			for (i = n - 1; i > 0; i -= 2) {
				v.push_back(arr[i]);
			}
		}
		else { // 홀수 일시
			for (i = 0; i < n; i += 2) {
				v.push_back(arr[i]);
			}
			for (i = n - 2; i > 0; i -= 2) {
				v.push_back(arr[i]);
			}
		}

		int ans = abs(v[0] - v[n - 1]); // 처음과 끝의 차이
		for (i = 0; i < n - 1; i++) { // 정렬된 나무들의 높이 차이를 구한다
			ans = max(ans, abs(v[i] - v[i + 1])); // 최댓값 갱신
		}
		printf("%d\n", ans);
		t--;
	}
	return 0;
}
