#include <iostream>
using namespace std;
#define MAXNUM (123456*2)+1
bool isNotPrime[MAXNUM] = { 0 };

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    isNotPrime[1] = 1;
    for (int i = 2; i < MAXNUM; i++)
    {
        if (isNotPrime[i] == 1)
            continue;
        int j = 2;
        while (i*j< MAXNUM)
        {
            isNotPrime[i * j] = 1;
            j++;
        }
    }
    int n; cin >> n;
    while (n!=0)
    {
        int ans = 0;
        for (int i = n+1; i <= 2*n; i++)
        {
            if (isNotPrime[i] == 0)
                ans++;
        }
        cout << ans << '\n';
        cin >> n;
    }

    return 0;
}