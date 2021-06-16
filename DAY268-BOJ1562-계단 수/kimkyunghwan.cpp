#include <iostream>
#include <cmath>
#define mod 1000000000
 
using namespace std;
 
long long dp[101][10][1024];
int N;
 
int main() {
    cin >> N;
    
    for(int i = 1; i <= 9; i++)
        dp[1][i][1 << i] = 1;
        
    for(int i = 2; i <= N; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 1; k < 1024; k++){
                if(j == 0){
                    dp[i][0][k | 1 << 0] += dp[i - 1][1][k] % mod;    
                }
                else if(j == 9){
                    dp[i][9][k | 1 << 9] += dp[i - 1][8][k] % mod;
                }else{
                    dp[i][j][k | 1 << j] += dp[i - 1][j - 1][k] % mod;
                    dp[i][j][k | 1 << j] += dp[i - 1][j + 1][k] % mod;
                }
            }
        }
    }
    
    long long answer = 0;
    for(int k = 0; k < 10; k++){
        answer = (answer + dp[N][k][1023]) % mod;
    }
    
    cout << answer << endl;
    return 0;
}
