#include<cstdio>
const int MXN = 1e6;
int n;
double p[MXN + 6] = { 1 }, a[MXN + 6], r;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= i + 6; j++) p[j] += p[i] / 6, a[j] += (a[i] / p[i] + 1)*p[i] / 6;
    for (int i = n; i < n + 6; i++) r += a[i];
    printf("%.9lf", r);
    return 0;
}
