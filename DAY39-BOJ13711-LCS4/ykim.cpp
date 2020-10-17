#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_N 100000
using namespace std;
int a[MAX_N + 1], b[MAX_N + 1], x, n, r;
vector<int> vt;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[x] = i;
    }
    for (int i = 1; i <= n; i++) 
        scanf("%d", &b[i]);
    vt.push_back(-MAX_N - 100);
    for (int i = 1; i <= n; i++) {
        if (vt.back() < a[b[i]]) {
            vt.push_back(a[b[i]]);
            r++;
        }
        else {
            auto it = lower_bound(vt.begin(), vt.end(), a[b[i]]);
            *it = a[b[i]];
        }
    }
    printf("%d\n", r);
    return 0;
}
