#include <stdio.h>

int main() {
//가로를 기준으로 길이1 또는 길이 2가 올수있다.
	// 길이 1은 한가지 종류(1*2), 길이 2는 (2*1붙인거, 2*2한개짜리) 두가지
		//dp유형인거같다.
	int i,x;
	int arr[1001] = { 0, };
	arr[1] = 1;
	arr[2] = 3;
	scanf("%d", &x);
	for (i = 3; i <= x; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2] * 2)%10007;
	}
	printf("%d", arr[x]);

}
