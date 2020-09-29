#include <iostream>
#define endl '\n'
using namespace std;
const int nMax = 10000;
int i, n, arr[nMax], s, e, ans;
unsigned int m, t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int nn = n;
    while (nn--)
        cin >> arr[i++];
    t = arr[s];
    while (s < n && e < n)
    {
        while (t < m && e < n)
        {
            t += arr[++e];
        }
        if (t == m)
            ans++;
        t -= arr[s++];
    }
    cout << ans << endl;
    return 0;
}
