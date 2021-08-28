#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

void func(int n, int start, int mid, int end) {
	if (n == 1) {
		printf("%d %d\n", start, end);
	}
	else {
		func(n - 1, start, end, mid);
		printf("%d %d\n", start, end);
		func(n - 1, mid, start, end);
	}
}

int main() {
	int i;
	int n;
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	func(n, 1, 2, 3);

	return 0;
}
