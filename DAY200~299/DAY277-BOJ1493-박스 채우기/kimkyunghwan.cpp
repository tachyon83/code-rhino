#include <cstdio>
#include <math.h>
int L, W, H,n,cube[21];
bool f = 1;
int func(int l, int w, int h) {
	if (!l || !w || !h)return 0;
	int k = l;
	if (w < k)k = w;
	if (h < k)k = h;

	int t = log2(k);
	do {
		if (!cube[t])continue;
		cube[t]--;
		int T = pow(2, t);
		return func(l - T, T, h) + func(l, w - T, h) + func(T, T, h - T)+1;
	} while (--t >= 0);
	f = 0;
	return -1;
}
int main() {
	scanf("%d%d%d%d", &L, &W, &H,&n);
	for (int i = 0,a,b; i < n; i++) {
		scanf("%d%d", &a, &b);
		cube[a] = b;
	}
	int ans = func(L, W, H);
	if (f)
		printf("%d", ans);
	else printf("-1");
	return 0;
}
