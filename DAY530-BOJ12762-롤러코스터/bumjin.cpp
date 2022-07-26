#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n, i, j, M = 0, I[1000], D[1000], a[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", a + i);
	fill(I, I + n, 1);
	fill(D, D + n, 1);
	for (i = 0; i < n; i++) 
		for (j = 0; j < i; j++)
			if (a[i] < a[j]) I[i] = max(I[i], I[j] + 1);
	for (i = n - 1; i >= 0; i--)
		for (j = n - 1; j > i; j--)
			if (a[i] < a[j]) D[i] = max(D[i], D[j] + 1);
	for (i = 0; i < n; i++) M = max(I[i] + D[i] - 1, M);
	printf("%d", M);
}
