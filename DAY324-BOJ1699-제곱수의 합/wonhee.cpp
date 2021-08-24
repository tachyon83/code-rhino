#include <iostream>
using namespace std;
int dp[100001] = { 0 };

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    for (int i = 1; i <= 100000; i++)
    {
        int j = 1;
        while (j*j <= i)
        {
            if (dp[i] == 0)
                dp[i] = dp[i - j * j] + 1;
            else
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            j++;
        }
    }
    cout << dp[N] << '\n';
    return 0;
}