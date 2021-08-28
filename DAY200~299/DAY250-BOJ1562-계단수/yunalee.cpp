#include<iostream>

#define MAX 100 + 1
#define Moduler 1000000000
typedef long long ll;
using namespace std;

ll DP[MAX][10][1<<10];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    for (int i = 0; i <= 9; i++) {
        DP[1][i][1 << i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            int a = 1 << j;
            for (int k = 1; k <= 1023; k++) {
                if (j == 0) {
                    DP[i][j][k|a] += DP[i - 1][j + 1][k];
                }
                else if(j == 9){
                    DP[i][j][k | a] += DP[i - 1][j - 1][k];
                }
                else {
                    DP[i][j][k | a] += DP[i - 1][j - 1][k] + DP[i - 1][j + 1][k];
                }

                DP[i][j][k | a] %= Moduler;
            }
        }
    }

    ll sum = 0;
    for (int i = 1; i <= 9; i++) {
        sum += DP[N][i][1023];
    }
    cout << sum % Moduler << '\n';

    return 0;
}
