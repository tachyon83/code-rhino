#include<iostream>
#include<string>
#include<cstring>

#define MAX 1001
using namespace std;

char A[MAX], B[MAX];
int DP[MAX][MAX];

void Solution()
{
    int aLen = strlen(A);
    int bLen = strlen(B);

    for (int i = 1; i <= aLen; i++)
    {
        for (int j = 1; j <= bLen; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                DP[i][j] = DP[i - 1][j] > DP[i][j - 1] ? DP[i - 1][j] : DP[i][j - 1];
            }

        }
    }
    cout << DP[aLen][bLen] << '\n';
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> B;
    Solution();

    return 0;
}
