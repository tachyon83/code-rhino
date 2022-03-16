#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	long long int n, k, q;
	scanf("%lld %lld %lld", &n, &k, &q);
	for (int i = 0; i < q; i++) {
		long long int x, y;
		long long int cnt = 0;
		scanf("%lld %lld", &x, &y);
		if (k == 1) { // k == 1 일시 일렬로 연결돼있기때문에 노드 번호가 depth
			printf("%lld\n", abs(y - x));
		}
		else { 
			while (y != x) { // 같은 부모가 될때까지
				// 더 높은 레벨의 노드의 부모노드를 얻는다
				if (y > x) {
					y = (y - 2) / k + 1;
				}
				else {
					x = (x - 2) / k + 1;
				}
				cnt++; // 거리 + 1
			}

			printf("%lld\n", cnt);
		}
	}


	return 0;
}
