#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <bitset>
using namespace std;

bitset<1 << 25> bit;

int main() {
	int n;

	while (scanf("%d", &n) != EOF) { // 입력이 없을때까지
		if (!bit[n]) { // bitset에 없는 정수일경우
			bit[n] = true; // bitset에 정수 저장
			printf("%d ", n);
		}
	}
}
