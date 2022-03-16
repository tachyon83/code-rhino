#include <iostream>
using namespace std;
bool prime[1001] = { 0 };

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int num = 1;
    for (int i = 2; i <=n; i++)
    {
        if (prime[i] == 1)
            continue;
        int j = 1;
        bool fEnd = 0;
        while (i*j<=n)
        {
            if (prime[i * j] == 0)
            {
                if (num == k)
                {
                    cout << i * j << '\n';
                    fEnd = 1;
                    break;
                }
                num++;
                prime[i * j] = 1;
            }
            j++;
        }
        if (fEnd)
            break;
    }

    return 0;
}